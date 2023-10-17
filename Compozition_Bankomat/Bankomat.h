#pragma once
#include <iostream>
#include <string>
#include "Money.h"


class Bankomat
{
private:
	std::string atm_id;
	Money cash;
public:
	Bankomat();
	Bankomat(int* a);
	float calculate_amount();
	float add_money(int* other_money);
	int* withdraw_money(float money);
	int set_denomination_rubles(int index, int meaning);
	int get_denomination_rubles(int index);
	int set_denomination_pennies(int index, int meaning);
	int get_denomination_pennies(int index);
	std::string get_atm_id();
	std::string to_string();
};
