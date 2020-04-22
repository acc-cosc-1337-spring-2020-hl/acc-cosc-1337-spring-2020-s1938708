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
	if (pegs.size() == 9)
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
	else if (pegs.size() == 16)
	{
		if (position <= 0 || position >= 17) //How am I supposed to check that the input isn't a char or double? I've seen solutions, but you've mentioned that you don't want solutions not learned in class to be used.
		{
			throw Error("\nPosition must be 1 to 16.");
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
}

string TicTacToe::get_player()const { return player; }

bool TicTacToe::check_column_win() { return false; }

bool TicTacToe::check_row_win() { return false; }

bool TicTacToe::check_diagonal_win() { return false; }

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

std::ostream& operator<<(std::ostream& out, const TicTacToe& a)
{
	out << "\n\n";
	if (a.pegs.size() == 9)
	{
		for (int i = 0; i < 9; i += 3)
		{
			cout << a.pegs[i] << "|" << a.pegs[i + 1] << "|" << a.pegs[i + 2] << "\n";
		}
		out << "\n";
	}
	else if (a.pegs.size() == 16)
	{
		for (int i = 0; i < 16; i += 4)
		{
			cout << a.pegs[i] << "|" << a.pegs[i + 1] << "|" << a.pegs[i + 2] << "|" << a.pegs[i + 3] << "\n";
		}
		out << "\n";
	}

	return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& a) //I took out the const in the second parameter. The code works, is there a security flaw that const is needed for? 
{
	int num;
	if (a.pegs.size() == 9)
	{
		do
		{
			cout << "\nIt is player " << a.get_player() << "'s turn.";
			cout << "\nEnter a postion (1-9): ";
			in >> num;
			try
			{
				a.mark_board(num);
			}
			catch (Error e)
			{
				cout << e.get_message();
			}
			cout << a;

		} while (a.game_over() == false);
	}
	else if (a.pegs.size() == 16)
	{
		do
		{
			cout << "\nIt is player " << a.get_player() << "'s turn.";
			cout << "\nEnter a postion (1-16): ";
			in >> num;
			try
			{
				a.mark_board(num);
			}
			catch (Error e)
			{
				cout << e.get_message();
			}
			cout << a;

		} while (a.game_over() == false);
	}

	return in;
}

string TicTacToe::get_winner() const { return winner; }

Error::Error(string msg) : message(msg) {};

string Error::get_message() { return message; }
