/*
 *	6-4.cpp
 *
 *	Correct the program you wrote in the previous exercise to copy
 *	from u into v. There are at least two possible ways to correct
 *	the program. Implement both, and describe the relative advantages
 *	and disadvantages of each approach.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main(int argc, char * argv[]) {

	/*	There are two possible fixes that I can think of;
	 *	
	 *	1. Initialize v with the same capacity as the data being copy.
	 *	2. Use an iterator that is able to append to the vector.
	 */

	std::vector<int> u(10, 100);

	// 1st. fix:
	std::vector<int> v( u.capacity() );
	copy(u.begin(), u.end(), v.begin());

	// 2nd. fix:
	std::vector<int> w;
	copy(u.begin(), u.end(), std::back_inserter(w));

	return 0;
}