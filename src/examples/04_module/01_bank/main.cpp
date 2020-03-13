#include "checking_account.h"
#include "savings_account.h"
#include<iostream>
#include<vector>

using std::cout; using std::cin; using std::vector;
using std::reference_wrapper;

int main()
{

	SavingsAccount s(100);
	CheckingAccount c(100);

	vector<reference_wrapper<BankAccount>> acts{s, c};

	for (auto account_ref : acts)
	{
		cout << account_ref.get().get_balance() << "\n";
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