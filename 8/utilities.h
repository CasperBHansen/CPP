/*
 * utilities.h
 *
 * Utilities used for assertion test purposes.
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>

#define CONTAINER_TYPE std::vector<int>
typedef CONTAINER_TYPE c_type;

c_type make_range(int i, int j) {
	c_type ret;
	for (int k = i; k < j; ++k)
		ret.push_back(k);
	return ret;
}

template <class T>
void print_c(T b, T e) {
	while (b != e) {
		std::cout << (* b) << std::endl;
		b++;
	}
}

#endif // UTILITIES_H