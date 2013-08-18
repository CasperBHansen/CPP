/*
 * Triangle.h
 *
 * Declares the Triangle class.
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle(const Color<ColorType>& initialColor = Color<ColorType>(),
			 const Coordinate<CoordType>& position = Coordinate<CoordType>(),
			 const Coordinate<CoordType>& s = Coordinate<CoordType>(),
			 const Coordinate<CoordType>& t = Coordinate<CoordType>(),
			 const Coordinate<CoordType>& u = Coordinate<CoordType>());
	
	virtual double area() const;

	virtual Coordinate<CoordType> getCenter() const;
	virtual Coordinate<CoordType> boundingLowerLeft();
	virtual Coordinate<CoordType> boundingUpperRight();

private:
	Coordinate<CoordType> a, b, c;
};

#endif
