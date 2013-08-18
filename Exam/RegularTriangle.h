/*
 * RegularTriangle.h
 *
 * Declares the RegularTriangle class.
 */

#ifndef REGULAR_TRIANGLE_H
#define REGULAR_TRIANGLE_H

#include "RegularPolygon.h"

class RegularTriangle : public RegularPolygon {
public:
	RegularTriangle(const Color<ColorType>& initialColor = Color<ColorType>(),
					const Coordinate<CoordType>& position = Coordinate<CoordType>(),
					const float length = 1.0);
	
	virtual Coordinate<CoordType> boundingLowerLeft();
	virtual Coordinate<CoordType> boundingUpperRight();

private:
};

#endif // REGULAR_TRIANGLE_H
