/*
 * Line.h
 *
 * Declares the Line class, which represents a 2D line.
 */

#ifndef LINE_H
#define LINE_H

#include "Shape.h"

template <class CoordType, class ColorType>
class Line : public Shape<CoordType, ColorType> {
public:
	Line(const Color<ColorType>& initialColor = Color<ColorType>(),
		 const Coordinate<CoordType>& position = Coordinate<CoordType>(),
		 const Coordinate<CoordType>& a = Coordinate<CoordType>(),
		 const Coordinate<CoordType>& b = Coordinate<CoordType>())
	: Shape<CoordType, ColorType>(initialColor, position)
	{
		this->type = std::string("Line");
		origin = a;
		end = b;
	}
	
	virtual double area() const { return 0.0; }
	
	virtual Coordinate<CoordType> getCenter() const
	{
		return Coordinate<CoordType>( (origin.x + end.x) / 2.0 , (origin.y + end.y) / 2.0 ) + this->position;
	}

	virtual Coordinate<CoordType> boundingLowerLeft() const
	{
		Coordinate<CoordType> ret;
		ret.x = min( origin.x, end.x );
		ret.y = min( origin.y, end.y );
		return ret + this->position;
	}

	virtual Coordinate<CoordType> boundingUpperRight() const
	{
		Coordinate<CoordType> ret;
		ret.x = max( origin.x, end.x );
		ret.y = max( origin.y, end.y );
		return ret + this->position;
	}

private:
	Coordinate<CoordType> origin, end;
};

#endif
