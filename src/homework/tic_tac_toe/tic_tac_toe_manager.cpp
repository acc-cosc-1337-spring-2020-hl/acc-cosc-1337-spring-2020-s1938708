//cpp
#include"tic_tac_toe_manager.h"


void TicTacToe_Manager::save_game(unique_ptr<TicTacToe>& game)
{
	game_hold.push_back(std::move(game));
	update_winner_count(game->get_winner());
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
	for (auto& vector_manager : manager.game_hold)
	{
		cout << vector_manager;
		
	}
	return out;
}
