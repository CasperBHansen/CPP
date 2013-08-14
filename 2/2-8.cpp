/*
 *	2-8.cpp
 *
 *	Write a program to generate the product of the numbers in
 *	the range [1, 10).
 */

#include <iostream>
using std::cout;
using std::endl;

int productOfRange(int a, int b) {
	// set up the variable for accumulating
	int ret = 1;

	// for all integers in the range, take the product of
	// the previously calculated value and the next integer
	for (int i = a; i < b; ++i)
		ret *= i;

	// return the product of the range
	return ret;
}

int main(int argc, char * argv[]) {

	// print the result
	cout << productOfRange(1, 10) << endl;
	
	return 0;
}