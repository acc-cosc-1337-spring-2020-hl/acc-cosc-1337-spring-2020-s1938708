#include "checking_account.h"
#include "savings_account.h"
#include<iostream>
#include<vector>
#include<memory>

using std::cout; using std::cin; using std::vector;
using std::unique_ptr; using std::make_unique;

int main()
{   //C++ 98
	BankAccount* z = new BankAccount(100);
	//more code here
	delete z;

	//C++ 11
	//declare uniqueptr			create the instance w make unique
	unique_ptr<BankAccount> s = make_unique<SavingsAccount>(100);
	unique_ptr<CheckingAccount> c= make_unique<CheckingAccount>(100);

	vector<unique_ptr<BankAccount>> acts; // {std::move(s), std::move(c)};
	acts.push_back(std::move(s));
	acts.push_back(std::move(c));

	for (auto &account : acts)
	{
		cout << account->get_balance() << "\n";
	}

	/*CheckingAccount c;
	CheckingAccount a(50), b(10);
	//BankAccount c = a + b;
	display_balance(a);
	cin >> a;
	cout << a;
	

	vector<BankAccount> accounts{ BankAccount(100), BankAccount(200), BankAccount(300) };

	for (auto act : accounts)
	{
		cout << act.get_balance() << "\n";
	}

	BankAccount account(500);
	int balance = account.get_balance();
	cout << "\nBalance: " << balance;

	try
	{
		account.deposit(-10);
	}
	catch (InvalidAmount e)
	{
		cout << e.get_message();
	} */
	return 0;
}