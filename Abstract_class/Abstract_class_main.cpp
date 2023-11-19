#include <iostream>
#include "Complex.h"
#include "Money.h"
#include <sstream>

int main()
{
    Pair* pcomplex_1 = new Complex(64, 5);
    Pair* pcomplex_2 = new Complex(1, 7);
    Pair* pcomplex_3 = *pcomplex_1 + pcomplex_2;
    Complex* pcompcomplex_1 = dynamic_cast<Complex*>(pcomplex_3);
    std::cout << *pcompcomplex_1;
    Pair* pcomplex_4 = *pcompcomplex_1 * pcomplex_2;
    Complex* pcompcomplex_2 = dynamic_cast<Complex*>(pcomplex_4);
    std::cout << *pcompcomplex_2;
    Pair* pmoney_1 = new Money(1000, 0.70);
    Pair* pmoney_2 = new Money(50, 0.80);
    Pair* pmoney_3 = *pmoney_1 + pmoney_2;
    Money* pmoneymoney_1 = dynamic_cast<Money*>(pmoney_3);
    std::cout << *pmoneymoney_1;
    Pair* pmoney_4 = *pmoney_1 - pmoney_2;
    Money* pmoneymoney_2 = dynamic_cast<Money*>(pmoney_4);
    std::cout << *pmoneymoney_2;
    std::cout << (* pmoneymoney_1 == pmoney_1) << "\n";
    std::cout << (*pmoneymoney_1 >= pmoney_1) << "\n";
}
