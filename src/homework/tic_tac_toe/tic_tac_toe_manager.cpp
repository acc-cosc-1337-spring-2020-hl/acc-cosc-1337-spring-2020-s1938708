//cpp
#include"tic_tac_toe_manager.h"

void TicTacToe_Manager::save_game(const TicTacToe b)
{
	games.push_back(b);
	update_winner_count(get_winner());
}

void TicTacToe_Manager::update_winner_count(string winner)
{
	if (winner == "X") { x_win += 1; }
	else if (winner == "O") { o_win += 1; }
	else { tie += 1; }
}

std::ostream& operator<<(std::ostream& out, const TicTacToe_Manager& manager)
{
	for (auto& vector_manager : manager.games)
	{
		out << &vector_manager.display_board;
	}
	return out;
}
