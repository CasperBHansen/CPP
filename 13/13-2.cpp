/*
 * 13-2.cpp
 *
 * Given the Core and Grad classes defined in this chapter,
 * indicate which function is called for each of these invocations:
 *
 * Core* p1 = new Core; Core* p2 = new Grad; Core s1;
 * Grad s2;
 * p1->grade(); p1->name();
 * p2->grade(); p2->name();
 * s1.grade(); s1.name();
 * s2.name(); s2.grade();
 * 
 * Check whether you are correct by adding output statements to the
 * name and grade functions that indicate which function is being
 * executed.
 */

#include <iostream>

#include "Core.h"

int main(int argc, char * argv[]) {

	Core* p1 = new Core;
	Core* p2 = new Grad;
	Core s1;
	Grad s2;
	
	p1->grade();	// Core::grade();
	/*
	p1->name();		// Core::grade();
	
	p2->grade();	// Grad::grade();
	p2->name();		// Grad::grade();
	
	s1.grade();		// Core::grade();
	s1.name();		// Core::grade();
	
	s2.name();		// Grad::grade();
	s2.grade();		// Grad::grade();
	*/

	delete p1, p2;

	return 0;
}
