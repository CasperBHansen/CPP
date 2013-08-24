/*
 * main.cpp
 *
 * This is the main program. It tests the solution by assertions.
 * For additional debug information #define DEBUG.
 */

// #define DEBUG

#include <iostream>
using std::cout;
using std::endl;

#include <cassert>
#include <stdexcept>
using std::exception;

#ifdef __GXX_EXPERIMENTAL_CXX0X__
	// requires -std=c++11 flag
	#include <cstdint>
	typedef float COORD_TYPE;
	typedef uint8_t COLOR_TYPE;
#else
	typedef float COORD_TYPE;
	typedef short COLOR_TYPE;
#endif

#include "shapes.h"

int main(int argc, char * argv[]) {
	
	cout << "Hello, Shapes!" << endl;

	// lines
	Line<COORD_TYPE, COLOR_TYPE>
		l1(red, origo, Coordinate<COORD_TYPE>(0.0, 0.0), Coordinate<COORD_TYPE>(0.0, 0.0)),	// a point
		l2(red, origo, Coordinate<COORD_TYPE>(-1.0, -1.0), Coordinate<COORD_TYPE>(1.0, 1.0)),
		l3(green, origo, Coordinate<COORD_TYPE>(-1.0, 1.0), Coordinate<COORD_TYPE>(1.0, -1.0));
	
	// circles
	Circle<COORD_TYPE, COLOR_TYPE>
		c1(red, origo, 1.0),
		c2(green, origo, 2.0),
		c3(blue, Coordinate<COORD_TYPE>(2.5, 2.5), 2.5);
	
	// triangles
	Triangle<COORD_TYPE, COLOR_TYPE>
		t1(red, origo, origo, Coordinate<COORD_TYPE>(3.0, 0.0), Coordinate<COORD_TYPE>(0.0, -4.0)),
		t2(green, Coordinate<COORD_TYPE>(0.0, -1.0), Coordinate<COORD_TYPE>(-1.0, 0.0), Coordinate<COORD_TYPE>(0.0, 1.0), Coordinate<COORD_TYPE>(0.0, 2.0));
	
	// rectangles
	Rectangle<COORD_TYPE, COLOR_TYPE>
		r1(red, Coordinate<COORD_TYPE>(0.0, 0.0)),
		r2(green, Coordinate<COORD_TYPE>(1.0, 0.0)),
		r3(blue, Coordinate<COORD_TYPE>(-1.5, -1.5), 2.0, 2.0);
	
	/* testing.. 1.. 2..
	 *
	 * NOTE:	Changing the coord type to int will cause some assertions to fail.
	 * 			Also, if these assertions hold, then it implies than any class methods used does too.
	 */
	cout << "Testing areaCompare(a, b)..\t";
	assert( areaCompare(l2, c1) == true );			// a line has no area
	assert( areaCompare(r1, r1) == false );			// cannot be smaller than itself
	assert( areaCompare(r1, r2) == false );			// same size comparison
	assert( areaCompare(c1, t1) == true );			// unit circle with less area than triangle
	assert( areaCompare(t1, c2) == true ); 			// triangle with less area than larger circle
	cout << "Passed!" << endl;

	cout << "Testing intersect(a, b)..\t";
	assert( intersect(l1, l1) == false );			// a point has no definable size, and thus cannot intersect another point
	assert( intersect(l1, c2) == true );			// however, a point can intersect a shape
	assert( intersect(t1, l1) == true );			// and vice versa
	assert( intersect(r1, r1) == true );			// intersects itself
	assert( intersect(r1, r2) == false );			// share an edge
	assert( intersect(r1, r3) == false );			// share a point
	cout << "Passed!" << endl;

	cout << "Testing intersectByColor(a, b)..\t";
	assert( intersectByColor(r1, r1) == true );		// intersects itself
	assert( intersectByColor(l2, c1) == true ); 	// red line crossing a red circle
	assert( intersectByColor(c1, l3) == false ); 	// green line crossing a red circle
	cout << "Passed!" << endl;

	return 0;
}
