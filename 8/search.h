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
T _search(T b, T e, T b2, T e2) {
	while( b != e ) {
		if ( equal(b, e, b2) ) return b;
		b++;
	}
	return b2;
}

template <class S, class T>
void test_search(T source, T dest, S expected, bool eval)
{
	S result = _search(source.begin(), source.end(), dest.begin(), dest.end());
	int len = dest.end() - dest.begin();
	assert( _equal(result, result+len, expected) == eval );
}

void search_tests() {
	cout << "Testing search(b, e, b1, b2):\t";
	
	c_type a = make_range(0, 10);
	c_type b = make_range(2, 8);
	c_type c = make_range(4, 6);
	
	test_search( a, b, b.begin(), true );
	test_search( b, c, c.begin(), true );
	test_search( c, a, c.begin(), false );
	
	cout << "Passed!" << endl;
}

#endif // SEARCH_H