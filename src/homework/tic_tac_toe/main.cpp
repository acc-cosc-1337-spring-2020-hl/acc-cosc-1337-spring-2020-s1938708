#include "tic_tac_toe.h"
#include<iostream>

using std::cout; using std::cin;
int main() 
{
	string choice;
	TicTacToe game;

	game.start_game("X");

	do
	{
		int num;
		cout << "\nEnter a postion: ";
		cin >> num;

		try
		{
			game.mark_board(num);
		}
		catch (Error e)
		{
			cout << e.get_message();
		}

		cout << "\nContinue Playing (Y/y)? ";
		cin >> choice;

	} while (choice == "Y" || choice == "y");
	return 0;
}