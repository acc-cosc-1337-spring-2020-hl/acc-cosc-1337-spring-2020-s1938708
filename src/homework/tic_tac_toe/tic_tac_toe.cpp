//cpp
#include"tic_tac_toe.h"

bool TicTacToe::game_over()
{
	if (check_row_win() == true)
	{
		set_winner();
		return check_row_win();
	}
	else if (check_column_win() == true)
	{
		set_winner();
		return check_column_win();
	}
	else if (check_diagonal_win() == true)
	{
		set_winner();
		return check_diagonal_win();
	}
	else if (check_board_full() == true)
	{
		winner = "C";
		return check_board_full();
	}
	else { return false; }
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
	cout << "\n\n";

	for (int i = 0; i < 9; i += 3)
	{
		cout << pegs[i] << "|" << pegs[i+1] << "|" << pegs[i+2] << "\n";
	}
	cout << "\n";
}

bool TicTacToe::check_column_win()
{
	if (pegs.at(0) == "X" && pegs.at(3) == "X" && pegs.at(6) == "X"
		|| pegs.at(0) == "O" && pegs.at(3) == "O" && pegs.at(6) == "O")
	{
		return true;
	}

	else if (pegs.at(1) == "X" && pegs.at(4) == "X" && pegs.at(7)== "X"
		     || pegs.at(1) == "O" && pegs.at(4) == "O" && pegs.at(7) == "O")
	{
		return true;
	}

	else if (pegs.at(2) == "X" && pegs.at(5) == "X" && pegs.at(8) == "X"
		     || pegs.at(2) == "O" && pegs.at(5) == "O" && pegs.at(8) == "O")
	{
		return true;
	}
	else { return false; }
}

bool TicTacToe::check_row_win()
{
	if (pegs.at(0) == "X" && pegs.at(1) == "X" && pegs.at(2) == "X"
		|| pegs.at(0) == "O" && pegs.at(1) == "O" && pegs.at(2) == "O")
	{
		return true;
	}

	else if (pegs.at(3) == "X" && pegs.at(4) == "X" && pegs.at(5) == "X"
		     || pegs.at(3) == "O" && pegs.at(4) == "O" && pegs.at(5) == "O")
	{
		return true;
	}

	else if (pegs.at(6) == "X" && pegs.at(7) == "X" && pegs.at(8) == "X"
		     || pegs.at(6) == "O" && pegs.at(7) == "O" && pegs.at(8) == "O")
	{
		return true;
	}
	else { return false; }
}

bool TicTacToe::check_diagonal_win()
{
	if (pegs.at(0) == "X" && pegs.at(4) == "X" && pegs.at(8) == "X"
		|| pegs.at(0) == "O" && pegs.at(4) == "O" && pegs.at(8) == "O")
	{
		return true;
	}

	else if (pegs.at(6) == "X" && pegs.at(4) == "X" && pegs.at(2) == "X"
		|| pegs.at(6) == "O" && pegs.at(4) == "O" && pegs.at(2) == "O")
	{
		return true;
	}
	else { return false; }
}

void TicTacToe::set_winner() 
{
	if (player == "X")
	{
		winner = "O";
	}
	else { winner = "X"; }
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

string TicTacToe::get_winner() { return winner; }

Error::Error(string msg) : message(msg) {};

string Error::get_message() { return message; }
