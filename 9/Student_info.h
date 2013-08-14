#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <string>
#include <vector>

class Student_info {
public:
	Student_info();              // construct an empty `Student_info' object
	Student_info(std::istream&); // construct one by reading a stream
	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }

	// as defined in 9.2.1/157, and changed to read into `n' instead of `name'
	std::istream& read(std::istream&);

	double grade() const;    // as defined in 9.2.1/158

	static bool cmp_by_name(const Student_info&, const Student_info&);
	static bool cmp_by_grade(const Student_info&, const Student_info&);

private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;
};

// bool compare(const Student_info&, const Student_info&);

#endif

