#pragma once
#include <iostream>
#include <iomanip>
#include <string>


class Money
{
private:
    int denominations_rubles[8];
    const int nominal_rubles[8] = { 1, 2, 5, 10, 50, 100, 500, 1000 };
    int denominations_pennies[3];
    const float nominal_pennies[3] = { 0.01f, 0.05f, 0.1f };
public:
    Money();
    Money(int* a);
    Money& operator =(const Money& other_money);
    float calculate_amount();
    float add_up_amount(float other_money);
    float difference_amount(float other_money);
    int get_denomination_rubles(int index) const;
    int get_denomination_pennies(int index) const;
    int get_nominal_rubles(int index) const;
    float get_nominal_pennies(int index) const;
    int set_denomination_rubles(int index, int meaning);
    int set_denomination_pennies(int index, int meaning);
    std::string toString();
};
