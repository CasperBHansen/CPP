/*
 * RegularPolygon.h
 *
 * Declares the RegularPolygon abstract class.
 */

#ifndef REGULAR_POLYGON_H
#define REGULAR_POLYGON_H

#include "Shape.h"

class RegularPolygon : public Shape {
public:
	RegularPolygon(const Color<ColorType>& initialColor = Color<ColorType>(),
				   const Coordinate<CoordType>& position = Coordinate<CoordType>(),
				   const unsigned int edges = 0,
				   const float length = 0);
	
	virtual double area();
	virtual Coordinate<CoordType> boundingLowerLeft() = 0;
	virtual Coordinate<CoordType> boundingUpperRight() = 0;

private:
	unsigned int n;
	float length;
};

#endif
