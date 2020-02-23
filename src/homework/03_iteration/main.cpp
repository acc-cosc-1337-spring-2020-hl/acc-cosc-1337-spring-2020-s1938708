//write include statements
#include "dna.h"
#include<iostream>

//write using statements
using std::cout; using std::cin;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	string choice; int option;

	do
	{
		string dna;
		cout << "Choose a number to perform an action.";
		cout << "\n1.) The GC content.\n2.) The DNA compliment.\nOption: ";
		cin >> option;
		cout << "\nEnter the DNA sequence: ";
		cin >> dna;

		if (option == 1)
		{
			cout << "\n" << get_gc_content(dna);
		}
		else if (option == 2) {
			cout << "\n" << get_dna_compliment(dna);
		}

		cout << "\nContinue? (Y/N): ";
		cin >> choice;
	} while (choice == "Y" || choice == "y");

	return 0;
}