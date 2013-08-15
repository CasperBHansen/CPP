/*
 * equal.h
 *
 * Defines the generic function equal(b, e, d)
 *
 * Description:
 *	Returns a bool indicating whether the elements in the sequence
 *	denoted by the input iterators b and e are equal to the elements
 *	in a sequence of the same size beginning at the input iterator b2.
 *	Uses the predicate p for the test, or the == operator if p is not
 *	supplied.
 */

#ifndef EQUAL_H
#define EQUAL_H

#include "utilities.h"

#include <assert.h>
#include <stdexcept>
#include <iostream>
using std::cout;
using std::endl;

template<class T>
bool equal(T& b, T& e, T& d) {
	while ( b != e && (* b) == (* d) ) { b++; d++; }
	return (* b) == (* d);
}

template <class T>
void test_equal(const T& source, const T& dest, bool expected)
{
	return assert( equal(source.begin(), source.end(), dest.begin()) == expected );
}

void equal_tests() {
	cout << "Testing equal(b, e, d):\t";
	test_equal( make_range(0, 10), make_range(0, 10), true );
	test_equal( make_range(0, 10), make_range(2, 8), false );
	test_equal( make_range(2, 8), make_range(0, 10), false );
	test_equal( make_range(2, 10), make_range(2, 12), true );
	cout << "Passed!" << endl;
}

#endif // EQUAL_H