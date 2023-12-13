#pragma once
#include <string>

class Pair
{
protected:
	int value_1, value_2;
public:
	Pair();
	Pair(int value_1, int value_2);
	int get_value_1();
	int get_value_2();
	virtual void set_value_1(int val_1);
	virtual void set_value_2(int val_2);
	virtual Pair* operator +(Pair* other_pair) = 0;
	virtual Pair* operator -(Pair* other_pair) = 0;
	bool operator ==(Pair* other_pair);
	bool operator !=(Pair* other_pair);
};
