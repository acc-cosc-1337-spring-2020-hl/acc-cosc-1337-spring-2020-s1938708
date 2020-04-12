//cpp
#include"tic_tac_toe_manager.h"


void TicTacToe_Manager::save_game(const TicTacToe b)
{
	games.push_back(b);
	update_winner_count(b.get_winner());
	get_winner_total(x_win, o_win, tie);
}

void TicTacToe_Manager::get_winner_total(int& o, int& w, int& t)
{
	cout << "\nX wins " << o << ", O wins " << w << ", Ties " << t;
}

void TicTacToe_Manager::update_winner_count(string winner)
{
	if (winner == "X") { x_win += 1; }
	else if (winner == "O") { o_win += 1; }
	else { tie += 1; }
}

std::ostream& operator<<(std::ostream& out, const TicTacToe_Manager& manager)
{
	out << "History of played games:\n";
	for (auto& vector_manager : manager.games)
	{
		cout << vector_manager;
		
	}
	return out;
}
