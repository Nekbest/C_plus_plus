#include "Triad.h"
#include <iostream>

Triad::Triad()
{
	value_1 = 0;
	value_2 = 0;
	value_3 = 0;
}


Triad::Triad(int val_1, int val_2, int val_3)
{
	value_1 = val_1;
	value_2 = val_2;
	value_3 = val_3;
}

Triad Triad::Val1Increase1()
{
	++value_1;
	return Triad(value_1, value_2, value_3);
}

Triad Triad::Val2Increase1()
{
	++value_2;
	return Triad(value_1, value_2, value_3);
}

Triad Triad::Val3Increase1()
{
	++value_3;
	return Triad(value_1, value_2, value_3);
}


std::ostream& operator <<(std::ostream& out, const Triad& triad)
{
	out << std::to_string(triad.value_1) << ":" << std::to_string(triad.value_2) << ":" << std::to_string(triad.value_3) << "\n";
	return out;
}

int Triad::GetValue1() const
{
	return value_1;
}

int Triad::GetValue2() const
{
	return value_2;
}

int Triad::GetValue3() const
{
	return value_3;
}

void Triad::SetValue1(int year)
{
	value_1 = year;
}

void Triad::SetValue2(int month)
{
	value_2 = month;
}

void Triad::SetValue3(int days)
{
	value_3 = days;
}
