#include "loops.h"

/*
WITH LOOP OF YOUR CHOICE:
Write code for function factorial that accepts an int num
and returns the num's factorial

factorial(5);
1*2*3*4*5

returns 120

DON'T FORGET TO WRITE TEST CASE.  See file loop_test.cpp
*/

int factorial(int num)
{

	int fact_prog = 0; int total = 0;

	for (int i = 0; i <= num; i++)
	{
		fact_prog *= i;

		total = fact_prog;

		if (fact_prog == 0)
		{
			fact_prog++;
		}
	}

	return total;
}