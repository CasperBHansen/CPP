#ifndef GUARD_Student_info
#define GUARD_Student_info

// `Student_info.h' header file
#include <iostream>
#include <string>
#include <vector>

/* old
struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
}; */

struct Student_info {
	std::string name;
	double final;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif

