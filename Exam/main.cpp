/*
 * main.cpp
 *
 * This is the main program.
 */

#define DEBUG

#include <iostream>

// math and template functions
#include "math.h"

// shapes
#include "Line.h"
#include "Circle.h"
#include "Triangle.h"

int main(int argc, char * argv[]) {

	std::cout << "Hello, Shapes!" << std::endl;
	
	Color<ColorType> color(255, 0, 0);
	Coordinate<CoordType> zero(0.0, 0.0), a(1.0, 1.0), b(2.0, 2.0);
	
	Line line(color, a, a, b);
	std::cout << line << " area: " << line.area() << std::endl;
	
	Circle circle(color, zero, 1.0);
	std::cout << circle << " area: " << circle.area() << std::endl;
	
	std::cout << intersect(line, circle) << std::endl;
	
	return 0;
}
