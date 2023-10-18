#include "Bankomat.h"


Bankomat::Bankomat()
{
	atm_id = std::to_string(rand());
}


Bankomat::Bankomat(int* a)
{
	atm_id = std::to_string(rand());
	cash = Money(a);
}


int Bankomat::calculate_amount()
{
	return cash.calculate_amount();
}


int Bankomat::add_money(int* other_money)
{
	for (int i = 0; i < 8; i++)
		cash.set_denomination_rubles(i, other_money[i]);

	return calculate_amount();
}


int* Bankomat::withdraw_money(int money)
{
	int copy_sum = 0;
	int* copy_rubles = new int [8];
	for (int i = 0; i < 8; i++)
	{
		copy_sum += cash.get_nominal_rubles(i) * cash.get_denomination_rubles(i);
		copy_rubles[i] = cash.get_denomination_rubles(i);

	}


	if (copy_sum < money || money < 100)
		return copy_rubles;

	int summ = 0;

	for (int i = 7; i >= 0; i--)
	{
		while (copy_rubles[i] != 0 && summ + cash.get_nominal_rubles(i) <= money)
		{
			copy_rubles[i] -= 1;
			summ += cash.get_nominal_rubles(i);
		}
	}

	if (summ != money)
	{
		for (int i = 0; i < 8; i++)
			cash.set_denomination_rubles(i, -(cash.get_denomination_rubles(i) - copy_rubles[i]));
	}
	else
	{
		for (int i = 0; i < 8; i++)
			copy_rubles[i] = cash.get_denomination_rubles(i);
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


std::string Bankomat::get_atm_id()
{
	return atm_id;
}


std::string Bankomat::to_string()
{
	return std::to_string(cash.calculate_amount());
}
