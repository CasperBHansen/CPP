/*
 * 8-2.cpp
 *
 * Implement the following library algorithms, which we used in
 * Chapter 6 and described in §6.5/121. Specify what kinds of
 * iterators they require. Try to minimize the number of distinct
 * iterator operations that each function requires. After you have
 * finished your implementation, see §B.3/321 to see how well you did.
 *
 * equal(b, e, d)			search(b, e, b2, e2)
 * find(b, e, f)			find_if(b, e, p)
 * copy(b, e, d)			remove(b, e, t)
 * remove_copy(b, e, d, t)	remove_copy_if(b, e, d, p)
 * transform(b, e, d, f)	partition(b, e, p)
 * accumulate(b, e, t)
 */

/*
	Done:
		· equal
		· find

	Buggy:
		· remove
		· search

	Missing:
		· accumulate
		· copy
		· find_if
		· partition
		· remove_copy
		· remove_copy_if
		· transform
 */

#include <iostream>
using std::cout;
using std::endl;

#include "utilities.h"

// #include "equal.h"
// #include "find.h"
#include "remove.h"
// #include "search.h"

int main(int argc, char * argv[]) {

	cout << "8-2" << endl;
	// equal_tests();
	// find_tests();
	// remove_tests();
	// search_tests();

//	c_type a = make_range(0, 10);

	// print_c(a.begin(), a.end());
//	remove(a.begin(), a.end(), 5);
//	print_c(a.begin(), a.end());

	return 0;
}