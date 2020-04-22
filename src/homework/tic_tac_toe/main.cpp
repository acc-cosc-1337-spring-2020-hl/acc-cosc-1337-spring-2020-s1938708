#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <functional>

using std::cout; using std::cin; using std::string;

int main()
{
	vector<reference_wrapper<TicTacToe>> games{};

	using std::cout; using std::cin;
	string player;
	TicTacToe_Manager Manage;
	int choice, game_choice;

	cout << "Tic Tac Toe by Simon.";

	do
	{
		cout << "\TicTacToe 3 or 4? ";
		cin >> game_choice;
		Tic_Tac_Toe_3 game3;
		Tic_Tac_Toe_4 game4;

		if (game_choice == 3)
		{
			games.push_back(game3);
		}
		else if (game_choice == 4)
		{
			games.push_back(game4);
		}

		reference_wrapper<TicTacToe> game = games.back();

		do
		{
			cout << "\nEnter 'X' or 'O' to start the game: ";
			cin >> player;
			try
			{
				game.get().start_game(player);
				break;
			}
			catch (Error e)
			{
				cout << e.get_message();
			}
		} while (game.get().get_player() != "X" || game.get().get_player() != "O");

		cin >> game.get();

		cout << "The winner is: " << game.get().get_winner();

		Manage.save_game(game.get());


		cout << "\nPress 0 to continue playing: ";
		cin >> choice;
	} while (choice == 0);

	cout << Manage;

	return 0;
}


