/*
 * Triangle.h
 *
 * Declares the Triangle class.
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

template <class CoordType, class ColorType>
class Triangle : public Shape<CoordType, ColorType> {
public:
	Triangle(const Color<ColorType>& initialColor = Color<ColorType>(),
			 const Coordinate<CoordType>& position = Coordinate<CoordType>(),
			 const Coordinate<CoordType>& s = Coordinate<CoordType>(),
			 const Coordinate<CoordType>& t = Coordinate<CoordType>(),
			 const Coordinate<CoordType>& u = Coordinate<CoordType>())
	: Shape<CoordType, ColorType>(initialColor, position)
	{
		this->type = std::string("Triangle");
		
		a = s;
		b = t;
		c = u;
	}
	
	virtual double area() const
	{
		// half the area of the parallelogram
		return 0.5 * abs( crossProduct(b-a, c-a) );
	}

	virtual Coordinate<CoordType> getCenter() const
	{
		return Coordinate<CoordType>( (a.x + b.x + c.x) / 3.0 , (a.y + b.y + c.y) / 3.0 ) + this->position;
	}

	virtual Coordinate<CoordType> boundingLowerLeft() const
	{
		return Coordinate<CoordType>( min( min(a.x, b.x), c.x ) , min( min(a.y, b.y), c.y ) ) + this->position;
	}

	virtual Coordinate<CoordType> boundingUpperRight() const
	{
		return Coordinate<CoordType>( max( max(a.x, b.x), c.x ) , max( max(a.y, b.y), c.y ) ) + this->position;
	}

private:
	Coordinate<CoordType> a, b, c;
};

#endif // TRIANGLE_H
