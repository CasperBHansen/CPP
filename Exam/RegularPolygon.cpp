/*
 * RegularPolygon.cpp
 *
 * Defines the RegularPolygon abstract class.
 */

#include "RegularPolygon.h"

#include <math.h>

RegularPolygon::RegularPolygon(const Color<ColorType>& initialColor,
							   const Coordinate<CoordType>& position,
							   const unsigned int edges,
							   const float len)
							   : Shape(initialColor, position)
{
	n = edges;
	length = len;
}

double RegularPolygon::area()
{
	return 0.25 * n * length * length * tan( 1 / (M_PI/n) );
}
