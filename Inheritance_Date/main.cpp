#include <iostream>
#include "Date.h"

int main()
{
    Date date_1(-2012, 1, 1);
    std::cout << date_1;
    date_1.Val3IncreaseN(731);
    std::cout << date_1;
    date_1.Val1Increase1();
    std::cout << date_1;
    date_1.Val2Increase1();
    std::cout << date_1;
    date_1.Val3Increase1();
    std::cout << date_1;
    date_1.SetValue1(2023);
    std::cout << date_1;
}
