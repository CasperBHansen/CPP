/*
 * RegularTriangle.cpp
 *
 * Defines the RegularTriangle class.
 */

#include "RegularTriangle.h"

#include "math.h"

RegularTriangle::RegularTriangle(const Color<ColorType>& initialColor,
								 const Coordinate<CoordType>& position,
								 const float len)
								 : RegularPolygon(initialColor, position, 3, len)
{
	// nothing to do here, really ..
}

Coordinate<CoordType> RegularTriangle::boundingLowerLeft()
{
	return Coordinate<CoordType>();
}

Coordinate<CoordType> RegularTriangle::boundingUpperRight()
{
	return Coordinate<CoordType>();
}
