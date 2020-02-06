#include "decision.h"
//Write the function code that returns the product of hours and hourly_rate.

double gross_pay(double hours, double hourly_rate)
{

	double gross_pay;

	if (hours >= 40)
	{
		double overtime_hours = (hours - 40) * 1.5;

		double overtime_hourly_rate = hourly_rate * overtime_hours;
		
		return gross_pay = (hours*hourly_rate) + overtime_hourly_rate;
	}

	else
	{
		return gross_pay = hours * hourly_rate;
	}
	
}
