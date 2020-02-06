#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "loops.h"
#include "decision.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test for gross pay")
{
	REQUIRE(gross_pay(10, 15) == 150);
	REQUIRE(gross_pay(5, 20) == 100);
	REQUIRE(gross_pay(20, 10) == 200);
	REQUIRE(gross_pay(45, 15) == 787.5);
}