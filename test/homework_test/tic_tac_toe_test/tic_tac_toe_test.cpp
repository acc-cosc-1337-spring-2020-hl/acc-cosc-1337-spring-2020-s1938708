#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over")
{
	Tic_Tac_Toe_3 game;
	game.start_game("X");

	REQUIRE(game.game_over() == false);
}
TEST_CASE("Test game over 4")
{
	Tic_Tac_Toe_4 game;
	game.start_game("X");

	REQUIRE(game.game_over() == false);
}

TEST_CASE("Test can't call mark board before start game")
{
	Tic_Tac_Toe_3 game;
	REQUIRE_THROWS_AS(game.mark_board(1), Error);
}
TEST_CASE("Test can't call mark board before start game 3")
{
	Tic_Tac_Toe_4 game;
	REQUIRE_THROWS_AS(game.mark_board(1), Error);
}

TEST_CASE("Test start game only accepts X or O")
{
	Tic_Tac_Toe_3 game;
	REQUIRE_THROWS_AS(game.start_game("L"), Error);
}
TEST_CASE("Test start game only accepts X or O 4")
{
	Tic_Tac_Toe_4 game;
	REQUIRE_THROWS_AS(game.start_game("L"), Error);
}

TEST_CASE("Test set player to X")
{
	Tic_Tac_Toe_3 game;

	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}
TEST_CASE("Test set player to X 4")
{
	Tic_Tac_Toe_4 game;

	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test set player to O")
{
	Tic_Tac_Toe_3 game;

	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}
TEST_CASE("Test set player to O 4")
{
	Tic_Tac_Toe_4 game;

	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test start game with X game flow")
{
	Tic_Tac_Toe_3 game;

	game.start_game("X");
	REQUIRE(game.get_player() == "X");
	
	game.mark_board(4);
	REQUIRE(game.get_player() == "O");
}
TEST_CASE("Test start game with X game flow 4")
{
	Tic_Tac_Toe_4 game;

	game.start_game("X");
	REQUIRE(game.get_player() == "X");

	game.mark_board(4);
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test start game with O game flow")
{
	Tic_Tac_Toe_3 game;

	game.start_game("O");
	REQUIRE(game.get_player() == "O");

	game.mark_board(2);
	REQUIRE(game.get_player() == "X");
}
TEST_CASE("Test start game with O game flow 4")
{
	Tic_Tac_Toe_4 game;

	game.start_game("O");
	REQUIRE(game.get_player() == "O");

	game.mark_board(2);
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test game over when board full and if there's a tie")
{
	Tic_Tac_Toe_3 game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test Mark Position accepts values from 1 to 9 only.")
{
	Tic_Tac_Toe_3 game;
	game.start_game("X");
	REQUIRE_THROWS_AS(game.mark_board(0), Error);
	REQUIRE_THROWS_AS(game.mark_board(10), Error);
	game.mark_board(5);
}
TEST_CASE("Test Mark Position accepts values from 1 to 16 only 4.")
{
	Tic_Tac_Toe_4 game;
	game.start_game("X");
	REQUIRE_THROWS_AS(game.mark_board(0), Error);
	REQUIRE_THROWS_AS(game.mark_board(17), Error);
	game.mark_board(5);
	game.mark_board(16);
}

TEST_CASE("Test win by first column")
{
	Tic_Tac_Toe_3 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	//X wins
	REQUIRE(board.game_over() == true);
}
TEST_CASE("Test win by first column 4")
{
	Tic_Tac_Toe_4 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false); 
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(13);//X
	//X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second column")
{
	Tic_Tac_Toe_3 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//X
	//X wins
	REQUIRE(board.game_over() == true);
}
TEST_CASE("Test win by second column 4")
{
	Tic_Tac_Toe_4 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//X
	REQUIRE(board.game_over() == false); 
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(14);//X
	//X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third column")
{
	Tic_Tac_Toe_3 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	//X wins
	REQUIRE(board.game_over() == true);
}
TEST_CASE("Test win by third column 4")
{
	Tic_Tac_Toe_4 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false); 
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(15);//X
	//X wins
	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by fourth column 4")
{
	Tic_Tac_Toe_4 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(12);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//X
	//X wins
	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by first row")
{
	Tic_Tac_Toe_3 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//X
	//X wins
	REQUIRE(board.game_over() == true);
}
TEST_CASE("Test win by first row 4")
{
	Tic_Tac_Toe_4 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X
	//X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second row")
{
	Tic_Tac_Toe_3 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	//X wins
	REQUIRE(board.game_over() == true);
}
TEST_CASE("Test win by second row 4")
{
	Tic_Tac_Toe_4 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false); 
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//X
	//X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third row")
{
	Tic_Tac_Toe_3 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	//X wins
	REQUIRE(board.game_over() == true);
}
TEST_CASE("Test win by third row 4")
{
	Tic_Tac_Toe_4 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//X
	REQUIRE(board.game_over() == false); 
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(12);//X
	//X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by fourth row 4")
{
	Tic_Tac_Toe_4 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(13);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(14);//X
	REQUIRE(board.game_over() == false); 
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(15);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//X
	//X wins
	REQUIRE(board.game_over() == true);
}
TEST_CASE("Test win diagonally from top left")
{
	Tic_Tac_Toe_3 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	//X wins
	REQUIRE(board.game_over() == true);
}
TEST_CASE("Test win diagonally from top left 4")
{
	Tic_Tac_Toe_4 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false); //yo
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(12);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//X
	//X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left")
{
	Tic_Tac_Toe_3 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//X
	//X wins
	REQUIRE(board.game_over() == true);
}
TEST_CASE("Test win diagonally from bottom left 4")
{
	Tic_Tac_Toe_4 board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(13);//X
	REQUIRE(board.game_over() == false); //yo
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X
	//X wins
	REQUIRE(board.game_over() == true);
}