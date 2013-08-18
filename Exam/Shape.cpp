/*
 * Shape.cpp
 *
 * Defines the base Shape class.
 */

#include "Shape.h"

using std::string;

std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
	return os << shape.getType() << " at " << shape.boundingLowerLeft() << " to " << shape.boundingUpperRight();
}

Shape::Shape(const Color<ColorType>& initialColor,
			 const Coordinate<CoordType>& initialPosition)
{
	type = string("Shape");
	color = initialColor;
	position = initialPosition;
	center = position;
}

Coordinate<CoordType> Shape::getPosition() const
{
	return position;
}

Color<ColorType> Shape::getColor() const
{
	return color;
}

void Shape::setColor(const Color<ColorType>& c)
{
	color = c;
}

string Shape::getType() const
{
	return type;
}
