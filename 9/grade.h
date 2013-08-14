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
	Grade(std::istream& is);
	~Grade();

private:
	std::vector<Student_info> students;
	std::string::size_type maxlen;
};

/*
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store the data
	while (record.read(cin)) {                           // changed
		maxlen = max(maxlen, record.name().size());      // changed
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
#ifdef _MSC_VER
	for (std::vector<Student_info>::size_type i = 0;
#else
	for (vector<Student_info>::size_type i = 0;
#endif
	     i != students.size(); ++i) {
		cout << students[i].name()   // this and the next line changed
		     << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();   // changed
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
			     << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
*/

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);

#endif

