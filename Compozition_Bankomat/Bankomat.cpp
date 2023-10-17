#include "Bankomat_header.h"
#include "Money_header.h"


Bankomat::Bankomat()
{
	atm_id = std::to_string(rand());
}


Bankomat::Bankomat(int* a)
{
	atm_id = std::to_string(rand());
	cash = Money(a);
}


float Bankomat::calculate_amount()
{
	return cash.calculate_amount();
}


float Bankomat::add_money(int* other_money)
{
	for (int i = 0; i < 8; i++)
		cash.set_denomination_rubles(i, other_money[i]);
	for (int i = 0; i < 3; i++)
		cash.set_denomination_pennies(i, other_money[8 + i]);

	return calculate_amount();
}


int* Bankomat::withdraw_money(float money)
{
	float copy_sum = 0;
	int* copy_rubles = new int [11];
	for (int i = 0; i < 8; i++)
	{
		copy_sum += cash.get_nominal_rubles(i) * cash.get_denomination_rubles(i);
		copy_rubles[i] = cash.get_denomination_rubles(i);

	}
	for (int i = 0; i < 3; i++)
	{
		copy_sum += cash.get_nominal_pennies(i) * cash.get_denomination_pennies(i);
		copy_rubles[8 + i] = cash.get_denomination_rubles(i);

	}

	if (copy_sum < money)
		return copy_rubles;

	float summ = 0;

	for (int i = 7; i >= 0; i--)
	{
		while (copy_rubles[i] != 0 && summ + cash.get_nominal_rubles(i) <= money)
		{
			copy_rubles[i] -= 1;
			summ += cash.get_nominal_rubles(i);
		}
	}

	for (int i = 2; i >= 0; i--)
	{
		while (copy_rubles[i] != 0 && summ + cash.get_nominal_pennies(i) <= money)
		{
			copy_rubles[8 + i] -= 1;
			summ += cash.get_nominal_pennies(i);
		}
	}
	if (summ - money < 0.01)
	{
		for (int i = 0; i < 8; i++)
			cash.set_denomination_rubles(i, -(cash.get_denomination_rubles(i) - copy_rubles[i]));
		for (int i = 0; i < 3; i++)
			cash.set_denomination_pennies(i, -(cash.get_denomination_pennies(i) - copy_rubles[8 + i]));
	}
	else
	{
		for (int i = 0; i < 8; i++)
			copy_rubles[i] = cash.get_denomination_rubles(i);
		for (int i = 0; i < 3; i++)
			copy_rubles[i] = cash.get_denomination_pennies(i);
	}
	return copy_rubles;
}


int Bankomat::set_denomination_rubles(int index, int meaning)
{
	return cash.set_denomination_rubles(index, meaning);
}


int Bankomat::get_denomination_rubles(int index)
{
	return cash.get_denomination_rubles(index);
}


int Bankomat::get_denomination_pennies(int index)
{
	return cash.get_denomination_pennies(index);
}


int Bankomat::set_denomination_pennies(int index, int meaning)
{
	return cash.set_denomination_pennies(index, meaning);
}


std::string Bankomat::get_atm_id()
{
	return atm_id;
}


std::string Bankomat::to_string()
{
	return std::to_string(cash.calculate_amount());
}
