#pragma once
#include <iostream>
#include <iomanip>
#include <string>


class Money
{
private:
    int denominations_rubles[8];
    const int nominal_rubles[8] = { 1, 2, 5, 10, 50, 100, 500, 1000 };

public:
    Money();
    Money(int* a);
    Money& operator =(const Money& other_money);
    int calculate_amount();
    int add_up_amount(int other_money);
    int difference_amount(int other_money);
    int get_denomination_rubles(int index) const;
    int get_nominal_rubles(int index) const;
    int set_denomination_rubles(int index, int meaning);
    std::string toString();
};
