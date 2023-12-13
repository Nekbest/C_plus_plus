#include "Fraction.h"

Fraction::Fraction() :Pair()
{}

Fraction::Fraction(int value_1, int value_2) :Pair(value_1, value_2)
{
	reduce();
}

void Fraction::set_value_1(int val_1)
{
	value_1 = val_1;
	reduce();
}

void Fraction::set_value_2(int val_2)
{
	value_2 = val_2;
	reduce();
}

int Fraction::gcd(int value_1, int value_2)
{
	if (value_2 == 0)
		return value_1;
	return gcd(value_2, value_1 % value_2);
}

void Fraction::reduce()
{
	int a;
	if (value_1 < 0)
		a = gcd(-1 * value_1, value_2);
	else
		a = gcd(value_1, value_2);
	value_2 = value_2 / a;
	value_1 = value_1 / a;
}

std::ostream& operator <<(std::ostream& out, Fraction& fract)
{
	out << std::to_string(fract.get_value_1()) + "/" + std::to_string(fract.get_value_2()) + "\n";
	return out;
}

Fraction Fraction::operator/ (const  Fraction& other_fract) const
{
	return Fraction(value_1 * other_fract.value_2, value_2 * other_fract.value_1);
}

Fraction Fraction::operator* (const  Fraction& other_fract) const
{
	return Fraction(value_1 * other_fract.value_1, value_2 * other_fract.value_2);
}

Pair* Fraction::operator +(Pair* other_pair)
{
	int numerator = value_1 * other_pair->get_value_2() + other_pair->get_value_1() * value_2;
	int denominator = value_2 * other_pair->get_value_2();
	Pair* pfraction = new Fraction(numerator, denominator);
	return pfraction;
}


Pair* Fraction::operator -(Pair* other_pair)
{
	int numerator = value_1 * other_pair->get_value_2() - other_pair->get_value_1() * value_2;
	int denominator = value_2 * other_pair->get_value_2();
	Pair* pfraction = new Fraction(numerator, denominator);
	return pfraction;
}

bool Fraction::operator <(Pair* other_fract)
{
	return (value_1 * other_fract->get_value_2() - other_fract->get_value_1() * value_2 < 0);
}

bool Fraction::operator >(Pair* other_fract)
{
	return (value_1 * other_fract->get_value_2() - other_fract->get_value_1() * value_2 > 0);
}

bool Fraction::operator <=(Pair* other_fract)
{
	return !(value_1 * other_fract->get_value_2() - other_fract->get_value_1() * value_2 > 0);
}

bool Fraction::operator >=(Pair* other_fract)
{
	return !(value_1 * other_fract->get_value_2() - other_fract->get_value_1() * value_2 < 0);
}
