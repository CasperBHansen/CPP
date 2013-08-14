/*
 *	4-5.cpp
 *
 *	Write a function that reads words from an input stream and
 *	stores them in a vector.
 *
 *	Use that function both to write programs that count the number
 *	of words in the input, and to count how many times each word
 *	occurred.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct word {
	std::string string;
	int count;
};

std::istream& read(std::istream& is, std::vector<std::string>& words) {

	if (is) {
		// make sure we've got a clean vector to work with
		words.clear();

		// while the input stream hasn't failed (by an end-of-file)
		std::string buffer;
		while ( is >> buffer ) {

			// add the buffered word to the vector
			words.push_back(buffer);
		}

		// clear the input stream flags
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max());
	}

	return is;
}

int main(int argc, char * argv[]) {

	// instruct the user to enter a string
	std::cout << "Enter a string, followed by an end-of-file:" << std::endl;

	// set up a vector for storage
	std::vector<std::string> ws;

	// read the input from the user
	read(std::cin, ws);

	// organize into data structure
	std::vector<word> words;
	for (std::vector<std::string>::iterator it = ws.begin();
		it != ws.end(); ++it) {

		// initially, just add it
		if ( words.empty() ) {
			word w;
			w.string = (* it);
			w.count = 1;
			words.push_back(w);
			continue;
		}

		// if it exists, add one to the count
		bool found = false;
		for (std::vector<word>::iterator w = words.begin();
			w != words.end(); ++w) {

			if ( (* w).string.compare(* it) == 0 ) {
				(* w).count++;
				w = words.end() - 1;
				found = true;
			}
		}

		// if we didn't find anything, just add it
		if ( !found ) {
			word w;
			w.string = (* it);
			w.count = 1;
			words.push_back(w);
		}
	}

	int count = 0;
	std::cout << "A list of words and how many times they appear:" << std::endl;
	for (std::vector<word>::iterator w = words.begin();
		w != words.end(); ++w) {
		std::cout << (* w).string << " (" << (* w).count << ")" << std::endl;
		count += (* w).count;	
	}

	std::cout << "Word count: " << count << std::endl;

	return 0;
}