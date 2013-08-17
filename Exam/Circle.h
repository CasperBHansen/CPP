/*
 * Circle.h
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:

	double area();
	Coordinate<int> boundingLowerLeft();
	Coordinate<int> boundingUpperRight();
};

#endif // CIRCLE_H