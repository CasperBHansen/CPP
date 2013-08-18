/*
 * Triangle.cpp
 *
 * Defines the Triangle class.
 */

#include "Triangle.h"

#include <string>
using std::string;

#include "math.h"

Triangle::Triangle(const Color<ColorType>& initialColor,
				   const Coordinate<CoordType>& position,
				   const Coordinate<CoordType>& s,
				   const Coordinate<CoordType>& t,
				   const Coordinate<CoordType>& u)
				   : Shape(initialColor, position)
{
	type = string("Triangle");
	
	a = s;
	b = t;
	c = u;
}

double Triangle::area() const
{
	return 0.5 * ( crossProduct(b-a, c-a) );
}

Coordinate<CoordType> Triangle::getCenter() const
{
	return Coordinate<CoordType>( (a.x + b.x + c.x) / 3.0 , (a.y + b.y + c.y) / 3.0 );
}

Coordinate<CoordType> Triangle::boundingLowerLeft()
{
	return Coordinate<CoordType>();
}

Coordinate<CoordType> Triangle::boundingUpperRight()
{
	return Coordinate<CoordType>();
}

