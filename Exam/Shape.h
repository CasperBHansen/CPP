/*
 * Shape.h
 *
 * Declares the base Shape class.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

#include "Coordinate.h"
#include "Color.h"

template <class CoordType, class ColorType>
class Shape {
public:
	Shape(const Color<ColorType>& initialColor = Color<ColorType>(),
		  const Coordinate<CoordType>& initialPosition = Coordinate<CoordType>())
	{
		type = std::string("Shape");
		color = initialColor;
		position = initialPosition;
	}
	
	virtual std::string getType() const { return type; }
	
	virtual double area() const = 0;
	
	Coordinate<CoordType> getPosition() const { return position; }
	virtual Coordinate<CoordType> getCenter() const = 0;
	virtual Coordinate<CoordType> boundingLowerLeft() const = 0;
	virtual Coordinate<CoordType> boundingUpperRight() const = 0;
	
	Color<ColorType> getColor() const { return color; }
	void setColor(const Color<ColorType>& aColor) { color = aColor; }
	void setPosition(const Coordinate<CoordType>& aPosition) { position = aPosition; };
	
protected:
	std::string type;
	
	Coordinate<CoordType> position;	// the shapes local "pivot", an offset to the shapes coords

private:
	Color<ColorType> color;
};

template <class CoordType, class ColorType>
std::ostream& operator<<(std::ostream& os, const Shape<CoordType, ColorType>& shape)
{
	return os << shape.getType() << " with bounds " << shape.boundingLowerLeft() << " to " << shape.boundingUpperRight();
}

#endif // SHAPE_H
