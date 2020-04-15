//h
#include "tic_tac_toe.h"

#ifndef TIC_TAC_TOE_4
#define TIC_TAC_TOE_4

class Tic_Tac_Toe_4 : public TicTacToe
{
public:
	Tic_Tac_Toe_4() : TicTacToe(4) {}

private:
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();
};

#endif // !TIC_TAC_TOE_4