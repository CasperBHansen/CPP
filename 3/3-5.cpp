/*
 *	3-5.cpp
 *
 *	Write a program that will keep track of grades for several
 *	students at once.
 *	
 *	The program could keep two vectors in sync: The first should
 *	hold the student's names, and the second the final grades that
 *	can be computed as input is read.
 *	
 *	For now, you should assume a fixed number of homework grades.
 *	We'll see in §4.1.3/56 how to handle a variable number of grades
 *	intermixed with student names.
 */

#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <string>
#include <vector>
using std::vector;

using std::cin;                  using std::setprecision;
using std::cout;                 using std::string;
using std::endl;                 using std::streamsize;

// student data structure
typedef struct {
	string name;
	double grade;
} Student;

Student processStudent() {

	// reset the stream flags and sync it
	cin.clear();
	cin.sync();

	Student student;

	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> student.name;

	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for the homework grades
	cout << "Enter all your homework grades, "
	        "followed by end-of-file (or a mismatch in datatype): ";

	// the number and sum of grades read so far
	int count = 0;
	double sum = 0;

	// a variable into which to read
	double x;

	// invariant:
	//     we have read `count' grades so far, and
	//     `sum' is the sum of the first `count' grades
	while (cin >> x) {
		++count;
		sum += x;
	}

	// calculate the final grade
	student.grade = 0.2 * midterm + 0.4 * final + 0.4 * sum / count;
	
	return student;
}

void printStudent(Student student) {

	// write the result
	streamsize prec = cout.precision();
	cout << student.name << "'s final grade is " << setprecision(3)
	     << student.grade
	     << setprecision(prec) << endl;
}

int main(int argc, char * argv[])
{
	// initialize a vector of students
	vector<Student> students;

	// ask the user for how many students we'd like to process
	cout << "How many students handed in their assignments?" << endl;

	// get the number of students from the user
	int number = 0;
	cin >> number;

	// for each one of these, complete the enquiry prompt
	for (int i = 0; i < number; ++i)
	{
		// add the newly processed student
		students.push_back( processStudent() );
		
		// this checks the eof- and mismatched data,
		// if not done it causes a bug in the istream
		if ( cin.fail() ) {
			// reset error flags
			cin.clear();
			// clear the stream buffer
			cin.ignore(std::numeric_limits<int>::max(),'\n');
		}
	}

	// print the students final grades
	for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
		printStudent( (* it) );

	return 0;
}
