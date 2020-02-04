#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "if.h"
#include "if_else.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test is an even function")
{
	REQUIRE(is_even(2) == true);
	REQUIRE(is_even(3) == false);
}

TEST_CASE("Test get generation function")
{
	REQUIRE(get_generation(1997) == "Centennial");
	REQUIRE(get_generation(1995) == "Millenial");
	REQUIRE(get_generation(1976) == "Generation X");
	REQUIRE(get_generation(1964) == "Baby Boomer");
	REQUIRE(get_generation(1945) == "Silent Generation");
	REQUIRE(get_generation(2016) == "Invalid");
}