#include <iostream>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::istream;
using std::vector;

double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

bool Student_info::passed() const
{
	return (this->grade() >= 60);
}

bool Student_info::cmp_by_name(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

bool Student_info::cmp_by_grade(const Student_info& x, const Student_info& y)
{
	return x.grade() > y.grade();
}

Student_info::Student_info(): midterm(0), final(0) { }

Student_info::Student_info(istream& is) { read(is); }	

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

istream& Student_info::read(istream& in)
{
	std::cout << "Enter student name, midterm and final grades:" << std:: endl;
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

