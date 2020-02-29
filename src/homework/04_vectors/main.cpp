#include "vectors.h"

/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
int main() 
{
	vector<int> nums{ 8, 4, 20, 88, 66, 99 };

	string choice; int option; int num = 0;

	do
	{
		cout << "The list of numbers: ";

		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << " ";
		}

		cout << "\nChoose either 1 or 2 to get the max value of a number or for the prime numbers respectively: ";
		cin >> option;

		if (option == 1)
		{
			cout << "\nThe maximum number is: " << get_max_from_vector(nums);
		}
		else if (option == 2) {
			cout << "Enter a number: ";
			cin >> num;

			vector<int> primes{vector_of_primes(num)};
			cout << "The prime numbers are: ";
			for (int i = 0; i < primes.size(); i++)
			{
				cout << primes[i] << " ";
			}

		}
		cout << "\nContinue(y)? ";
		cin >> choice;
	} while (choice == "Y" || choice == "y");
	return 0;
}