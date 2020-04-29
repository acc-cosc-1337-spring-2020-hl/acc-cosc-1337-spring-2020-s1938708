#include "vector.h"
#include<iostream>

/*
Allocated dynamic memory for an array of sz(size) elements
Initialized all of the array elements to 0
*/
Vector::Vector(size_t sz) 
	: size{ sz }, nums{new int[sz]}
{
	std::cout << "Allocate memory";
	for (size_t i = 0; i < sz; i++)
	{
		nums[i] = 0;
	}
}

/*
Set the new class size to the right-hand operand array size
Allocated a dynamic array of size elements
Initialized all the elements to the value of the right-hand operand(value)
*/
Vector::Vector(const Vector& v)
	: size{v.size}, nums{new int[v.size]}
{
	for (size_t i = 0; i < size; ++i)
	{
		nums[i] = v[i]; 
	}
}

/*
Allocated temporary memory of right-hand operand size
Initialized all temp elements to right-hand operand elements' value
Deallocated created memory of this class
Copied temporary memory to this class (nums)
Return a dereferenced instance of this class.
*/
Vector& Vector::operator=(const Vector& v)
{
	int* temp = new int[v.size];

	for (size_t i = 0; i < v.size; ++i)
	{
		temp[i] = v[i];
	}
	delete[] nums;

	nums = temp;
	size = v.size;

	return *this;
}

/*
Get the dynamic memory from v
Get the size from v
Point the v.nums to nullptr
*/
Vector::Vector(Vector&& v)
	:size{ v.size }, nums{ v.nums }
{
	v.size = 0;
	v.nums = nullptr;
}

/*
Deallocate original dynamic memory
Get the dynamic memory from v 
Get the size from v
Point v.nums to nullptr
Set v.size to 0;
*/
Vector& Vector::operator=(Vector&& v)
{
	delete nums;
	nums = v.nums;
	size = v.size;
	v.nums = nullptr;
	v.size = 0;

	return *this;
}

Vector::~Vector()
{
	std::cout << "\nRelease Memory";
	delete[] nums;
}

void use_vector()
{
	Vector* v1 = new Vector(3);
	delete v1;
	v1 = nullptr;
}

Vector get_vector()
{
	Vector v(3);

	return v;
}
