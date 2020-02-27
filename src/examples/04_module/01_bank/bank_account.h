//bank_account.h
#include<string>
class BankAccount
{
public:
	BankAccount(int b) : balance{ b } {};
	int get_balance()const { return balance; }
	void deposit(int amount);
	void withdraw(int amount);
private:
	int balance;
};

class InvalidAmount
{
public:
	InvalidAmount(std::string msg) : message{ msg } {};
	std::string get_message()const { return message; }
private:
	std::string message;
};