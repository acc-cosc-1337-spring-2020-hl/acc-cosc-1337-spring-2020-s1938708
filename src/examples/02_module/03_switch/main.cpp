#include<iostream>
#include"switch.h"

using std::cout; using std::cin;

int main() 
{
	int option;

	cout << "Enter a number (1-4): ";
	cin >> option;

	string result = menu(option);

	cout << result;

	return 0;
}