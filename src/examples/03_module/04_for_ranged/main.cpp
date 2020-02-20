#include "for_ranged.h"

int main() 
{
	string str = "john";
	loop_string_w_index(str);
	loop_string_w_auto(str);
	loop_string_w_auto_ref(str);

	return 0;
}