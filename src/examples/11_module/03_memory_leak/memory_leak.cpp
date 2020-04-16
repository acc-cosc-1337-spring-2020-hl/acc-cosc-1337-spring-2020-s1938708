#include "memory_leak.h"

void memory_leak()
{
	int* ptr_num = new int(5);
	//some other function code

	//we forget to delete and point to nullptr
}