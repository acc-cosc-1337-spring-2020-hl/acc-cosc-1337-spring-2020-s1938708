#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <functional>

using std::cout; using std::cin; using std::string;

int main()
{
	vector<unique_ptr<TicTacToe>> games{};

	using std::cout; using std::cin;
	string player;
	unique_ptr<TicTacToe_Manager> Manage;
	int choice, game_choice;

	cout << "Tic Tac Toe by Simon.";

	do
	{
		cout << "\nTicTacToe 3 or 4? ";
		cin >> game_choice;

		if (game_choice == 3)
		{
			unique_ptr<TicTacToe> game3 = make_unique<Tic_Tac_Toe_3>(3);
			games.push_back(game3);
		}
		else if (game_choice == 4)
		{
			unique_ptr<TicTacToe> game4 = make_unique<Tic_Tac_Toe_4>(4);
			games.push_back(game4);
		}

		

		do
		{
			cout << "\nEnter 'X' or 'O' to start the game: ";
			cin >> player;
			try
			{
				games.back()->start_game(player);
				break;
			}
			catch (Error e)
			{
				cout << e.get_message();
			}
		} while (games.back()->get_player() != "X" || games.back()->get_player() != "O");
		cout << games.back();
		cin >> *games.back();

		cout << "The winner is: " << games.back()->get_winner();

		Manage->save_game(games.back());


		cout << "\nPress 0 to continue playing: ";
		cin >> choice;
	} while (choice == 0);

	cout << *Manage;

	return 0;
}


