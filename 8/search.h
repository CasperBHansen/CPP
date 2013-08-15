/*
 * search.h
 *
 * Defines the generic function search(b1, e1, b2, e2)
 *
 * Description:
 *	Returns a forward iterator positioned on the first occurrence,
 *	in the sequence denoted by the forward iterators b and e, of the
 *	subsequence denoted by the forward iterators b2 and e2. Uses the
 *	predicate p for the test, or the == operator if p is not supplied.
 */

#ifndef SEARCH_H
#define SEARCH_H

#include "utilities.h"
#include "equal.h"

#include <assert.h>
#include <iostream>
using std::cout;
using std::endl;

template<class T>
T& search(T& b, T& e, T& b2, T& e2) {
	while (b != e) {
		while ( (* b2) != (* b) && b2 != e2 )
			if ( equal(b, e, b2) ) return b;
	}

	return b;
}

template <class T>
void test_search(const T& source, const T& dest)
{
	search(source.begin(), source.end(), dest.begin(), dest.end());
}

void search_tests() {
	cout << "Testing search(b, e, b1, b2):\t";
	test_search( make_range(0, 10), make_range(0, 10) );
	cout << "Passed!" << endl;
}

#endif // SEARCH_H