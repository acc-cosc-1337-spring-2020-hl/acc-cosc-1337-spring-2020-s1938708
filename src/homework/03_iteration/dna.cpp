#include "dna.h"

/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/

double get_gc_content(const string& dna)
{

	double gc_count = 0; double gc_percent = 0;

	for (int i = 0; i <= dna.length(); i++)
	{
		if (dna[i] == 'G' || dna[i] == 'C')
		{
			gc_count ++;
		}
	}

	return gc_percent = gc_count / dna.length();
}


/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string dna)
{

	string reverse_dna;
	for (int i = dna.length()-1; i >= 0; i--)
	{
		reverse_dna += dna[i];
	}

	return reverse_dna;
}


/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/

string get_dna_compliment(string dna)
{
	string rv_dna = get_reverse_string(dna);

	string dna_compliment;

	for (int i = 0; i <= rv_dna.length(); i++)
	{
		if (rv_dna[i] == 'A')
		{
			dna_compliment += "T";
		}
		else if (rv_dna[i] == 'T')
		{
			dna_compliment += 'A';
		}
		else if (rv_dna[i] == 'C')
		{
			dna_compliment += 'G';
		}
		else if (rv_dna[i] == 'G')
		{
			dna_compliment += 'C';
		}
	}

	return dna_compliment;
}
