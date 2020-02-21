//write includes statements
#include "loops.h"
#include<iostream>


//write using statements for cin and cout

using std::cin; using std::cout;


/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	int choice;

	do
	{
		int num;
		cout << "Enter a number for factorial calculation: ";
		cin >> num;
		cout << "\nThe factorial of "<< num<< " is: "<< factorial(num);
		cout << "\nContinue? (1=Y, 0=N)";
		cin >> choice;
	} while (choice == 1);
	return 0;
}