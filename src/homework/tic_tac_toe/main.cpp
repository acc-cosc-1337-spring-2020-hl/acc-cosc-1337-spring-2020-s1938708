#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

using std::cout; using std::cin; using std::string;

/*int main()
{
	int choice = 0;
	TicTacToe_Manager game_manager;
	do {
		TicTacToe game;
		string x_prompt = "X's TURN \n";
		string o_prompt = "Os TURN\n";
		string first_player;


		bool first_player_success = false;
		while (!first_player_success) {
			try {
				cout << "Enter X or O to choose the first player \n";
				cin >> first_player;
				game.start_game(first_player);
				cout << game;
				first_player_success = true;
			}
			catch (Error &ex) {
				cout << ex.get_message() << "\n";
				cout << "Try again \n";
			}
		}

		while (!game.game_over()) {
			if (game.get_player() == "X") {
				cout << x_prompt;
			}
			else {
				cout << o_prompt;
			}
			bool mark_board_success = false;

			while (!mark_board_success) {

				try {
					cin >> game;
					mark_board_success = true;

				}
				catch (Error &ex) {
					cout << ex.get_message() << "\n";
					cout << "try again \n";
				}

				cout << game;

				if (game.game_over()) {
					cout << "winner :" << game.get_winner() << "\n";
				}

			}

			//mark_board_success = false;

		}
		game_manager.save_game(game);
		cout << game_manager;
		cout << "\n";
		cout << "Enter 0 to continue the game \n";
		cin >> choice;
		if (choice != 0) {
			cout << game_manager;
		}
		cout << "\n";

	} while (choice == 0);

	return 0;
}*/

int main()
{
	string player;
	TicTacToe_Manager Manage;
	int num, choice, game_choice;

	cout << "Tic Tac Toe by Simon.";

	do
	{
		vector<reference_wrapper<TicTacToe>> games{};

		cout << "Choose either \'3\' for TicTacToe 3 or \'4\' for TicTacToe 4: ";
		cin >> game_choice;
		
		if (game_choice == 3) 
		{
			Tic_Tac_Toe_3 game3;
			games.push_back(game3);
		}
		else if (game_choice == 4)
		{
			Tic_Tac_Toe_4 game4;
			games.push_back(game4);
		}

		bool first_player_success = false;
		do
		{
			cout << "\nEnter 'X' or 'O' to start the game: ";
			cin >> player;
			try
			{
				.start_game(player);
				first_player_success = true;
				break;
			}
			catch (Error e)
			{
				cout << e.get_message();
			}
		} while (!first_player_success);

		cin >> game;

		cout << "The winner is: " << game.get_winner();

		Manage.save_game(game);


		cout << "\nPress 0 to continue playing: ";
		cin >> choice;
	} while (choice == 0);

	cout << Manage;

	return 0;
}