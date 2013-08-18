/*
 * Line.h
 *
 * Declares the Line class, which represents a 2D line.
 */

#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
public:
	Line(const Color<ColorType>& initialColor = Color<ColorType>(),
		 const Coordinate<CoordType>& position = Coordinate<CoordType>(),
		 const Coordinate<CoordType>& a = Coordinate<CoordType>(),
		 const Coordinate<CoordType>& b = Coordinate<CoordType>());
	
	virtual double area() const;
	
	virtual Coordinate<CoordType> getCenter() const;
	virtual Coordinate<CoordType> boundingLowerLeft() const;
	virtual Coordinate<CoordType> boundingUpperRight() const;

private:
	Coordinate<CoordType> origin, end;
};

#endif
