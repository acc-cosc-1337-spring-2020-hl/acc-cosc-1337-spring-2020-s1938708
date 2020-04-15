//h
#include "tic_tac_toe.h"

#ifndef TIC_TAC_TOE_3
#define TIC_TAC_TOE_3

class Tic_Tac_Toe_3 : public TicTacToe
{
public:
	Tic_Tac_Toe_3() : TicTacToe(3) {}

private:
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();
};

#endif // !TIC_TAC_TOE_3