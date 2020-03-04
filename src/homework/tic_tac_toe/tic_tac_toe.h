//h
#include<string>

using std::string;

class TicTacToe
{
public:
	void start_game(string first_player);
	void mark_board(int position);
	string get_player()const;
private:
	void set_next_player();
	string player;
};

class Error
{
public:
	Error(string msg);
	string get_message();
private:
	string message;
};