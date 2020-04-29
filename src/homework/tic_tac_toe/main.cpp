#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

using std::cout; using std::cin; using std::string;

int main()
{
	//string player; //Player is never reinitialized and makes the code not work outside loop
	unique_ptr<TicTacToe_Manager> Manage = make_unique<TicTacToe_Manager>();
	int choice, game_choice;

	cout << "Tic Tac Toe by Simon.";
	//unique_ptr<TicTacToe> game; //game is never reinitialized because it's outside the loop.
	do
	{
		string player;
		unique_ptr<TicTacToe> game;
		cout << "\nTicTacToe 3 or 4? ";
		cin >> game_choice;

		if (game_choice == 3)
		{
			game = make_unique<Tic_Tac_Toe_3>(3);
		}
		else if (game_choice == 4)
		{
			game = make_unique<Tic_Tac_Toe_4>(4);
		}

		while (!(player == "O" || player == "X")) //This while loop catches incorrect input for me and doesn't need a break;
		{
			try {
				cout << "Please choose one: 'X' or 'O'\n";
				cin >> player;
				game->start_game(player);
			}
			catch (Error e) {

				cout << e.get_message();
			}
		}

		do
		{
			/*try
			{
				cout << "\nEnter 'X' or 'O' to start the game: "; //This previous code no longer works because it breaks the whole loop.
				cin >> player;
				break;
			}
			catch(Error e)
			{
				cout << e.get_message();
			}*/

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