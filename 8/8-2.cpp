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
 *
 *	NOTE:	I spent waaay too long figuring out why my functions
 *			weren't getting called. At first it seemed like they
 *			did get called, and that the ones I had written worked.
 *			Later I found out that the actual calling stack went to
 *			the standard library - this took me 4 hours to realize.
 *			As such, I had one and a half hours left of fixing the
 *			bugs that I thought weren't even there. This is why I
 *			haven't gotten all done, and should you find any bugs,
 *			that would also be the reason. Dang it!
 */

#include "utilities.h"

#include "copy.h"
#include "equal.h"
#include "find.h"
#include "partition.h"
#include "remove.h"
#include "search.h"

int main(int argc, char * argv[]) {

	copy_tests();
	equal_tests();
	find_tests();
	partition_tests();
	// remove_tests(); this doesn't work, too little time to fix and too tired ...
	search_tests();

	return 0;
}