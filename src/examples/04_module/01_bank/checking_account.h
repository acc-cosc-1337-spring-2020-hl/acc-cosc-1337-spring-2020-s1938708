#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "bank_account.h"
//checking_account.h
class CheckingAccount : public BankAccount
{
public:
	CheckingAccount() = default;
	explicit CheckingAccount(int b) : BankAccount(b) {}
	int get_balance()const { return balance * (1 + get_rate()); }
private:

};
#endif // !CHECKING_ACCOUNT_H