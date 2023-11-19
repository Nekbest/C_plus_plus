#include "Money.h"

Money::Money():Pair()
{}

Money::Money(double r, double p):Pair(r, p)
{}

Pair* Money::operator +(Pair* other_pair)
{

	double r, p, summ = value_1 + other_pair->get_value_1() + value_2 + other_pair->get_value_2();
	r = floor(summ);
	p = summ - r;
	Pair* pmoney = new Money(r, p);
	return pmoney;
}

Pair* Money::operator -(Pair* other_pair)
{
	double r, p, dif = abs(value_1 + value_2 - other_pair->get_value_1() + other_pair->get_value_2());
	r = floor(dif);
	p = dif - r;
	Pair* pmoney = new Money(r, p);
	return pmoney;
}

std::string Money::tostring()
{
	return std::to_string(value_1 + value_2);
}

std::ostream& operator <<(std::ostream& out, Money& money)
{
	double summ = money.get_value_1() + money.get_value_2();
	out << money.tostring() << '\n';
	return out;
}

bool Money::operator >(Pair* other_money)
{
	return ((value_1 + value_2) > (other_money->get_value_1() + other_money->get_value_2()));
}

bool Money::operator <(Pair* other_money)
{
	return ((value_1 + value_2) < (other_money->get_value_1() + other_money->get_value_2()));
}

bool Money::operator >=(Pair* other_money)
{
	return !(this < other_money);
}

bool Money::operator <=(Pair* other_money)
{
	return !(this > other_money);
}
