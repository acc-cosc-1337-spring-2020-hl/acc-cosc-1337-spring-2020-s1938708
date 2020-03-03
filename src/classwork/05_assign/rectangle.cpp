//Write include statement
#include "rectangle.h"


/*
Write the class function code for the Rectangle class with one constructor that accepts two int parameters (width, height),
has one public function area that returns the area of the rectangle, and one private function calculate_area
that calculates area of the rectangle.  The class has 3 int private variables area, width, and height.
*/

Rect::Rect(int w, int h) : width{ w }, height{ h } {calculate_area(); }

int Rect::get_area()const { return area; }

void Rect::calculate_area()
{
	area = width * height;
}