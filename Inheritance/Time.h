#pragma once
#include "Triad.h"
#include <iostream>
#include <string>

class Time: public Triad
{
public:
	Time();
	Time(int h, int m, int s);
	Time(Triad& triad);
	int in_seconds() const;
	int in_minutes();
	friend std::ostream& operator <<(std::ostream& out, const Time& time);
	Time val_1_increase_1();
	Time val_2_increase_1();
	Time val_3_increase_1();
	Time val_2_increase_n(int n);
	Time val_3_increase_n(int n);
	void normalized();

};
