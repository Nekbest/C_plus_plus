#pragma once
#include "Triad.h"


class Date : public Triad
{
public:
	Date(int year = 0, int month = 0, int day = 0);
    int GetDaysInFeb();
    int GetDaysInMonth();
    int GetDaysInYear();
    bool IsCorrectDate();
    Date Val1Increase1();
    Date Val2Increase1();
    Date Val3Increase1();
    Date Val3IncreaseN(int n);
    void NormalizeDate();
    void SetValue1(int year);
    void SetValue2(int month);
    void SetValue3(int days);
    friend std::ostream& operator <<(std::ostream& out, const Date& time);
};
