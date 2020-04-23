#include "dangling_pointer.h"
#include <iostream>

int main() 
{
	int* ptr_num = new int(5);
	int* ptr = ptr_num;
	std::cout << *ptr << "\n";
	delete ptr_num;
	//delete ptr; //Needed to remove the dangling ptr.
	std::cout << *ptr;
	ptr_num = nullptr;
	return 0;
}