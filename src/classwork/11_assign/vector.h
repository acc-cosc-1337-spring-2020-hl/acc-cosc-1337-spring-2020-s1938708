//
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

class Vector
{
public:
	Vector(size_t sz);
	Vector(const Vector& v); //copy constructor-RULE of 3 c++98
	Vector& operator=(const Vector& v);//copy assignment-RULE OF 3 c++98
	Vector (Vector&& v); //move constructor Rule of 5 - c++11
	Vector& operator=(Vector&& v);//move assignment Rule of 5 - c++11
	size_t Size()const { return size; }
	int& operator[](int i) { return nums[i]; }
	int& operator[](int i) const { return nums[i]; }
	~Vector();//destructor-RULE of 3 c++ 98
private:
	size_t size;
	int* nums;
};
#endif

void use_vector();

Vector get_vector();