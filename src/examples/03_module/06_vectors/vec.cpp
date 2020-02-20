#include<iostream>
#include<vector>
#include "vec.h"

using std::vector;

/*
Write code for function loop_vector_w_index with no parameters.
The function creates an int vector with values 9, 10, 99, 5, 67
and displays the numbers to screen using an indexed for loop as follows: 9 10 99 5  67
*/
void loop_vector_w_index(vector<int> nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << "\n";
		nums[i] = 0;
	}
}

/*
Write code for function loop_vector_w_index with a vector of int pass by value parameter.
The function creates an int vector with values 9, 10, 99, 5, 67
and displays the numbers to screen using an indexed for loop as follows: 9 10 99 5  67
*/

void loop_vector_w_index_ref(vector<int>& nums)
{
	for (auto &n : nums)
	{
		cout << n << "\n";
		n = 0;
	}
}


/*
Write code for function loop_vector_w_index with a vector of int pass by reference parameter.
The function creates an int vector with values 9, 10, 99, 5, 67
and displays the numbers to screen using an indexed for loop as follows : 9 10 99 5  67
*/
void loop_vector_w_index_const(const vector<int>& nums)
{
	for (auto n : nums)
	{
		cout << n << "\n";
	}
}




/*
Write code for function loop_vector_w_index with a vector of int const pass by reference parameter.
The function creates an int vector with values 9, 10, 99, 5, 67
and displays the numbers to screen using an indexed for loop as follows : 9 10 99 5  67
*/


