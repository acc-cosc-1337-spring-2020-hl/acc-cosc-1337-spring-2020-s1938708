#include<iostream>

using std::cout;
int main() 
{
	int* ptr_num = new int(5); //declare and aquire new memory(heap)

	cout << &ptr_num << "\n";//displays the address where ptr_num is stored
	cout << ptr_num << "\n";//address where 5 is stored
	cout << *ptr_num; //displays the value of ptr_num

	delete ptr_num;
	ptr_num = nullptr;

	return 0;
}