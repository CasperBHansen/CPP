/*
 *	4-4.cpp
 *
 *	Now change your squares program to use double values instead
 *	of ints. Use manipulators to manage the output so that the
 *	values line up in columns.
 *
 *	Note:	I'm not entirely sure what the exercise is supposed to
 *			show. It's still needs to iterate using an iterator, and
 *			not n itself, since I assume you'd like it to be in
 *			ascending order. The only changes needed, according to
 *			my understanding of what is asked in the exercise, is to
 *			change the types and account for any differences in math
 *			function calls.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

int main(int argc, char * argv[]) {

	// ask the user for input
	std::cout << "Enter a double: ";
	
	// get the input from the user
	double n;
	std::cin >> n;

	// make sure input is valid
	if (n < 0)
		n = fabs(n);

	// calculate padding size
	std::string::size_type pad = ceil( log10(n + 1) );

	// print formatted integers and their squares
	for (double i = 0.0; i <= n; ++i)
		std::cout << std::setw(pad) << i << "\t" << i * i << std::endl;
	
	return 0;
}