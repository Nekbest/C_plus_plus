#include "Pair_abstract.h"

Pair::Pair()
{
	value_1 = 0;
	value_2 = 0;
}

Pair::Pair(double val_1, double val_2)
{
	value_1 = val_1;
	value_2 = val_2;
}

double Pair::get_value_1()
{
	return value_1;
}

double Pair::get_value_2()
{
	return value_2;
}

void Pair::set_value_1(double val_1)
{

	value_1 = val_1;
}

void Pair::set_value_2(double val_2)
{
	value_2 = val_2;
}

bool Pair::operator ==(Pair* other_pair)
{
	return ((value_1 == other_pair->get_value_1()) && value_2 == other_pair->get_value_2());
}

bool Pair::operator !=(Pair* other_pair)
{
	return !(this == other_pair);
}
