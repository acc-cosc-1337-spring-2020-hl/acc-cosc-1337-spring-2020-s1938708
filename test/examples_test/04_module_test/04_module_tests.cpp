#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include<memory>
#include "checking_account.h"
#include "savings_account.h"

using std::unique_ptr; using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test Bank Account get_balance")
{
	CheckingAccount account(150);

	REQUIRE(account.get_balance() == 150);
}

TEST_CASE("Test Savings Account deposit")
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>(150);

	REQUIRE(account->get_balance() == 150);

	REQUIRE_THROWS_AS(account->deposit(-50), InvalidAmount);

	account->deposit(50);

	REQUIRE(account->get_balance() == 200);
}

TEST_CASE("Test Bank Account withdraw")
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>(150);

	REQUIRE(account->get_balance() == 150);

	REQUIRE_THROWS_AS(account->withdraw(-5), InvalidAmount);

	REQUIRE(account->get_balance() == 150);

	account->withdraw(50);

	REQUIRE(account->get_balance() == 100);

	REQUIRE_THROWS_AS(account->withdraw(101), InvalidAmount);

	REQUIRE(account->get_balance() == 100);
}

TEST_CASE("Test default constructor for balance eq 0")
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>(150);
	REQUIRE(account->get_balance() == 0);
}

TEST_CASE("Test default constructor open account")
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>(150);
	REQUIRE(account->get_balance() == 0);

	account->open(25);
	REQUIRE(account->get_balance() == 25);
}

TEST_CASE("Test default constructor account already open.")
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>(150);
	REQUIRE_THROWS_AS(account->open(25), InvalidAmount);
}

TEST_CASE("Test default constructor open account with less $25.")
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>(150);
	REQUIRE_THROWS_AS(account->open(21), InvalidAmount);
}

TEST_CASE("Test bank account get rate.")
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>(150);
	REQUIRE(account->get_rate() == .025);
}