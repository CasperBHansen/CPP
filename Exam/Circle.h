/*
 * Circle.h
 *
 * Declares the Circle class.
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

template <class CoordType, class ColorType>
class Circle : public Shape<CoordType, ColorType> {
public:
	Circle(const Color<ColorType>& initialColor = Color<ColorType>(),
		   const Coordinate<CoordType>& position = Coordinate<CoordType>(),
		   const float r = 1.0)
	: Shape<CoordType, ColorType>(initialColor, position)
	{
		this->type = std::string("Circle");
		radius = r;
	}
	
	virtual double area() const { return MATH_PI * radius * radius; }
	
	virtual Coordinate<CoordType> getCenter() const { return this->position; }
	virtual Coordinate<CoordType> boundingLowerLeft() const
	{
		return Coordinate<CoordType>(this->position.x - radius, this->position.y - radius) + this->position;
	}

	virtual Coordinate<CoordType> boundingUpperRight() const
	{
		return Coordinate<CoordType>(this->position.x + radius, this->position.y + radius) + this->position;
	}

private:
	float radius;
};

#endif
