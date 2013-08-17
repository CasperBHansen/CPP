/*
 * Shape.cpp
 */

#include "Shape.h"

using std::ostream;
using std::string;

std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
	return os << shape.getColor() << " shape at (" << shape.getX() << "," << shape.getY() << ")";
}

Shape::Shape()
{
	// make sure we don't have garbage values
	coordinates.x = 0;
	coordinates.y = 0;

	color = string("");
}

string Shape::getColor() const
{
	return color;
}

void Shape::setColor(const char * c_string)
{
	color = string(c_string);
}

void Shape::setColor(string str)
{
	color = str;
}

int Shape::getX() const
{
	return coordinates.x;
}

int Shape::getY() const
{
	return coordinates.y;
}

void Shape::getCoordinates(Coordinate<int>& coord) const {
	coord.x = coordinates.x;
	coord.y = coordinates.y;
}

/*

double Circle::area()
{
	return 0;
}

Coordinate Circle::boundingLowerLeft()
{
	Coordinate tmp;
	return tmp;
}

Coordinate Circle::boundingUpperRight()
{
	Coordinate tmp;
	return tmp;
}

*/