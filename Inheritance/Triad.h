#pragma once
#include <iostream>
#include <string>

class Triad
{
protected:
	int value_1, value_2, value_3;
public:
	Triad();
	Triad(int val_1, int val_2, int val_3);
	Triad val_1_increase_1();
	Triad val_2_increase_1();
	Triad val_3_increase_1();
	int get_value_1();
	int get_value_2();
	int get_value_3();
	friend std::ostream& operator <<(std::ostream& out, const Triad& triad);
};
