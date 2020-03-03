//bank_account.h
#include<string>
class BankAccount
{
public:
	BankAccount() = default;
	explicit BankAccount(int b) : balance{ b } {};
	int get_balance()const { return balance; }
	void deposit(int amount);
	void withdraw(int amount);
	void open(int amount);
private:
	int balance{ 0 };
	const int min_balance_to_open{ 25 };
};

class InvalidAmount
{
public:
	InvalidAmount(std::string msg) : message{ msg } {};
	std::string get_message()const { return message; }
private:
	std::string message;
};