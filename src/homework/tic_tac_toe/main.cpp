#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include<iostream>

using std::cout; using std::cin;
int main() 
{
	string choice, player;
	TicTacToe game;
	TicTacToe_Manager Manage;
	int num;

	cout << "Tic Tac Toe by Simon.";
	do
	{
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

		cin >> game;
		
		cout << "The winner is: " << game.get_winner();

		Manage.save_game(game);


		cout << "\nPress [Q/q] to quit. Anything else to continue playing: ";
		cin >> choice;
	} while (choice != "Q" && choice != "q");

	cout << Manage;

	return 0;
}