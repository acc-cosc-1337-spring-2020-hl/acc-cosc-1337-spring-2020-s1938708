//cpp
#include"tic_tac_toe.h"

bool TicTacToe::game_over()
{
	return check_board_full();
}

void TicTacToe::start_game(string first_player)
{
	if (first_player == "X" || first_player == "O")
	{
		clear_board();
		player = first_player;
	}
	else
	{
		throw Error("\nPlayer must be X or O.");
	}
}

void TicTacToe::mark_board(int position)
{
	if (position <= 0 || position >= 10) //How am I supposed to check that the input isn't a char or double? I've seen solutions, but you've mentioned that you don't want solutions not learned in class to be used.
	{
		throw Error("\nPosition must be 1 to 9: ");
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
	cout << "\n";
}

void TicTacToe::set_next_player()
{
	if (player == "X")
	{
		player = "O";
	}
	else if(player == "O")
	{
		player = "X";
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
