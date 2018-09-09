/* Franco Marcoccia
COP3330 Section 6
Homework 4
This is a cpp file which contains the definitions of the Grid class member functions
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "grid.h" 
using namespace std;

Grid::Grid()																						// default constructor
{
	columncurrent = 1;
	rowcurrent = 1;
	grid[0][0] = '>';
	path = 'Y';
}

Grid::Grid(int r, int c)																			// 2 parameter contructor
{
	srand((unsigned int)time(0));
	int wall, box, box2, ndirection, pr, pc;
	char direction;
	if (r<3)																						// error checking
		rowcurrent = 3;
	else if (r>40)
		rowcurrent = 40;
	else
		rowcurrent = r;

	if (c<3)
		columncurrent = 3;
	else if (c>40)
		columncurrent = 40;
	else
		columncurrent = c;

	for (int i = 0; i < rowcurrent; i++)																			// for loop to fill grid with walls and empty spaces
	{
		for (int j = 0; j < columncurrent; j++)
		{
			if (i == 0 || i == rowcurrent - 1)
				grid[i][j] = '#';
			else if (j == columncurrent - 1 || j == 0)
				grid[i][j] = '#';
			else
				grid[i][j] = '.';
		}
	}

	wall = rand() % 4 + 1;																			// random number generation to pick a wall and certain array
	box = rand() % (columncurrent - 2) + 1;
	box2 = rand() % (rowcurrent - 2) + 1;

	if (wall == 1)
		grid[0][box] = '%';
	else if (wall == 2)
		grid[rowcurrent - 1][box] = '%';
	else if (wall == 3)
		grid[box2][0] = '%';
	else if (wall == 4)
		grid[box2][columncurrent - 1] = '%';

	ndirection = rand() % 4;																		// rand for direction of mover
	if (ndirection == 0)
		direction = '^';
	else if (ndirection == 1)
		direction = '<';
	else if (ndirection == 2)
		direction = 'v';
	else if (ndirection == 3)
		direction = '>';

	pr = rand() % (rowcurrent - 2) + 1;
	pc = rand() % (columncurrent - 2) + 1;
	grid[pr][pc] = direction;

	path = 'Y';																				// sets path to on

}

Grid::Grid(int r, int c, int mr, int mc, int d)													
{
	if (r<1)
		rowcurrent = 1;
	else if (r>40)
		rowcurrent = 40;
	else
		rowcurrent = r;

	if (c<1)
		columncurrent = 1;
	else if (c>40)
		columncurrent = 40;
	else
		columncurrent = c;

	for (int i = 0; i < rowcurrent; i++)																	// fills grid to empty spaces only
	{
		for (int j = 0; j < columncurrent; j++)
		{
			grid[i][j] = '.';
		}
	}

	if (mr < 0 && mc < 0)																			// various if statements to determine location of mover and direction
	{
		if (d == Grid::NORTH)
		{
		grid[0][0] = '^';
		previousdirection = '^';
		}
		else if (d == Grid::WEST)
		{
			grid[0][0] = '<';
			previousdirection = '<';
		}
		else if (d == Grid::SOUTH)
		{
			grid[0][0] = 'v';
			previousdirection = 'v';
		}
		else if (d == Grid::EAST)
		{
			grid[0][0] = '>';
			previousdirection = '>';
		}
		
	}
	else if (mr > rowcurrent - 1 && mc > columncurrent - 1)
	{
		if (d == Grid::NORTH)
		{
			grid[rowcurrent - 1][columncurrent - 1] = '^';
			previousdirection = '^';
		}
		else if (d == Grid::WEST)
		{
			grid[rowcurrent - 1][columncurrent - 1] = '<';
			previousdirection = '<';
		}
		else if (d == Grid::SOUTH)
		{
			grid[rowcurrent - 1][columncurrent - 1] = 'v';
			previousdirection = 'v';
		}
		else if (d == Grid::EAST)
		{
			grid[rowcurrent - 1][columncurrent - 1] = '>';
			previousdirection = '>';
		}
		
		
	}
	else if (mr<0 && mc>columncurrent - 1)
	{
		if (d == Grid::NORTH)
		{
			grid[0][columncurrent - 1] = '^';
			previousdirection = '^';
		}
		else if (d == Grid::WEST)
		{
			grid[0][columncurrent - 1] = '<';
			previousdirection = '<';
		}
		else if (d == Grid::SOUTH)
		{
			grid[0][columncurrent - 1] = 'v';
			previousdirection = 'v';
		}
		if (d == Grid::EAST)
		{
			grid[0][columncurrent - 1] = '>';
			previousdirection = '>';
		}
	}
	else if (mr > rowcurrent - 1 && mc < 0)
	{
		if (d == Grid::NORTH)
		{
			grid[rowcurrent - 1][0] = '^';
			previousdirection = '^';
		}
		else if (d == Grid::WEST)
		{
			grid[rowcurrent - 1][0] = '<';
			previousdirection = '<';
		}
		else if (d == Grid::SOUTH)
		{
			grid[rowcurrent - 1][0] = 'v';
			previousdirection = 'v';
		}
		else if (d == Grid::EAST)
		{
			grid[rowcurrent - 1][0] = '>';
			previousdirection = '>';
		}
	}
	else if (mr >= 0 && mr <= rowcurrent - 1 && mc < 0)
	{
		if (d == Grid::NORTH)
		{
			grid[mr][0] = '^';
			previousdirection = '^';
		}
		else if (d == Grid::WEST)
		{
			grid[mr][0] = '<';
			previousdirection = '<';
		}
		else if (d == Grid::SOUTH)
		{
			grid[mr][0] = 'v';
			previousdirection = 'v';
		}
		else if (d == Grid::EAST)
		{
			grid[mr][0] = '>';
			previousdirection = '>';
		}
	}
	else if (mr >= 0 && mr <= rowcurrent - 1 && mc > columncurrent - 1)
	{
		if (d == Grid::NORTH)
		{
			grid[mr][columncurrent - 1] = '^';
			previousdirection = '^';
		}
		else if (d == Grid::WEST)
		{
			grid[mr][columncurrent - 1] = '<';
			previousdirection = '<';
		}
		else if (d == Grid::SOUTH)
		{
			grid[mr][columncurrent - 1] = 'v';
			previousdirection = 'v';
		}
		else if (d == Grid::EAST)
		{
			grid[mr][columncurrent - 1] = '>';
			previousdirection = '>';
		}
	}
	else if (mr < 0 && mc >= 0 && mc <= columncurrent - 1)
	{
		if (d == Grid::NORTH)
		{
			grid[0][mc] = '^';
			previousdirection = '^';
		}
		else if (d == Grid::WEST)
		{
			grid[0][mc] = '<';
			previousdirection = '<';
		}
		else if (d == Grid::SOUTH)
		{
			grid[0][mc] = 'v';
			previousdirection = 'v';
		}
		else if (d == Grid::EAST)
		{
			grid[0][mc] = '>';
			previousdirection = '>';
		}
	}
	else if (mr > rowcurrent - 1 && mc >= 0 && mc <= columncurrent - 1)
	{
		if (d == Grid::NORTH)
		{
			grid[rowcurrent - 1][mc] = '^';
			previousdirection = '^';
		}
		else if (d == Grid::WEST)
		{
			grid[rowcurrent - 1][mc] = '<';
			previousdirection = '<';
		}
		else if (d == Grid::SOUTH)
		{
			grid[rowcurrent - 1][mc] = 'v';
			previousdirection = 'v';
		}
		else if (d == Grid::EAST)
		{
			grid[rowcurrent - 1][mc] = '>';
			previousdirection = '>';
		}
	}
	else if (mr >= 0 && mr <= rowcurrent - 1 && mc >= 0 && mc <= columncurrent - 1)
	{
		if (d == Grid::NORTH)
		{
			grid[mr][mc] = '^';
			previousdirection = '^';
		}
		else if (d == Grid::WEST)
		{
			grid[mr][mc] = '<';
			previousdirection = '<';
		}
		else if (d == Grid::SOUTH)
		{
			grid[mr][mc] = 'v';
			previousdirection = 'v';
		}
		else if (d == Grid::EAST)
		{
			grid[mr][mc] = '>';
			previousdirection = '>';
		}
	}
		path = 'Y';
}

void Grid::Display() const
{
	if (path == 'Y')
	{
		for (int i = 0; i < rowcurrent; i++)
		{
			for (int j = 0; j < columncurrent; j++)													// for loop to display various chars as the proper displays on the grid
			{																						// for array on a single line
				if (grid[i][j] == '$')
					cout << " ";
				else if (grid[i][j] == '!')
					cout << "0";
				else if (grid[i][j] == '%')
					cout << " ";
				else
				cout << grid[i][j];
			}
		}
		cout << endl << endl;

		for (int i = 0; i < rowcurrent; i++)														// for a 2d array display
		{
			for (int j = 0; j < columncurrent; j++)
			{
				if (grid[i][j] == '$')
					cout << " " << " ";
				else if (grid[i][j] == '!')
					cout << "0" << " ";
				else if (grid[i][j] == '%')
					cout << " " << " ";
				else
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	else if (path == 'N')																		// alterations to previous path
	{
		for (int i = 0; i < rowcurrent; i++)
		{
			for (int j = 0; j < columncurrent; j++)
			{
				if (grid[i][j] == '*')
					cout << ".";
				else if (grid[i][j] == '!')
					cout << "0";
				else if (grid[i][j] == '%')
					cout << " ";
				else
					cout << grid[i][j];
			}
		}
		cout << endl << endl;

		for (int i = 0; i < rowcurrent; i++)
		{
			for (int j = 0; j < columncurrent; j++)
			{
				if (grid[i][j] == '*')
					cout << "." << " ";
				else if (grid[i][j] == '!')
					cout << "0" << " ";
				else if (grid[i][j] == '%')
					cout << " " << " ";
				else
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void Grid::TogglePath()
{
	if (path = 'Y')																						// switches path to opposite form and replaces $ with *
	{																									// to know where the mover has been
		for (int i = 0; i < rowcurrent; i++)
		{
			for (int j = 0; j < columncurrent; j++)
			{
				if (grid[i][j] == '$')
				{
					grid[i][j] = '*';
				}
			}
		}
		path = 'N';
	}
	else if (path = 'N')																			// opposite of other path
	{
		for (int i = 0; i < rowcurrent; i++)
		{
			for (int j = 0; j < columncurrent; j++)
			{
				if (grid[i][j] == '*')
				{
					grid[i][j] = '$';
				}
			}
		}
		path = 'Y';
	}
}
int Grid::GetRow() const
{
	int rw = -1;
	for (int i = 0; i < rowcurrent; i++)
	{
		for (int j = 0; j < columncurrent; j++)
		{
			if (grid[i][j] == '>' || grid[i][j] == '^' || grid[i][j] == 'v' || grid[i][j] == '<' || grid[i][j]=='@')
				rw = i;
		}
	}
	return rw;
}

int Grid::GetCol() const
{
	int cw = -1;
	for (int i = 0; i < columncurrent; i++)
	{
		for (int j = 0; j < rowcurrent; j++)
		{
			if (grid[j][i] == '>' || grid[j][i] == '^' || grid[j][i] == 'v' || grid[j][i] == '<' || grid[j][i]=='@')
				cw = i;
		}
	}
	return cw;
}

int Grid::GetNumRows() const
{
	return rowcurrent;
}

int Grid::GetNumCols() const
{
	return columncurrent;
}

bool Grid::FrontIsClear() const											// uses multiple if statements to determine if the array in front of the mover is available to replace
{
	if ((grid[GetRow()][GetCol()]) == '^')
	{
		if ((grid[GetRow() - 1][GetCol()]) == '#')
			return false;
		else if ((GetRow() - 1 < 0))
			return false;
		else
			return true;
	}
	else if ((grid[GetRow()][GetCol()]) == '<')
	{
		if ((grid[GetRow()][GetCol() - 1]) == '#')
			return false;
		else if ((GetCol() - 1) < 0)
			return false;
		else
			return true;
	}
	else if ((grid[GetRow()][GetCol()]) == 'v')
	{
		if ((grid[GetRow() + 1][GetCol()]) == '#')
			return false;
		else if ((GetRow() + 1) >= rowcurrent)
			return false;
		else
			return true;
	}
	else if ((grid[GetRow()][GetCol()]) == '>')
	{
		if ((grid[GetRow()][GetCol() + 1]) == '#')
			return false;
		else if ((GetCol() + 1) >= columncurrent)
			return false;
		else
			return true;
	}
	else
		return false;
}

bool Grid::RightIsClear() const														// same as front function but to the right of mover
{
	if ((grid[GetRow()][GetCol()]) == '^')
	{
		if ((grid[GetRow()][GetCol() + 1]) == '#')
			return false;
		else if ((GetCol() + 1) >= columncurrent)
			return false;
		else
			return true;
	}
	else if ((grid[GetRow()][GetCol()]) == '<')
	{
		if ((grid[GetRow() - 1][GetCol()]) == '#')
			return false;
		else if ((GetRow() - 1) < 0)
			return false;
		else
			return true;
	}
	else if ((grid[GetRow()][GetCol()]) == 'v')
	{
		if ((grid[GetRow()][GetCol() - 1]) == '#')
			return false;
		else if ((GetCol() - 1) < 0)
			return false;
		else
			return true;
	}
	else if ((grid[GetRow()][GetCol()]) == '>')
	{
		if ((grid[GetRow() + 1][GetCol()]) == '#')
			return false;
		else if ((GetRow() + 1) >= rowcurrent)
			return false;
		else
			return true;
	}
	else
		return false;
}

void Grid::PutDown()										// places an item down on mover which turns it into a @
{
	if ((grid[GetRow()][GetCol()]) == '^'|| grid[GetRow()][GetCol()] == '<'|| grid[GetRow()][GetCol()] == 'v'|| grid[GetRow()][GetCol()] == '>')
	{
		previousdirection = grid[GetRow()][GetCol()];
		grid[GetRow()][GetCol()] = '@';
	}
}

bool Grid::PutDown(int r, int c)														// puts down an item 0 or ! at certain parameter location
{
	if ( r<0 || r >= rowcurrent ||  c < 0 || c >= columncurrent)
		return false;
	else if (r >= 0 && r < rowcurrent &&  c >= 0 && c < columncurrent)
	{
		if (grid[r][c] == '#' || grid[r][c] == '@' || grid[r][c] == '!')
			return false;
		else if(grid[r][c]=='^'|| grid[r][c] == '<'|| grid[r][c] == 'v'|| grid[r][c] == '>')
		{
			previousdirection = grid[r][c];
			grid[r][c] = '@';
			return true;
		}
		else
		{
			grid[r][c] = '!';
			return true;
		}
	}
}

bool Grid::PlaceBlock(int r, int c)									// places block # at certain parameter location
{
	if (r < 0 || r >= rowcurrent || c < 0 || c >= columncurrent)
		return false;
	else if (r >= 0 && r < rowcurrent &&  c >= 0 && c < columncurrent)
	{
		if (grid[r][c] == '#' || grid[r][c] == '@' || grid[r][c] == '!' || grid[r][c] == '^' || grid[r][c] == '<' || grid[r][c] == 'v' || grid[r][c] == '>')
			return false;
		else
		{
			grid[r][c] = '#';
			return true;
		}
	}
}
bool Grid::PickUp()																		// picks up an item 0 or ! on grid which turns the mover into @
{
	for (int i = 0; i < rowcurrent ; i++)
	{
		for (int j = 0; j < columncurrent ; j++)
		{
			if (grid[i][j] == '@')
			{
				grid[i][j] = previousdirection;
				return true;
			}
		}
	}
}

bool Grid::Move(int s)										// various if statements and for loops to move the mover if applicable
{
	int looploc = GetRow();
	int looppla = GetCol();

	if ((grid[GetRow()][GetCol()]) == '@')
	{
		if (previousdirection == '^' || previousdirection==Grid::NORTH)
		{
			if ((GetRow() - s) < 0)														// if in range of size
				return false;
			for (int i = 0; i < s; i++)
			{
				if (grid[looploc - 1][GetCol()] == '#')
					return false;
				else if (grid[looploc - 1][GetCol()] == '.' || grid[looploc - 1][GetCol()] == ' ' || grid[looploc - 1][GetCol()] == '*' || grid[looploc - 1][GetCol()] == '$')
				{
					if (path == 'Y')												// dependant on path to replace empty spaces on grid
						grid[looploc - 1][GetCol()] = '$';
					else if (path == 'N')
						grid[looploc - 1][GetCol()] = '*';
				}
				if (s == i + 1)														// right before loop ends to actually move the mover and replace his location from start
				{
					if (grid[looploc - 1][GetCol()] == '!')
					{
						previousdirection = '^';
						grid[GetRow()][GetCol()] = '$';
						grid[looploc - 1][looppla] = '@';
						return true;
					}
					else
					{
						grid[GetRow()][GetCol()] = '!';
						grid[looploc - 1][looppla] = '^';
						return true;
					}
				}
				looploc--;
			}
			looploc = GetRow();
	}
		else if(previousdirection=='<' || previousdirection==Grid::WEST)
		{
			if ((GetCol() - s) < 0)
				return false;
			for (int i = 0; i < s; i++)
			{
				if (grid[GetRow()][looppla - 1] == '#')
					return false;
				else if (grid[GetRow()][looppla - 1] == '.' || grid[GetRow()][looppla - 1] == ' ' || grid[GetRow()][looppla - 1] == '*' || grid[GetRow()][looppla - 1] == '$')
				{
					if (path == 'Y')
						grid[GetRow()][looppla - 1] = '$';
					else if (path == 'N')
						grid[GetRow()][looppla - 1] = '*';
				}
				if (s == i + 1)
				{
					if (grid[GetRow()][looppla - 1] == '!')
					{
						previousdirection = '<';
						grid[GetRow()][GetCol()] = '$';
						grid[looploc][looppla - 1] = '@';
						return true;
					}
					else
					{
						grid[GetRow()][GetCol()] = '!';
						grid[looploc][looppla - 1] = '<';
						return true;
					}
				}
				looppla--;
			}
			looppla = GetCol();
		}
		else if(previousdirection=='v' || previousdirection==Grid::SOUTH)
		{
			if ((GetRow() + s) >= rowcurrent)
				return false;
			for (int i = 0; i < s; i++)
			{
				if (grid[looploc + 1][GetCol()] == '#')
					return false;
				else if (grid[looploc + 1][GetCol()] == '.' || grid[looploc + 1][GetCol()] == ' ' || grid[looploc + 1][GetCol()] == '*' || grid[looploc + 1][GetCol()] == '$')
				{
					if (path == 'Y')
						grid[looploc + 1][GetCol()] = '$';
					else if (path == 'N')
						grid[looploc + 1][GetCol()] = '*';
				}
				if (s == i + 1)
				{
					if (grid[looploc + 1][GetCol()] == '!')
					{
						previousdirection = 'v';
						grid[GetRow()][GetCol()] = '$';
						grid[looploc + 1][looppla] = '@';
						return true;
					}
					else
					{
						grid[GetRow()][GetCol()] = '!';
						grid[looploc + 1][looppla] = 'v';
						return true;

					}

				}
				looploc++;
			}
			looploc = GetRow();
		}
		else if(previousdirection=='>' || previousdirection==Grid::EAST)
		{
			if ((GetCol() + s) >= columncurrent)
				return false;
			for (int i = 0; i < s; i++)
			{
				if (grid[GetRow()][looppla + 1] == '#')
					return false;
				else if (grid[GetRow()][looppla + 1] == '.' || grid[GetRow()][looppla + 1] == ' ' || grid[GetRow()][looppla + 1] == '*' || grid[GetRow()][looppla + 1] == '$')
				{
					if (path == 'Y')
						grid[GetRow()][looppla + 1] = '$';
					else if (path == 'N')
						grid[GetRow()][looppla + 1] = '*';
				}
				if (s == i + 1)
				{
					if (grid[GetRow()][looppla + 1] == '!')
					{
						previousdirection = '>';
						grid[GetRow()][GetCol()] = '$';
						grid[looploc][looppla + 1] = '@';
						return true;
					}
					else
					{
						grid[GetRow()][GetCol()] = '!';
						grid[looploc][looppla + 1] = '>';
						return true;
					}
				}
				looppla++;
			}
			looppla = GetCol();
		}
}





	else if ((grid[GetRow()][GetCol()]) == '^' || grid[GetRow()][GetCol()]==Grid::NORTH)
	{
		if ((GetRow() - s) < 0)
			return false;
		for (int i = 0; i < s; i++)
		{
			if (grid[looploc - 1][GetCol()] == '#')
				return false;
			else if (grid[looploc - 1][GetCol()] == '.' || grid[looploc - 1][GetCol()] == ' ' || grid[looploc - 1][GetCol()] == '*' || grid[looploc - 1][GetCol()] == '$')
			{
				if (path == 'Y')
					grid[looploc - 1][GetCol()] = '$';
				else if (path == 'N')
					grid[looploc - 1][GetCol()] = '*';
			}
				if (s==i+1)
				{
						if (grid[looploc - 1][GetCol()] == '!')
						{
							previousdirection = '^';
							grid[GetRow()][GetCol()] = '$';
							grid[looploc - 1][looppla] = '@';
							return true;
						}
						else
						{
							grid[GetRow()][GetCol()] = '$';
							grid[looploc - 1][looppla] = '^';
							return true;
						}
				}
						looploc--;
		}
		looploc = GetRow();
	}
	else if ((grid[GetRow()][GetCol()]) == '<' || grid[GetRow()][GetCol()] == Grid::WEST)
	{
		if ((GetCol() - s) < 0)
			return false;
		for (int i = 0; i < s; i++)
		{
			if (grid[GetRow()][looppla-1] == '#')
				return false;
			else if (grid[GetRow()][looppla-1] == '.' || grid[GetRow()][looppla - 1] == ' ' || grid[GetRow()][looppla - 1] == '*' || grid[GetRow()][looppla - 1] == '$')
			{
				if (path == 'Y')
					grid[GetRow()][looppla - 1] = '$';
				else if (path == 'N')
					grid[GetRow()][looppla - 1] = '*';
			}
			if (s==i+1)
			{
					if (grid[GetRow()][looppla - 1] == '!')
					{
						previousdirection = '<';
						grid[GetRow()][GetCol()] = '$';
						grid[looploc][looppla - 1] = '@';
						return true;
					}
					else
					{
						grid[GetRow()][GetCol()] = '$';
						grid[looploc][looppla - 1] = '<';
						return true;
					}
			}
			looppla--;
		}
		looppla = GetCol();
	}
	else if ((grid[GetRow()][GetCol()]) == 'v' || grid[GetRow()][GetCol()] == Grid::SOUTH)
	{
		if ((GetRow() + s) >= rowcurrent)
			return false;
		for (int i = 0; i < s; i++)
		{
			if (grid[looploc + 1][GetCol()] == '#')
				return false;
			else if (grid[looploc + 1][GetCol()] == '.' || grid[looploc + 1][GetCol()] == ' ' || grid[looploc + 1][GetCol()] == '*' || grid[looploc + 1][GetCol()] == '$')
			{
				if (path == 'Y')
					grid[looploc + 1][GetCol()] = '$';
				else if(path=='N')
				grid[looploc + 1][GetCol()] = '*';
			}
			if (s==i+1)
			{
					if (grid[looploc + 1][GetCol()] == '!')
					{
						previousdirection = 'v';
						grid[GetRow()][GetCol()] = '$';
						grid[looploc + 1][looppla] = '@';
						return true;
					}
					else
					{
						grid[GetRow()][GetCol()] = '$';
						grid[looploc + 1][looppla] = 'v';
						return true;
						
					}
				
			}
			looploc++;
		}
		looploc = GetRow();
	}
	else if ((grid[GetRow()][GetCol()]) == '>' || grid[GetRow()][GetCol()] == Grid::EAST)
	{
		if ((GetCol() + s) >= columncurrent)
			return false;
		for (int i = 0; i < s; i++)
		{
			if (grid[GetRow()][looppla + 1] == '#')
				return false;
			else if (grid[GetRow()][looppla + 1] == '.' || grid[GetRow()][looppla + 1] == ' ' || grid[GetRow()][looppla + 1] == '*' || grid[GetRow()][looppla + 1] == '$')
			{
				if(path=='Y')
					grid[GetRow()][looppla + 1] = '$';
				else if(path=='N')
					grid[GetRow()][looppla + 1] = '*';
			}
			if (s==i+1)
			{
					if (grid[GetRow()][looppla + 1] == '!')
					{
						previousdirection = '>';
						grid[GetRow()][GetCol()] = '$';
						grid[looploc][looppla + 1] = '@';
						return true;
					}
					else
					{
						grid[GetRow()][GetCol()] = '$';
						grid[looploc][looppla + 1] = '>';
						return true;
					}
			}
			looppla++;
		}
		looppla = GetCol();
	}
}

void Grid::TurnLeft()																			// turns mover to the left depending on direction
{
	if (grid[GetRow()][GetCol()] == '^' || grid[GetRow()][GetCol()] == Grid::NORTH)
	{
		grid[GetRow()][GetCol()] = '<';
		previousdirection = '<';
	}
	else if (grid[GetRow()][GetCol()] == '<' || grid[GetRow()][GetCol()] == Grid::WEST)
	{
		grid[GetRow()][GetCol()] = 'v';
		previousdirection = 'v';
	}
	else if (grid[GetRow()][GetCol()] == 'v' || grid[GetRow()][GetCol()] == Grid::SOUTH)
	{
		grid[GetRow()][GetCol()] = '>';
		previousdirection = '>';
	}
	else if (grid[GetRow()][GetCol()] == '>' || grid[GetRow()][GetCol()] == Grid::EAST)
	{
		grid[GetRow()][GetCol()] = '^';
		previousdirection = '^';
	}
	else if (grid[GetRow()][GetCol()] == '@')
	{
		if (previousdirection == '^')
			previousdirection = '<';
		else if (previousdirection == '<')
			previousdirection = 'v';
		else if (previousdirection == 'v')
			previousdirection = '>';
		else if (previousdirection == '>')
			previousdirection = '^';
	}
}

void Grid::Grow(int gr, int gc)										// increases row/column if applicable
{
	int newrow = rowcurrent + gr;
	int newcol = columncurrent + gc;

	if (((newrow) > 40) && ((newcol) > 40))
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				if (grid[i][j] != '#' && grid[i][j] != ' ' && grid[i][j] != '$' && grid[i][j] != '*' && grid[i][j] != '.' && grid[i][j] != '@' && grid[i][j] != '!' && grid[i][j] != '^' && grid[i][j] != 'v' && grid[i][j] != '<' && grid[i][j] != '>')
				grid[i][j] = '.';
			}
		}
		rowcurrent = 40;
		columncurrent = 40;
	}
	else if (((newrow) > 40) && ((newcol) < 41))
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < newcol; j++)
			{
				if (grid[i][j] != '#' && grid[i][j] != ' ' && grid[i][j] != '$' && grid[i][j] != '*' && grid[i][j] != '.' && grid[i][j] != '@' && grid[i][j] != '!' && grid[i][j] != '^' && grid[i][j] != 'v' && grid[i][j] != '<' && grid[i][j] != '>')
				grid[i][j] = '.';
			}
		}
		rowcurrent = 40;
		columncurrent = newcol;
	}
	else if (((newrow) < 40) && ((newcol) > 40))
	{
		for (int i = 0; i < newrow; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				if (grid[i][j] != '#' && grid[i][j] != ' ' && grid[i][j] != '$' && grid[i][j] != '*' && grid[i][j] != '.' && grid[i][j] != '@' && grid[i][j] != '!' && grid[i][j] != '^' && grid[i][j] != 'v' && grid[i][j] != '<' && grid[i][j] != '>')
				grid[i][j] = '.';
			}
		}
		rowcurrent = newrow;
		columncurrent = 40;
	}
	else if (((newrow) < 40) && ((newcol) < 40))
	{
		for (int i=0; i < newrow; i++)
		{
			for (int j = 0; j < newcol; j++)
			{
				if (grid[i][j] != '#' && grid[i][j] != ' ' && grid[i][j] != '$' && grid[i][j] != '*' && grid[i][j] != '.' && grid[i][j] != '@' && grid[i][j] != '!' && grid[i][j] != '^' && grid[i][j] != 'v' && grid[i][j] != '<' && grid[i][j] != '>')
					grid[i][j] = '.';
			}
		}
		rowcurrent = newrow;
		columncurrent = newcol;
	}
}
