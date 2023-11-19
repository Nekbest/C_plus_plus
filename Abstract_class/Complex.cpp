#include "Complex.h"
#include <sstream>

Complex::Complex():Pair()
{}

Complex::Complex(double r, double im):Pair(r, im)
{}


Pair* Complex::operator +(Pair* other_pair)
{
	Pair* pcomplex_number = new Complex(value_1 + other_pair->get_value_1(), value_2 + other_pair->get_value_2());
	return pcomplex_number;
}

Pair* Complex::operator -(Pair* other_pair)
{

	Pair* pcomplex_number = new Complex(value_1 - other_pair->get_value_1(), value_2 - other_pair->get_value_2());
	return pcomplex_number;
}

Pair* Complex::operator *(Pair* other_complex)
{

	Pair* pcomplex_number = new Complex(value_1 * other_complex->get_value_1() - value_2 * other_complex->get_value_2(),
		value_1 * other_complex->get_value_2() + value_2 * other_complex->get_value_1());
	return pcomplex_number;
}

Pair* Complex::operator /(Pair* other_complex)
{
	Pair* pcomplex_number = new Complex(0, 0);
	if (other_complex->get_value_1() != 0 && other_complex->get_value_2() != 0)
	{
		pcomplex_number->set_value_1((value_1 * other_complex->get_value_1() + value_2 * other_complex->get_value_2())
			/ (other_complex->get_value_1() * other_complex->get_value_1() + other_complex->get_value_2() * other_complex->get_value_2()));
		pcomplex_number->set_value_2((value_2 * other_complex->get_value_1() - value_1 * other_complex->get_value_2())
			/ (other_complex->get_value_1() * other_complex->get_value_1() + other_complex->get_value_2() * other_complex->get_value_2()));
	}
	return pcomplex_number;
}
 
std::string Complex::tostring()
{
	if (get_value_2() >= 0)
		return std::to_string(get_value_1()) + "+" + std::to_string(get_value_2()) + "i";
	else
		return std::to_string(get_value_1()) + std::to_string(get_value_2()) + "i";
}

std::ostream& operator <<(std::ostream& out, Complex& complex_number)
{

	out << complex_number.tostring() << "\n";
	return out;
}
