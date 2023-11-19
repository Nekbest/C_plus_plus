#pragma once
#include "Pair_abstract.h"
#include <string>
#include <sstream>

class Complex: public Pair
{
public:
	Complex();
	Complex(double real, double image);
	std::string tostring() override;
	friend std::ostream& operator << (std::ostream& os, Complex& complex_number);
	Pair* operator +(Pair* other_pair) override;
	Pair* operator -(Pair* other_pair) override;
	Pair* operator *(Pair* other_complex);
	Pair* operator /(Pair* other_complex);
};
