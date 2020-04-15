#include "tic_tac_toe_3.h"

/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/



/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/



/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8
*/

bool Tic_Tac_Toe_3::check_column_win()
{
	if (pegs.at(0) == "X" && pegs.at(3) == "X" && pegs.at(6) == "X"
		|| pegs.at(0) == "O" && pegs.at(3) == "O" && pegs.at(6) == "O")
	{
		return true;
	}

	else if (pegs.at(1) == "X" && pegs.at(4) == "X" && pegs.at(7) == "X"
		|| pegs.at(1) == "O" && pegs.at(4) == "O" && pegs.at(7) == "O")
	{
		return true;
	}

	else if (pegs.at(2) == "X" && pegs.at(5) == "X" && pegs.at(8) == "X"
		|| pegs.at(2) == "O" && pegs.at(5) == "O" && pegs.at(8) == "O")
	{
		return true;
	}
	else { return false; }
}

bool Tic_Tac_Toe_3::check_row_win()
{
	if (pegs.at(0) == "X" && pegs.at(1) == "X" && pegs.at(2) == "X"
		|| pegs.at(0) == "O" && pegs.at(1) == "O" && pegs.at(2) == "O")
	{
		return true;
	}

	else if (pegs.at(3) == "X" && pegs.at(4) == "X" && pegs.at(5) == "X"
		|| pegs.at(3) == "O" && pegs.at(4) == "O" && pegs.at(5) == "O")
	{
		return true;
	}

	else if (pegs.at(6) == "X" && pegs.at(7) == "X" && pegs.at(8) == "X"
		|| pegs.at(6) == "O" && pegs.at(7) == "O" && pegs.at(8) == "O")
	{
		return true;
	}
	else { return false; }
}

bool Tic_Tac_Toe_3::check_diagonal_win()
{
	if (pegs.at(0) == "X" && pegs.at(4) == "X" && pegs.at(8) == "X"
		|| pegs.at(0) == "O" && pegs.at(4) == "O" && pegs.at(8) == "O")
	{
		return true;
	}


	else if (pegs.at(6) == "X" && pegs.at(4) == "X" && pegs.at(2) == "X"
		|| pegs.at(6) == "O" && pegs.at(4) == "O" && pegs.at(2) == "O")
	{
		return true;
	}
	else { return false; }
}