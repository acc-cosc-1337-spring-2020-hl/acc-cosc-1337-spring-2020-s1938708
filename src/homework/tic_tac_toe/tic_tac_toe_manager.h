//h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include"tic_tac_toe.h"
#include<vector>
#include<iostream>
#include<memory>

using std::string; using std::vector; using std::unique_ptr; 

class TicTacToe_Manager
{
public:
	void save_game(unique_ptr<TicTacToe> game);
	friend std::ostream& operator<<(std::ostream& out, const TicTacToe_Manager& manager);
	void get_winner_total(int& o, int& w, int& t);
private:
	vector<TicTacToe> games;
	int o_win = { 0 };
	int x_win = { 0 };
	int tie = { 0 };

	void update_winner_count(string winner);
};

#endif // !TIC_TAC_TOE_MANAGER_H
