#include "vector.h"
#include<iostream>


int main() 
{
	/*Vector v1(3);
	Vector v2(3);
	v2 = v1;*/

	//lvalue-can reference or has an address that is accessible
	int num = 5; //5 is an rvalue
	int& num_ref = num;// right here accessible
	//rvalue
	int&& num_5 = 5;
	int a = 1, b = 5, c;
	c = a * b; //a*b is an rvalue
	//(a * b) = c;

	Vector v1(3);
	v1 = get_vector();

	return 0;
}
