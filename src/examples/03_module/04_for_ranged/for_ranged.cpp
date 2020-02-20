#include "for_ranged.h"

/*
Write code for loop_string_w_index that accepts a string parameter.
The function uses an indexed for loop to iterate and display the characters in the
string as follows:
for string test displays

t
e
s
t
*/

void loop_string_w_index(const string & str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		cout << str[i] << "\n";
	}
}


/*
Write code for loop_string_w_index that accepts a string parameter.
The function uses a for ranged loop using auto to iterate and display the characters in the
string as follows:
for string test displays

t
e
s
t
*/


void loop_string_w_auto(const string & str)
{
	for (auto s : str)
	{
		cout << s << "\n";
		s = 'z';
	}
}

void loop_string_w_auto_ref(string &str)
{
	for (auto &s : str)
	{
		cout << s << "\n";
		s = 'z';
	}

}