/*
 * Line.cpp
 *
 * Defines the Line class.
 */

#include "Line.h"

#include <string>
using std::string;

#include "math.h"

Line::Line(const Color<ColorType>& initialColor,
		   const Coordinate<CoordType>& position,
		   const Coordinate<CoordType>& a,
		   const Coordinate<CoordType>& b)
		   : Shape(initialColor, position)
{
	type = string("Line");
	
	origin = a;
	end = b;
}

double Line::area() const
{
	// a line has no definable area, hence we simply return zero
	return 0.0;
}

Coordinate<CoordType> Line::getCenter() const
{
	return Coordinate<CoordType>( (origin.x + end.x) / 2.0 , (origin.y + end.y) / 2.0 );
}

Coordinate<CoordType> Line::boundingLowerLeft() const
{
	Coordinate<CoordType> ret;
	ret.x = min( origin.x, end.x );
	ret.y = min( origin.y, end.y );
	return ret + position;
}

Coordinate<CoordType> Line::boundingUpperRight() const
{
	Coordinate<CoordType> ret;
	ret.x = max( origin.x, end.x );
	ret.y = max( origin.y, end.y );
	return ret + position;
}

