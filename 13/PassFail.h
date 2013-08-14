/*
 * PassFail.h
 * 
 * Declares the PassFail class.
 */

#ifndef PassFail_h
#define PassFail_h

#include "Core.h"

class PassFail : public Core
{
public:
	PassFail(): thesis(0) { }
	PassFail(std::istream& is) { read(is); }

	// as defined in 13.1.2/230; Note: `grade' and `read' are `virtual' by inheritance
	double grade() const;
	std::istream& read(std::istream&);

private:
	double thesis;
#ifdef _MSC_VER
	Core* clone() const { return new Grad(*this); }
#else
	PassFail* clone() const { return new PassFail(*this); }
#endif
};

#endif // PassFail_h