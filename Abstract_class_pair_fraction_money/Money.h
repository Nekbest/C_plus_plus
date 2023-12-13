#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Pair_abstract.h"


class Money : public Pair
{
    void normalized();
public:
    Money();
    void set_value_2(int val_2) override;
    Money(int rubles, int pennies);
    bool operator >(Pair* other_money);
    bool operator <(Pair* other_money);
    bool operator >=(Pair* other_money);
    bool operator <=(Pair* other_money);
    Pair* operator +(Pair* other_pair) override;
    Pair* operator -(Pair* other_pair) override;
    friend std::ostream& operator << (std::ostream& os, Money& money);
};
