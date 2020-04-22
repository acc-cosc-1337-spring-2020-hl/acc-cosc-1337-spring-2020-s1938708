#include "vector.h"
#include<iostream>
Vector::Vector(size_t sz) 
	: size{ sz }, nums{new int[sz]}
{
	std::cout << "Allocate memory";
	for (size_t i = 0; i < sz; i++)
	{
		nums[i] = 0;
	}
}

Vector::Vector(const Vector& v)
	: size{v.size}, nums{new int[v.size]}
{
	for (size_t i = 0; i < size; ++i)
	{
		nums[i] = v[i]; 
	}
}

Vector::~Vector()
{
	std::cout << "\nRelease Memory";
	delete[] nums;
}

void use_vector()
{
	Vector v(3);
}
