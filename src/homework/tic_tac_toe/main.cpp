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
			cout << "\nIt is player " << game.get_player() << "'s turn.";
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
			game.display_board();
		} while (game.game_over() == false);
		
		cout << "The winner is: " << game.get_winner();

		cout << "\nPress [Q/q] to quit. Anything else to continue playing: ";
		cin >> choice;
	} while (choice != "Q" && choice != "q");
	return 0;
}