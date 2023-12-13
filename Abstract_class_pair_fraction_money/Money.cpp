#include "Money.h"

Money::Money() :Pair()
{}

Money::Money(int rubles, int pennies) :Pair(rubles, pennies)
{
	normalized();
}

void Money::normalized()
{
	while (value_2 > 99)
	{
		value_2 -= 100;
		value_1 += 1;
	}
}

Pair* Money::operator +(Pair* other_pair)
{

	int rubles = 0;
	int pennies = 0;
	rubles = value_1 + other_pair->get_value_1();
	pennies = value_2 + other_pair->get_value_2();
	Pair* pmoney = new Money(rubles, pennies);
	return pmoney;
}

Pair* Money::operator -(Pair* other_pair)
{
	int rubles = 0;
	int pennies = 0;
	rubles = abs(value_1 - other_pair->get_value_1());
	pennies = abs(value_2 - other_pair->get_value_2());
	Pair* pmoney = new Money(rubles, pennies);
	return pmoney;
}

void Money::set_value_2(int val_2)
{
	value_2 = val_2;
	normalized();
}

std::ostream& operator <<(std::ostream& out, Money& money)
{
	out << std::to_string(money.get_value_1()) + "." + std::to_string(money.get_value_2()) + "\n";
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
