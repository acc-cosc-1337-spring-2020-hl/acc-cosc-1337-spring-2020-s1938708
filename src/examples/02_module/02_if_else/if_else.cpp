#include "if_else.h"
//write include statement for if_else header file

//write code for function named get_generation that accepts an int year and returns
//a string, apply the following logic:
//return "Centenial" when year greater than equal to 1996 to 2014
//return "Millenial" when year greater than equal to 1977 to 1995
//return "Generation X" when year greater than equal to 1965 to 1976
//return "Baby boomer" when year greater than equal to 1946 to 1964
//return "Silent Generation" when year greater than equal 1925 and less than equal 1945
//return "Invalid Year" otherwise

string get_generation(int gen)
{
	if (gen >= 1996 && gen <= 2014)
	{
		return "Centennial";
	}
	else if (gen >= 1977 && gen <= 1995)
	{
		return "Millenial";
	}
	else if (gen >= 1965 && gen <= 1976)
	{
		return "Generation X";
	}
	else if (gen >= 1946 && gen <= 1964)
	{
		return "Baby Boomer";
	}
	else if (gen >= 1925 && gen <= 1945)
	{
		return "Silent Generation";
	}
	else
	{
		return "Invalid";
	}

	return "";
}
