/*
 * math.h
 *
 * Mathematical functions. (I know I could use <math.h> and <algorithm>)
 */

#ifndef MATH_H
#define MATH_H

#ifdef DEBUG
	#include <iostream>
#endif

#include "Shape.h"

#define MATH_PI 3.1415

template <class T>
T abs(T n) {
	return (n < 0) ? -n : n;
}

template <class T>
T min(T a, T b) {
	return (a < b) ? a : b;
}

template <class T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

template <class S, class T>
bool areaCompare(const S& a, const T& b) {
	#ifdef DEBUG
	if (a.area() < b.area())
		std::cout << "a (" << a.area() << ") < b (" << b.area() << ")" << std::endl;
	else
		std::cout << "a (" << a.area() << ") >= b (" << b.area() << ")" << std::endl;
	#endif
	return a.area() < b.area();
}

template <class S, class T>
bool intersect(const S& a, const T& b) {
	if (abs( a.getCenter().x - b.getCenter().x ) * 2 < ( (a.boundingUpperRight().x - a.boundingLowerLeft().x) + (b.boundingUpperRight().x - b.boundingLowerLeft().x) ) &&
		abs( a.getCenter().y - b.getCenter().y ) * 2 < ( (a.boundingUpperRight().y - a.boundingLowerLeft().y) + (b.boundingUpperRight().y - b.boundingLowerLeft().y) ) ) {
		#ifdef DEBUG
		std::cout << "a (" << a.getType() << ") and b (" << b.getType() << ") intersects." << std::endl;
		#endif
		return true;
	}
	#ifdef DEBUG
	std::cout << "a (" << a.getType() << ") and b (" << b.getType() << ") do not intersect." << std::endl;
	#endif
	return false;
}

template <class S, class T>
bool intersectByColor(const S& a, const T& b) {
	if ( !(a.getColor() == b.getColor()) ) {
		#ifdef DEBUG
		std::cout << "a (" << a.getType() << ") and b (" << b.getType() << ") colors do not match." << std::endl;
		#endif
		return false;
	}
	else
		return intersect(a, b);
}

#endif // MATH_H
