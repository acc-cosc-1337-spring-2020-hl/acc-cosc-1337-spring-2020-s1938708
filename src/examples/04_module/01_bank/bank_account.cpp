//bank_account.cpp
#include "bank_account.h"


using std::cout;

void BankAccount::deposit(int amount)
{
	if (amount > 0)
	{
		balance += amount;
	}
	else
	{
		//usually write to a file
		throw InvalidAmount("\nAmount must be greater than zero.");
	}
}

void BankAccount::withdraw(int amount)
{
	if (amount <= 0)
	{
		throw InvalidAmount("\nAmount must be greater than zero.");
	}
	else if(balance - amount < 0)
	{
		throw InvalidAmount("\nAmount must not be greater than amount.");
	}
	else
	{
		//usually write to a file
		balance -= amount;
	}
}

void BankAccount::open(int amount)
{
	if (balance > 0)
	{
		throw InvalidAmount("Account already open, use deposit.");
	}

	if (amount >= min_balance_to_open)
	{
		balance += amount;
	}
	else
	{
		throw InvalidAmount("A deposit of at least $25 is needed.");
	}
}

double BankAccount::rate = init_rate();

void display_balance(const BankAccount & b)
{
	cout << "Balance is: " << b.balance << "\n";
}

std::ostream & operator<<(std::ostream & out, const BankAccount & b)
{
	out << "Balance is: " << b.balance << "\n";

	return out;
}

std::istream & operator>>(std::istream & in, BankAccount & b)
{
	int amount;
	cout << "Enter deposit: ";
	in >> amount;
	b.deposit(amount);
	return in;
}
