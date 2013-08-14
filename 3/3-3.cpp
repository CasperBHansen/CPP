/*
 *	3-3.cpp
 *
 *	Write a program to count how many times each distinct
 *	word appears in its input.
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

// token data structure
typedef struct {
	string identifier;
	int count;
} token;

vector<token> tokenize(string str) {

    string buffer;
    std::stringstream ss(str);

    vector<token> tokens;

    // parse the string
    while (ss >> buffer) {

    	// look for existence within the list
    	token * t = 0;
    	for (vector<token>::iterator it = tokens.begin(); it != tokens.end(); ++it)
    		if ( buffer.compare( (* it).identifier ) == 0 )
    			t = &(* it);

    	// if the token existed increase its count
    	if (t)
    		(* t).count++;
    	// if not, then add it to the vector
    	else {
    		token tmp;
    		tmp.identifier = buffer;
    		tmp.count = 1;
    		tokens.push_back(tmp);
    	}
    }
    
    return tokens;
}

void printTokens(vector<token> tokens) {
	// simply prints all tokens and their respective counts
	for (vector<token>::iterator it = tokens.begin(); it != tokens.end(); ++it)
		cout << (* it).identifier << ": " << (* it).count << endl;
}

int main(int argc, char * argv[])
{
	// ask for input from the user
	cout << "Can I has string?" << endl;

	// read input from the user
	string str;
	std::getline(cin, str);

	// tokenize the string
	vector<token> tokens = tokenize(str);

	// print the word counts
	printTokens(tokens);

	return 0;
}
