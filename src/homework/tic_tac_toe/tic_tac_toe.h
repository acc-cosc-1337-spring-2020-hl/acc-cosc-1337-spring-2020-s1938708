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
	TicTacToe(int size) : pegs{ size * size, "" } {}
	bool game_over();
	void start_game(string first_player);
	void mark_board(int position);
	string get_player()const;
	string get_winner() const;
	friend std::ostream& operator<<(std::ostream& out, const TicTacToe& a);
	friend std::istream& operator>>(std::istream& in, TicTacToe& a);

protected:
	std::vector<std::string> pegs{};
	virtual bool check_column_win();
	virtual bool check_row_win();
	virtual bool check_diagonal_win();
private:
	void set_winner();
	void set_next_player();
	bool check_board_full();
	void clear_board();
	string player;
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