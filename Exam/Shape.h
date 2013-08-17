/*
 * Shape.h
 *
 * Declares the base Shape class.
 */

#ifndef SHAPE_H
#define SHAPE_H

#define MATH_PI 3.1415

#include <iostream>
#include <string>

// might want to change these to doubles, or something ..
template <class T>
struct Coordinate {
	T x, y;
};

class Shape {
public:
	Shape();

	virtual double area() = 0;
	virtual Coordinate<int> boundingLowerLeft() = 0;
	virtual Coordinate<int> boundingUpperRight() = 0;

	std::string getColor() const;
	void setColor(const char * c_string);
	void setColor(std::string str);

	int getX() const;
	int getY() const;

	void getCoordinates(Coordinate<int>& coord) const;

private:
	Coordinate<int> coordinates;
	std::string color;
};

std::ostream& operator<<(std::ostream& os, const Shape& shape);

#endif // SHAPE_H
