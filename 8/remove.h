/*
 * remove.h
 *
 * Defines the generic function remove(b, e, t)
 *
 * Description:
 *	Rearranges the elements in the sequence denoted by the forward
 *	iterators b and e so that elements whose values do not match t,
 *	or for which the predicate p returns false (if p is supplied),
 *	are coalesced at the beginning of the associated sequence.
 *	Returns an iterator one past the unremoved elements.
 */

#ifndef REMOVE_H
#define REMOVE_H

#include "utilities.h"

//#include "equal.h"
//#include "find.h"

#include <assert.h>
#include <stdexcept>
#include <iostream>
using std::cout;
using std::endl;


/*
template <class S, class T>
void test_remove(T source, S t, T expected)
{
	T result = remove(source.begin(), source.end(), t);
	equal(result.begin(), result.end(), expected.begin());
}

void remove_tests() {
	cout << "Testing remove(b, e, t):\t";
	test_remove( make_range(0, 10), 0, make_range(1, 10));
	test_remove( make_range(0, 10), 9, make_range(0, 9));
	cout << "Passed!" << endl;
}*/

#endif // REMOVE_H