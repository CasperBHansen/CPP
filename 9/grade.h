#ifndef GUARD_grade_h
#define GUARD_grade_h

// `grade.h'
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Student_info.h"

class Grade {
public:
	Grade();
	~Grade();

	std::istream& read(std::istream& is = std::cin);

	template <class comparison> void report(comparison compare)
	{
		sort(students.begin(), students.end(), compare);

		// write the names and grades
	#ifdef _MSC_VER
		for (std::vector<Student_info>::size_type i = 0;
	#else
		for (std::vector<Student_info>::size_type i = 0;
	#endif
		     i != students.size(); ++i) {
			std::cout << students[i].name()   // this and the next line changed
			     << std::string(maxlen + 1 - students[i].name().size(), ' ');
			try {
				double final_grade = students[i].grade();   // changed
				std::streamsize prec = std::cout.precision();
				std::cout << std::setprecision(3) << final_grade
				     << std::setprecision(prec) << std::endl;
			} catch (std::domain_error e) {
				std::cout << e.what() << std::endl;
			}
		}
	}

private:
	std::vector<Student_info> students;
	std::string::size_type maxlen;
};

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);

#endif

