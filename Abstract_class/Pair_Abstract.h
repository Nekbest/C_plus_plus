#pragma once
#include <string>

class Pair
{
protected:
	double value_1, value_2;
public:
	Pair();
	Pair(double value_1, double value_2);
	double get_value_1();
	double get_value_2(); 
	void set_value_1(double val_1);
	void set_value_2(double val_2);
	virtual Pair* operator +(Pair* other_pair) = 0;
	virtual Pair* operator -(Pair* other_pair) = 0;
	bool operator ==(Pair* other_pair);
	bool operator !=(Pair* other_pair);
	virtual std::string tostring() = 0;
};
