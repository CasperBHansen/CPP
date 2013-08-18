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
T min(T a, T b) {
	return (a < b) ? a : b;
}

template <class T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

// overload the == operator on Shape instead
template <class S, class T>
bool areaCompare(const S& a, const T& b) {
	#ifdef DEBUG
	if (a.area() < b.area())
		std::cout << "a's area is less than b's area." << std::endl;
	else
		std::cout << "a's area is greater than or equal to b's area." << std::endl;
	#endif
	return a.area() < b.area();
}

template <class S, class T>
bool intersect(const S& a, const T& b) {
	if (
		( a.boundingLowerLeft().x >= b.boundingLowerLeft().x &&
		  a.boundingLowerLeft().x <= b.boundingUpperRight().x &&
		  a.boundingLowerLeft().y >= b.boundingLowerLeft().y &&
		  a.boundingLowerLeft().y <= b.boundingUpperRight().y ) ||
		( a.boundingUpperRight().x >= b.boundingLowerLeft().x &&
		  a.boundingUpperRight().x <= b.boundingUpperRight().x &&
		  a.boundingUpperRight().y >= b.boundingLowerLeft().y &&
		  a.boundingUpperRight().y <= b.boundingUpperRight().y
		)
	)
		return true;
	return false;
}

template <class S, class T>
bool intersectByColor(const S& a, const T& b, const Color<ColorType>& color) {
	if ( !(a.getColor() == b.getColor()) )
		return false;
	else
		return intersect(a, b);
}

#endif // MATH_H
