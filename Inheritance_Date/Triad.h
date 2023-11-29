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
	Triad Val1Increase1();
	Triad Val2Increase1();
	Triad Val3Increase1();
	void SetValue1(int year);
	void SetValue2(int month);
	void SetValue3(int days);
	int GetValue1() const;
	int GetValue2() const;
	int GetValue3() const;
	friend std::ostream& operator <<(std::ostream& out, const Triad& triad);
};
