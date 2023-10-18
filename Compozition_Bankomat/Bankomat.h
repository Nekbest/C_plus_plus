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
	int calculate_amount();
	int add_money(int* other_money);
	int* withdraw_money(int money);
	int set_denomination_rubles(int index, int meaning);
	int get_denomination_rubles(int index);
	std::string get_atm_id();
	std::string to_string();
};
