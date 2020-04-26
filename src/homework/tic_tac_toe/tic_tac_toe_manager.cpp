//cpp
#include"tic_tac_toe_manager.h"


void TicTacToe_Manager::save_game(unique_ptr<TicTacToe>& game)
{
	update_winner_count(game->get_winner());
	games.push_back(std::move(game));
}

void TicTacToe_Manager::get_winner_total(int& o, int& w, int& t)
{
	o = x_win;
	w = o_win;
	t = tie;
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

	out << "O win: " << manager.o_win << " X win: " << manager.x_win << " Tie: " << manager.tie;

	return out;
}
