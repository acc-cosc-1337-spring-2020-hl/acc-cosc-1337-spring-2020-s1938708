//cpp
#include"tic_tac_toe.h"

bool TicTacToe::game_over()
{
	return check_board_full();
}

void TicTacToe::start_game(string first_player)
{
	if (!(first_player == "X" || first_player == "O"))
	{
		throw Error("\nPlayer must be X or O.");
	}
	else
	{
		clear_board();
		player = first_player;
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
		pegs[position - 1] = player;
		set_next_player();
	}
}

string TicTacToe::get_player()const { return player; }

void TicTacToe::display_board() const
{
	for (int i = 0; i < 9; i += 3)
	{
		cout << pegs[i] << "|" << pegs[i+1] << "|" << pegs[i+2] << "\n";
	}
}

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

bool TicTacToe::check_board_full()
{
	for (auto peg : pegs)
	{
		if (peg == " ")
		{
			return false;
		}
	}

	return true;
}

void TicTacToe::clear_board()
{
	for (auto &peg : pegs)
	{
		peg = " ";
	}
}

Error::Error(string msg) : message(msg) {};

string Error::get_message() { return message; }
