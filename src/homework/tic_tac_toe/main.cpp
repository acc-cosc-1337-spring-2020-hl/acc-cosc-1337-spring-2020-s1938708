#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

using std::cout; using std::cin; using std::string;

int main()
{
	vector<reference_wrapper<TicTacToe>> games{};
	int choice = 0, game_choice, games_size = 0;
	//TicTacToe_Manager game_manager;
	do {

		string x_prompt = "X's TURN \n";
		string o_prompt = "Os TURN\n";
		string first_player;

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
		games_size = games.size();

		for (int i = 0; i <= games.size(); i++)
		{
			cout << i;
		}

		bool first_player_success = false;
		while (!first_player_success) {
			try {
				cout << "Enter X or O to choose the first player \n";
				cin >> first_player;
				games[games_size - 1].get().start_game(first_player);
				cout << games[games_size - 1];
				first_player_success = true;
			}
			catch (Error &ex) {
				cout << ex.get_message() << "\n";
				cout << "Try again \n";
			}
		}

		while (!games[games_size - 1].get().game_over()) {
			if (games[games_size - 1].get().get_player() == "X") {
				cout << x_prompt;
			}
			else {
				cout << o_prompt;
			}
			bool mark_board_success = false;

			while (!mark_board_success) {

				try {
					cin >> games[games_size - 1].get();
					mark_board_success = true;

				}
				catch (Error &ex) {
					cout << ex.get_message() << "\n";
					cout << "try again \n";
				}

				cout << games.back().get();

				if (games.back().get().game_over()) {
					cout << "winner :" << games.back().get().get_winner() << "\n";
				}

			}

			//mark_board_success = false;

		}
		//game_manager.save_game(game);
		//cout << game_manager;
		cout << "\n";
		cout << "Enter 0 to continue the game \n";
		cin >> choice;
		//if (choice != 0) {
		//	cout << game_manager;
		//}
		cout << "\n";

	} while (choice == 0);

	return 0;
}
