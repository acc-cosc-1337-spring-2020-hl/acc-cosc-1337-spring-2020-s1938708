//Write include statement
#include "rectangle.h"


/*
Write the class function code for the Rectangle class with one constructor that accepts two int parameters (width, height),
has one public function area that returns the area of the rectangle, and one private function calculate_area
that calculates area of the rectangle.  The class has 3 int private variables area, width, and height.
*/

int get_area()
{
	calculate_area();
}

int calculate_area(int w, int h)
{
	int area = w * h;

	return area;

}