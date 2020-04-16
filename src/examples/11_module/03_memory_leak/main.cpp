#include "memory_leak.h"

int main() 
{
	//has lots of code

	//call function 1 time
	memory_leak();

	//call function in a loop
	while (true)
	{
		memory_leak();
	}
	
	return 0;
}