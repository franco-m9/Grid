/* Franco Marcoccia
COP3330 Section 6
Homework 4
This is a cpp file which will run the Trapped game
*/

#include <iostream>
#include "grid.h"
using namespace std;

int main()
{
	int rows, columns;																									// variables for user input

	cout << "Oh no! You are trapped in the Giant Mole People's jail cell!" << endl;
	cout << "Since the Mole people are blind and left an exit in the cell," << endl;
	cout << "it is up to you to escape and join the human resistance!" << endl;
	cout << "How many rows are in the jail cell?: ";
	cin >> rows;													
	cout << "How many columns are in the jail cell?: ";
	cin >> columns;

	Grid g(rows, columns);
	g.Display();
	
	while (g.FrontIsClear() == true)										// while loop which brings the mover up to a wall
	{
		g.Move(1);
		if (g.GetRow() == 0 || g.GetRow() == rows - 1 || g.GetCol() == 0 || g.GetCol() == columns - 1)
		{
			g.Move(1);																							// if finds exit in a straight line then exit
			cout << "You escaped!" << endl;
			cout << "The exit was in row " << g.GetRow() << " and column " << g.GetCol() << endl << endl;
			g.Display();
			break;
		}
	}
	
	if (g.GetRow() != 0 && g.GetRow() != rows - 1 && g.GetCol() != 0 && g.GetCol() != columns - 1)				// if not , turn left (happens once only)
	{
		if (g.FrontIsClear() == false)
			g.TurnLeft();
	}

	while (g.GetRow() != 0 && g.GetRow() != rows - 1 && g.GetCol() != 0 && g.GetCol() != columns - 1)			
	{
		if (g.RightIsClear() == true)																			// if right of mover is clear, 270 degree turn and exit
		{
				g.TurnLeft();
				g.TurnLeft();
				g.TurnLeft();
				g.Move(1);
				cout << "You escaped!" << endl;
				cout << "The exit was in row " << g.GetRow() << " and column " << g.GetCol() << endl << endl;
				g.Display();
				break;
		}
		else if (g.RightIsClear() == false)
		{
			if (g.FrontIsClear() == true)																				// if not, keep moving 1 and exit
			{
				g.Move(1);
				if (g.GetRow() == 0 || g.GetRow() == rows - 1 || g.GetCol() == 0 || g.GetCol() == columns - 1)
				{
					cout << "You escaped!" << endl;
					cout << "The exit was in row " << g.GetRow() << " and column " << g.GetCol() << endl << endl;
					g.Display();
					break;
				}
			}
			else if (g.FrontIsClear() == false)																			// if no exit still, keep turning left and repeat
				g.TurnLeft();
		}
	}
}

