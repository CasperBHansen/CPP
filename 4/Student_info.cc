// source file for `Student_info'-related functions
#include "Student_info.h"
#include "grade.h"

#include <exception>
using std::exception;

using std::istream;  using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	std::cout << "Enter student name, midterm and final exam grades:" << std::endl;

	// read and store the student's name and midterm and final exam grades
	double midterm, final;
	is >> s.name >> midterm >> final;

	vector<double> homework;
	read_hw(is, homework);  // read and store all the student's homework grades

	try {
		s.final = grade(midterm, final, homework);
	}
	catch (exception& e) {
		e.what();
	}
	return is;
}

// read homework grades from an input stream into a `vector<double>'
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {

		std::cout << "Enter homework grades:" << std::endl;

		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}

