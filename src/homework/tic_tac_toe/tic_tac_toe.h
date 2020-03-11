//h
#include<string>
#include<iostream>
#include<vector>

using std::string; using std::cout;

class TicTacToe
{
public:
	bool game_over();
	void start_game(string first_player);
	void mark_board(int position);
	string get_player()const;
	void display_board()const;
private:
	void set_next_player();
	bool check_board_full();
	void clear_board();
	string player;
	std::vector<std::string> pegs{ 9, " " };
};

class Error
{
public:
	Error(string msg);
	string get_message();
private:
	string message;
};