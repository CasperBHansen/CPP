/*
 * Rectangle.h
 *
 * Declares the Rectangle class.
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

template <class CoordType, class ColorType>
class Rectangle : public Shape<CoordType, ColorType> {
public:
	Rectangle(const Color<ColorType>& initialColor = Color<ColorType>(),
			  const Coordinate<CoordType>& position = Coordinate<CoordType>(),
			  const float w = 1.0,
			  const float h = 1.0)
	: Shape<CoordType, ColorType>(initialColor, position)
	{
		this->type = std::string("Rectangle");
		
		width = w;
		height = h;
	}
	
	virtual double area() const
	{
		return width * height;
	}

	virtual Coordinate<CoordType> getCenter() const
	{
		return this->position;
	}

	virtual Coordinate<CoordType> boundingLowerLeft() const
	{
		return this->position - Coordinate<CoordType>( width / 2, height / 2);
	}

	virtual Coordinate<CoordType> boundingUpperRight() const
	{
		return this->position + Coordinate<CoordType>( width / 2, height / 2);
	}

private:
	float width, height;
};

#endif // Rectangle_H
