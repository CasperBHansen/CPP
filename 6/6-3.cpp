/*
 *	6-3.cpp
 *
 *	What does this program fragment do?
 *
 *	Write a program that contains this fragment, and compile
 *	and execute it.
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char * argv[]) {

	std::vector<int> u(10, 100);
	std::vector<int> v;

	/*	bug:	this line segfaults
	 *	reason:	copy assumes that v has the capacity to hold
	 *			the amount of data being copied, but since v
	 *			is an empty vector, it will segfault when
	 *			trying to copy to unallocated memory.
	 */
	std::copy(u.begin(), u.end(), v.begin());

	return 0;
}