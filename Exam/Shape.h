/*
 * Shape.h
 *
 * Declares the base Shape class.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <cstdint>	// requires the -std=c++11 flag
#include <iostream>
#include <string>

#include "Coordinate.h"
#include "Color.h"

typedef float CoordType;
typedef int ColorType;

// template <class CoordType, class ColorType>
class Shape {
public:
	Shape(const Color<ColorType>& initialColor = Color<ColorType>(),
		  const Coordinate<CoordType>& initialPosition = Coordinate<CoordType>());
	
	virtual std::string getType() const;
	
	virtual double area() const = 0;
	
	Coordinate<CoordType> getPosition() const;
	virtual Coordinate<CoordType> getCenter() const = 0;
	virtual Coordinate<CoordType> boundingLowerLeft() const = 0;
	virtual Coordinate<CoordType> boundingUpperRight() const = 0;
	
	Color<ColorType> getColor() const;
	void setColor(const Color<ColorType>& c);
	
protected:
	std::string type;
	
	Coordinate<CoordType> position;
	Coordinate<CoordType> center;

private:
	Color<ColorType> color;
};

std::ostream& operator<<(std::ostream& os, const Shape& shape);

#endif // SHAPE_H
