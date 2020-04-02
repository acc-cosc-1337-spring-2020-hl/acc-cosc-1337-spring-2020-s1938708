//h
#include<string>
#include<iostream>
#include<vector>
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

using std::string; using std::cout;

class TicTacToe
{
public:
	bool game_over();
	void start_game(string first_player);
	void mark_board(int position);
	string get_player()const;
	void display_board()const;
	string get_winner();
private:
	bool check_column_win();
	bool check_row_win();
	//bool check_diagonal_win();
	void set_winner();
	void set_next_player();
	bool check_board_full();
	void clear_board();
	string player;
	std::vector<std::string> pegs{ 9, " " };
	string winner;
};

class Error
{
public:
	Error(string msg);
	string get_message();
private:
	string message;
};

#endif // !TIC_TAC_TOE_H