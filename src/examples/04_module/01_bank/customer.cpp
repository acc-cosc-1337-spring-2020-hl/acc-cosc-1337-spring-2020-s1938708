//customer.cpp
#include "customer.h"

std::ostream& operator<<(std::ostream& out, const Customer& c)
{
	for (auto& bank_account : c.accounts)
	{
		out << "Balance: " << *bank_account << "\n";
	}

	return out;
}