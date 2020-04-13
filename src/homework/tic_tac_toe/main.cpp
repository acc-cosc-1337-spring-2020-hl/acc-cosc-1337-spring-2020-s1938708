#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

using std::cout; using std::cin; using std::string;

int main()
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
				cout << "try again \n";
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
}