/*
 * Color.h
 *
 * Declares the Color data structure.
 */

#ifndef COLOR_H
#define COLOR_H

template <class T>
struct Color {
	T r, g, b;
	
	Color(T s = 0, T t = 0, T u = 0) {
		r = s;
		g = t;
		b = u;
	}
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Color<T>& color)
{
	return os << "RGB(" << color.r << "," << color.g << "," << color.b << ")";
}

template <class T>
bool operator==(const Color<T>& a, const Color<T> b) {
	return (a.r == b.r && a.g == b.g && a.b == b.b);
}

#endif // COLOR_H

