//
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

class Vector
{
public:
	Vector(size_t sz);
	Vector(const Vector& v); //copy constructor-RULE of 3
	Vector& operator=(const Vector& v);//copy assignment-RULE OF 3
	size_t Size()const { return size; }
	int& operator[](int i) { return nums[i]; }
	int& operator[](int i) const { return nums[i]; }
	~Vector();//destructor-RULE of 3
private:
	size_t size;
	int* nums;
};
#endif

void use_vector();