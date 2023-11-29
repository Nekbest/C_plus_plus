#include "Date.h"

Date::Date(int year, int month, int day)
{
    value_1 = year;
    value_2 = month;
    value_3 = day;
    NormalizeDate();
}

int Date::GetDaysInFeb()
{
    if ((!(value_1 % 4) && (value_1 % 100)) || !(value_3 % 400))
        return 29;
    return 28;
}


int Date::GetDaysInMonth()
{
    switch (value_2) 
    {
        case 2:
            return GetDaysInFeb();
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        default:
            return 30;
    }
}


int Date::GetDaysInYear()
{
    return 337 + GetDaysInFeb();
}


bool Date::IsCorrectDate()
{
    return value_2 <= 12 && value_2 >= 1 && value_3 <= GetDaysInMonth() && value_3 > 0;
}


Date Date::Val1Increase1()
{
    Triad triad = Triad::Val1Increase1();
    Date res(triad.GetValue1(), triad.GetValue2(), triad.GetValue3());
    res.NormalizeDate();;
    return res;
}


Date Date::Val2Increase1()
{
    Triad triad = Triad::Val2Increase1();
    Date res(triad.GetValue1(), triad.GetValue2(), triad.GetValue3());
    res.NormalizeDate();
    return res;
}

Date Date::Val3Increase1()
{
    Triad triad = Triad::Val3Increase1();
    Date res(triad.GetValue1(), triad.GetValue2(), triad.GetValue3());
    res.NormalizeDate();
    return res;
}

void Date::NormalizeDate() 
{
    if (value_1 < 0)
        value_1 *= -1;
    if (value_2 < 0)
        value_2 *= -1;
    if (value_3 < 0)
        value_3 *= -1;
    while (!IsCorrectDate())
    {
        if (value_2 == 1 || value_2 == 3 || value_2 == 5 || value_2 == 7 || value_2 == 8 || value_2 == 10 || value_2 == 12)
        {
            value_2++;
            value_3 = value_3 - 31;
        }
        else if (value_2 == 4 || value_2 == 6 || value_2 == 9 || value_2 == 11)
        {
            value_2++;
            value_3 = value_3 - 30;
        }
        else if (value_2 == 2 && value_3 > GetDaysInFeb())
        {
            value_2++;
            value_3 = value_3 - GetDaysInFeb();
            NormalizeDate();
        }
        else if (value_2 > 12)
        {
            value_1++;
            value_2 = value_2 - 12;
            NormalizeDate();
        }
    }
}

Date Date::Val3IncreaseN(int n)
{
    value_3 += n;
    NormalizeDate();
    return *this;
}

std::ostream& operator <<(std::ostream& out, const Date& date)
{
    out << std::to_string(date.GetValue1()) << "." << std::to_string(date.GetValue2()) << "." << std::to_string(date.GetValue3()) << "\n";
    return out;
}

void Date::SetValue1(int year)
{
    Triad::SetValue1(year);
    NormalizeDate();
}

void Date::SetValue2(int month)
{
    Triad::SetValue2(month);
    NormalizeDate();
}

void Date::SetValue3(int days)
{
    Triad::SetValue3(days);
    NormalizeDate();
}
