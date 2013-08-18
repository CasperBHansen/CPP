/*
 * Circle.h
 *
 * Declares the Circle class.
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
	Circle(const Color<ColorType>& initialColor = Color<ColorType>(),
		   const Coordinate<CoordType>& position = Coordinate<CoordType>(),
		   const float r = 1.0);
	
	virtual double area() const;
	
	virtual Coordinate<CoordType> getCenter() const;
	virtual Coordinate<CoordType> boundingLowerLeft() const;
	virtual Coordinate<CoordType> boundingUpperRight() const;

private:
	float radius;
};

#endif
