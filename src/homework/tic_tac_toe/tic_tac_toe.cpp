//cpp
#include"tic_tac_toe.h"

void TicTacToe::start_game(string first_player)
{
	if (first_player == "X" || first_player == "O")
	{
		player = first_player;
	}
	else
	{
		throw Error("\nPlayer must be X or O.");
	}
}

void TicTacToe::mark_board(int position)
{
	if (position <= 0 || position >= 10)
	{
		throw Error("\nPosition must be 1 to 9.");
	}
	else if (player == "")
	{
		throw Error("\nMust start game first.");
	}
	else
	{
		set_next_player();
	}
}

string TicTacToe::get_player()const { return player; }

void TicTacToe::set_next_player()
{
	if (player == "X")
	{
		player = "O";
	}
	else
	{
		player == "X";
	}
}

Error::Error(string msg) : message(msg) {};

string Error::get_message() { return message; }
