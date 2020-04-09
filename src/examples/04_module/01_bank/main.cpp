#include "atm.h"
#include "checking_account.h"
#include "savings_account.h"
#include<iostream>
#include<vector>
#include<memory>

using std::cout; using std::cin; using std::vector;
using std::unique_ptr; using std::make_unique;

int main()
{   
	
	/*CheckingAccount b1;
	//C++ 98
	BankAccount* z = new SavingsAccount(100);
	//more code here
	delete z;

	//C++ 11
	//declare uniqueptr			create the instance w make unique*/

	unique_ptr<BankAccount> s = make_unique<SavingsAccount>(100);
	unique_ptr<CheckingAccount> c= make_unique<CheckingAccount>(100);

	vector<unique_ptr<BankAccount>> acts; // {std::move(s), std::move(c)};
	acts.push_back(std::move(s));
	acts.push_back(std::move(c));

	Customer cust(acts);
	ATM atm(cust);
	//some interaction
	cout << atm;

	/*for (auto &account : acts)
	{
		cout << account->get_balance() << "\n";
	}*/

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

	/*int num = 5;
	int& num_ref = num;
	std::cout << "\nAddress: " << &num_ref;
	std::cout << "\nValue at above address: " << num_ref;
	num_ref = 10;
	std::cout << "\nValue at above address: " << num_ref;
	std::cout << "\nNum value: " << num;

	int* val_ = &num_ref;
	std::cout << "\nAddress pointed to: " << val_;
	std::cout << "\nValue pointed to: " << *val_;
	*val_ = 15;
	std::cout << "\nValue pointed to: " << *val_;
	std::cout << "\nNum value: " << num;*/
	return 0;
}