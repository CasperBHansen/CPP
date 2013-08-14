/*
 * 13-6.cpp
 *
 * Add a class to the system to represent students taking the
 * course for pass/fail credit. Assume that such students need
 * not do the homework, but might do so. If they do, the homework
 * should participate in determining whether they passed or failed,
 * according to the normal formula. If they did no homework, then
 * the grade is the average of their midterm and final grades. A
 * passing grade is 60 or higher.
 *
 * Make sure it inherits from the Core class!
 */

#include <iostream>
#include <stdexcept>

#include "Core.h"
#include "PassFail.h"

int main(int argc, char * argv[]) {

	// simple tests, to see that it chooses the correct formula
	PassFail * p1 = new PassFail(std::cin);
	PassFail * p2 = new PassFail(std::cin);
	
	// enter one with homework
	double g1 = p1->grade();
	std::cout << "Grade: " << g1 << std::endl;
	
	// enter one without homework
	double g2 = p2->grade();
	std::cout << "Grade: " << g2 << std::endl;

	delete p1, p2;
	
	return 0;
}
