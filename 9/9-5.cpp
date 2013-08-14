/*
 * 9-5.cpp
 *
 * Write a class and associated functions to generate grades for
 * students who take the course for pass/fail credit.
 *
 * Assume that only the midterm and final grades matter, and that
 * a student passes with an average exam score greater than 60.
 *
 * The report should list the students in alphabetical order, and
 * indicate P or F as the grade.
 */

#include <algorithm>
#include <iomanip>

#ifndef __GNUC__
#include <ios>
#endif

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif

#include "grade.h"
// #include "Student_info.h"
// #include "median.h"

using std::cin;                    using std::cout;
using std::domain_error;           using std::endl;
using std::setprecision;           using std::setw;
using std::sort;                   using std::streamsize;
using std::string;                 using std::vector;

int main()
{
	Grade g = Grade();

	g.read(cin);
	g.report(Student_info::cmp_by_name);

	return 0;
}

