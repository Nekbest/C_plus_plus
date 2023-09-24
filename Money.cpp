#include "Money.h"


Money::Money(int* a)
{
	for (int i = 0; i < 8; ++i)
	{
		denominations_rubles[i] = a[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		denominations_pennies[i] = a[i+8];
	}
}


float Money::calculate_amount()
{
	float summ = 0;
	for (int i = 0; i < 8; i++)
		summ += nominal_rubles[i] * denominations_rubles[i];
	for (int i = 0; i < 3; i++)
		summ += nominal_pennies[i] * denominations_pennies[i];

	return summ;
}


float Money::add_up_amount(float other_sum)
{
	float sum_amount;

	sum_amount = 0;
	sum_amount += calculate_amount() + other_sum;

	return sum_amount;
}


float Money::difference_amount(float other_sum)
{
	float dif_amount = 0;
	float summ = calculate_amount();
	if (summ >= other_sum)
		dif_amount = summ - other_sum;
	else
		dif_amount = other_sum - summ;

	return dif_amount;
}


int Money::get_denomination_ruble(int index)
{
	return denominations_rubles[index];
}


int Money::get_denomination_pennie(int index)
{
	return denominations_pennies[index];
}


std::string Money::toString()
{
	std::string data;
	for (int i = 0; i < 8; i++)
		data += std::to_string(denominations_rubles[i]) + " ";
	data += "\n";
	for (int i = 0; i < 3; i++)
		data += std::to_string(denominations_pennies[i]) + " ";
	return data;

}


int Money::set_denomination_ruble(int index, int meaning)
{
	switch (index)
	{
		case 0:
			denominations_rubles[0] = meaning;
		case 1:
			denominations_rubles[1] = meaning;
		case 2:
				denominations_rubles[2] = meaning;
		case 3:
				denominations_rubles[3] = meaning;
		case 4:
			denominations_rubles[4] = meaning;
		case 5:
			denominations_rubles[5] = meaning;
		case 6:
			denominations_rubles[6] = meaning;
		case 7:
			denominations_rubles[7] = meaning;
	}
	return denominations_rubles[index];
}


int Money::set_denomination_pennie(int index, int meaning)
{
	switch (index)
	{
	case 0:
		denominations_pennies[0] = meaning;
	case 1:
		denominations_pennies[1] = meaning;
	case 2:
		denominations_pennies[2] = meaning;
	}
	return denominations_pennies[index];
}