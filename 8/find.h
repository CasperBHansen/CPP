/*
 * find.h
 *
 * Defines the generic function find(b, e, t)
 *
 * Description:
 *	Returns an iterator denoting the first occurrence of the value t,
 *	or for which the predicate p is true (if p is supplied), in the
 *	sequence denoted by the input iterators b and e. Returns e if no
 *	such element exists.
 */

#ifndef FIND_H
#define FIND_H

#include "utilities.h"

#include <assert.h>
#include <stdexcept>
#include <iostream>
using std::cout;
using std::endl;

template<class S, class T>
S& find(S& b, S& e, T t) {
	while(b != e && (* b) != t) { b++; }
	return b;
}

template <class S, class T>
void test_find(const T& source, S t, bool expected)
{
	S result = (* find(source.begin(), source.end(), t));
	assert( (result == t) == expected );
}

void find_tests() {
	cout << "Testing find(b, e, t):\t";
	test_find( make_range(0, 10), 0, true);
	test_find( make_range(0, 10), 15, false);
	test_find( make_range(0, 10), 9, true);
	test_find( make_range(0, 10), -1, false);
	cout << "Passed!" << endl;
}

#endif // FIND_H