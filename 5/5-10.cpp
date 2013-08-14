/*
 *	5-10.cpp
 *
 *	Palindromes are words that are spelled the same right to left
 *	as left to right. Write a program to find all the palindromes
 *	in a dictionary. Next, find the longest palindrome.
 */

#include <iostream>
#include <vector>

// palindrome 
typedef struct {
	std::string string;
	std::string::size_type length;
} Palindrome;

// make it easy on ourselves to print palindromes
std::ostream& operator <<(std::ostream& os, const Palindrome& p) {
	return os << p.string << " (" << p.length << ")";
}

// takes a string and returns whether or not it is a palindrome
bool isPalindrome(const std::string str) {
	// make sure the string isn't empty
	if ( str.empty() ) return false;

	// walk through the string from both ends, checking for equality
	for (int i = 0, j = str.length() - 1; i < j; ++i, --j) {

		// should one of these not be equal, then it is not a palindrome
		if (str[i] != str[j])
			return false;
	}

	// by this point it is induced that the string is a palindrome
	return true;
}

std::vector<Palindrome> extractPalindromes(std::vector<std::string> dictionary) {
	
	// loop through the dictionary and find palindromes
	std::vector<Palindrome> palindromes;
	for (std::vector<std::string>::iterator it = dictionary.begin();
		it != dictionary.end(); ++it) {
		
		// if it's a palindrome, add it to the vector
		if ( isPalindrome(* it) ) {
			Palindrome tmp;
			tmp.string = (* it);
			tmp.length = (* it).length();
			palindromes.push_back(tmp);
		}
	}

	// return the palindromes
	return palindromes;
}

int main(int argc, char * argv[]) {

	// ask the user for input
	std::cout << "Enter a string:" << std::endl;

	// read input from the stream and add each word to a dictionary
	std::vector<std::string> dictionary;
	std::string buffer;
	while (std::cin >> buffer) {
		dictionary.push_back(buffer);
	}

	// extract palindromes out of the dictionary
	std::vector<Palindrome> palindromes = extractPalindromes(dictionary);

	// print our findings
	Palindrome longest;
	longest.length = 0;
	for (std::vector<Palindrome>::iterator it = palindromes.begin();
		it != palindromes.end(); ++it) {
		std::cout << (* it) << std::endl;

		// if this one is longer than the previously stored, replace it
		if ( (* it).length > longest.length )
			longest = (* it);
	}

	// print the longest palindrome in the dictionary
	std::cout << "Longest palindrome in dictionary: " << longest << std::endl;

	return 0;
}