#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test can't call mark board before start game")
{
	TicTacToe game;
	REQUIRE_THROWS_AS(game.mark_board(1), Error);
}

TEST_CASE("Test start game only accepts X or O")
{
	TicTacToe game;
	REQUIRE_THROWS_AS(game.start_game("L"), Error);
}

TEST_CASE("Test set player to X")
{
	TicTacToe game;

	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test set player to O")
{
	TicTacToe game;

	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test start game with X game flow")
{
	TicTacToe game;

	game.start_game("X");
	REQUIRE(game.get_player() == "X");
	
	game.mark_board(4);
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test start game with O game flow")
{
	TicTacToe game;

	game.start_game("O");
	REQUIRE(game.get_player() == "O");

	game.mark_board(2);
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test game over when board full")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test display board function")
{

}