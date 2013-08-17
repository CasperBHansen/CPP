/*
 * main.cpp
 */

#include <iostream>
using std::cout;
using std::endl;

#include "Circle.h"

int main(int argc, char * argv[]) {

	cout << "Hello, Shapes!" << endl;

	Circle c = Circle();
	c.setColor("Red");
	cout << "The variable c is a " << c << endl;
	
	return 0;
}