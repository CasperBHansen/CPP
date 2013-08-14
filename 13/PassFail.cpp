/*
 * PassFail.cpp
 *
 * Defines the PassFail class.
 */

#include "PassFail.h"

#include <algorithm>
#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::min;
#endif

#include <iostream>
using std::istream;

#include <stdexcept>

#include "grade.h"

std::istream& read_hw(std::istream& in, std::vector<double>& hw);

istream& PassFail::read(istream& in)
{
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double PassFail::grade() const
{
	try {
		// attempt the normal calculation
		return std::min(Core::grade(), thesis);
	}
	catch(std::domain_error& e) {
		// if no homework is done, take the average of
		// midterm and final exams
		std::cout << "No homework: Calculate by averaging midterm and final exam." << std::endl;
		return (midterm + final) / 2.0;
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}