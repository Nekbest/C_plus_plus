#pragma once
#include <string>
#include <sstream>
#include "Pair_abstract.h"


class Fraction: public Pair
{
private:
	int gcd(int numerator, int denominator);
	void reduce();
public:

	Fraction();
	Fraction(int numerator, int denominator);
	void set_value_1(int val_1) override;
	void set_value_2(int val_2) override;
	Fraction operator  /(const  Fraction& fracrght) const;
	Fraction operator *(const  Fraction& fracrght) const;
	Pair* operator +(Pair* other_pair) override;
	Pair* operator -(Pair* other_pair) override;
	bool operator >(Pair* other_fract);
	bool operator <(Pair* other_fract);
	bool operator >=(Pair* other_fract);
	bool operator <=(Pair* other_fract);
	friend std::ostream& operator << (std::ostream& os, Fraction& fract);

};
