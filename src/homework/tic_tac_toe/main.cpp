#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <functional>

using std::cout; using std::cin; using std::string;

int main()
{
	using std::cout; using std::cin;
	string player;
	unique_ptr<TicTacToe_Manager> Manage = make_unique<TicTacToe_Manager>();
	int choice, game_choice;

	cout << "Tic Tac Toe by Simon.";
	unique_ptr<TicTacToe> game;
	do
	{
		cout << "\nTicTacToe 3 or 4? ";
		cin >> game_choice;

		if (game_choice == 3)
		{
			game = make_unique<Tic_Tac_Toe_3>();
		}
		else if (game_choice == 4)
		{
			game = make_unique<Tic_Tac_Toe_4>();
		}

		
		while (!(player == "X" || player == "O")) 
		{
			try
			{
				cout << "\nEnter 'X' or 'O' to start the game: ";
				cin >> player;
				game->start_game(player);
			}
			catch (Error e) 
			{
				cout << e.get_message();
			}
		}

		do
		{
			try
			{
				cin >> *game;
				cout << *game;
			}
			catch (Error e)
			{
				cout << e.get_message();
			}
		} while (!game->game_over());
		

		cout << "The winner is: " << game->get_winner();

		Manage->save_game(game);


		cout << "\nPress 0 to continue playing: ";
		cin >> choice;
	} while (choice == 0);

	cout << *Manage;

	return 0;
}


