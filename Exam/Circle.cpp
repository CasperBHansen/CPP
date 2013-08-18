/*
 * Circle.cpp
 *
 * Defines the Circle class.
 */

#include "Circle.h"

#include <string>
using std::string;

#include <math.h>

#include "math.h"

Circle::Circle(const Color<ColorType>& initialColor,
			   const Coordinate<CoordType>& position,
			   const float r)
			   : Shape(initialColor, position)
{
	type = string("Circle");
	
	radius = r;
}

double Circle::area() const
{
	return M_PI * radius * radius;
}

Coordinate<CoordType> Circle::getCenter() const
{
	return position;
}

Coordinate<CoordType> Circle::boundingLowerLeft() const
{
	return Coordinate<CoordType>(center.x - radius, center.y - radius) + position;
}

Coordinate<CoordType> Circle::boundingUpperRight() const
{
	return Coordinate<CoordType>(center.x + radius, center.y + radius) + position;
}

