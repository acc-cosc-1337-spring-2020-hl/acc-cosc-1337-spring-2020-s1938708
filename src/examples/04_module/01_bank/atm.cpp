//atm.cpp
#include "atm.h"

std::ostream& operator<<(std::ostream& out, const ATM& a)
{
	out << a.customer;

	return out;
}