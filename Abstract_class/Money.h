#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Pair_abstract.h"


class Money: public Pair
{
public:
    Money();
    Money(double rubles, double pennies);
    std::string tostring() override;
    bool operator >(Pair* other_money);
    bool operator <(Pair* other_money);
    bool operator >=(Pair* other_money);
    bool operator <=(Pair* other_money);
    Pair* operator +(Pair* other_pair) override;
    Pair* operator -(Pair* other_pair) override;
    friend std::ostream& operator << (std::ostream& os, Money& money);
};
