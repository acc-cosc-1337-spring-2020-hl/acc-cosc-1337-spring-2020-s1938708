#include<iostream>

using std::cout;

int main() 
{
	int num = 5;
	cout << "Address for num is: " << &num << "\n";

	int &num_ref = num;
	num_ref = 10;

	cout << "num is: " << num;

	return 0;
}