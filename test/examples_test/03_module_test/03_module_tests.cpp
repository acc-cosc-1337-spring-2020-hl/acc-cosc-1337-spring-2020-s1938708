#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "while.h"
#include "for_ranged.h"
#include "value_ref.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test sum of squares function")
{
	REQUIRE(sum_of_squares(3) == 14);
	REQUIRE(sum_of_squares(4) == 30);
	REQUIRE(sum_of_squares(5) == 55);
}

TEST_CASE("Test for ranged loop by value")
{
	string name = "Joe";
	loop_string_w_auto(name);

	REQUIRE(name == "Joe");
}

TEST_CASE("Test for ranged loop by reference")
{
	string name = "Joe";
	loop_string_w_auto_ref(name);

	REQUIRE(name == "zzz");
}