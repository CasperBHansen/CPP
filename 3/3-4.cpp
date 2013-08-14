/*
 *	3-4.cpp
 *
 *	Write a program to report the length of the longest
 *	and shortest string in its input.
 *
 *	Note:	I assume that by the length of the strings it is
 *			meant to be the length of individual words within
 *			a string. If not, then a possible fix is simply to
 *			take more than one string from the user, and have the
 *			user end the input session by a special delimiter.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <vector>;
using std::vector;

int main(int argc, char * argv[])
{
	// ask for input from the user
	cout << "Can I has string?" << endl;

	// read input from the user
	string str;
	std::getline(cin, str);

	// parse the string
	string first, buffer;
    std::stringstream ss(str);

    // make sure that initial values are good
    ss >> first;
    string longest = "";
    string shortest = first;
    while (ss >> buffer) {

    	// if the buffered string is shorter, update the shortest.
    	if ( buffer.length() < shortest.length() )
    		shortest = buffer;

    	// if the buffered string is longer, update the longest.
    	if ( buffer.length() > longest.length() )
    		longest = buffer;
    }

    // print our findings
    cout << "Longest string was \"" << longest << "\", of length " << longest.length() << endl;
    cout << "Shortest string was \"" << shortest << "\", of length " << shortest.length() << endl;

	return 0;
}
