/*
 * Coordinate.h
 *
 * Declares the Coordinate data structure.
 */

#ifndef COORDINATE_H
#define COORDINATE_H

template <class T>
struct Coordinate {
	T x, y;
	
	Coordinate(T a = 0, T b = 0) {
		x = a;
		y = b;
	};
};

const Coordinate<COORD_TYPE> origo(0.0, 0.0);

template <class T>
std::ostream& operator<<(std::ostream& os, const Coordinate<T>& coord)
{
	return os << "(" << coord.x << "," << coord.y << ")";
}

template <class T>
Coordinate<T> operator+(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return Coordinate<T>(a.x + b.x, a.y + b.y);
}

template <class T>
Coordinate<T> operator-(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return Coordinate<T>(a.x - b.x, a.y - b.y);
}

template <class T>
T operator*(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return a.x * b.x + a.y * b.y;
}

template <class T>
T crossProduct(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return ( (a.x * b.y) - (a.y * b.x) );
}

#endif // COORDINATE_H

