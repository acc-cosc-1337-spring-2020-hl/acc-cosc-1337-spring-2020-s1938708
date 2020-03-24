#include "tic_tac_toe.h"
#include<iostream>

using std::cout; using std::cin;
int main() 
{
	string choice, player;
	TicTacToe game;

	cout << "Tic Tac Toe by Simon.";

	do
	{
		cout << "\nEnter 'X' or 'O' to start the game: ";
		cin >> player;

		try
		{
			game.start_game(player);
			break;
		}
		catch (Error e)
		{
			cout << e.get_message();
		}
	} while (game.get_player() != "X" || game.get_player() != "O");

	do
	{
		int num;
		cout << "\nEnter a postion (1-9): ";
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