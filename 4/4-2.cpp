/*
 *	4-2.cpp
 *
 *	Write a program to calculate the squares of int values up to 100.
 *	
 *	The program should write two columns: The first lists the value;
 *	the second contains the square of that value. Use setw (described
 *	above) to manage the output so that the values line up in columns.
 *
 *	Note:	This implementation also makes up for the invariant
 *			that is to be solved in 4-3.
 */

#include <iostream>
#include <iomanip>

#include <string>
using std::string;

#include <math.h>

int main(int argc, char * argv[]) {

	// ask the user for input
	std::cout << "Enter a number (100 for exercise 4-2, and 999 for exercise 4-3): ";
	
	// get the input from the user
	int n;
	std::cin >> n;

	// make sure input is valid
	if (n < 0)
		n = abs(n);

	// calculate padding size
	std::string::size_type pad = ceil( log10( fabs(n) + 1 ) );

	// print formatted integers and their squares
	for (int i = 0; i <= n; ++i)
		std::cout << std::setw(pad) << i << "\t" << i * i << std::endl;
	
	return 0;
}