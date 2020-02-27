#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "bank_account.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test Bank Account get_balance")
{
	BankAccount account(150);

	REQUIRE(account.get_balance() == 150);
}

TEST_CASE("Test Bank Account deposit")
{
	BankAccount account(150);

	REQUIRE(account.get_balance() == 150);

	REQUIRE_THROWS_AS(account.deposit(-50), InvalidAmount);

	account.deposit(50);

	REQUIRE(account.get_balance() == 200);
}

TEST_CASE("Test Bank Account withdraw")
{
	BankAccount account(150);

	REQUIRE(account.get_balance() == 150);

	REQUIRE_THROWS_AS(account.withdraw(-5), InvalidAmount);

	REQUIRE(account.get_balance() == 150);

	account.withdraw(50);

	REQUIRE(account.get_balance() == 100);

	REQUIRE_THROWS_AS(account.withdraw(101), InvalidAmount);

	REQUIRE(account.get_balance() == 100);
}