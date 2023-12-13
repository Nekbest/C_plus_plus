#include <iostream>
#include "Fraction.h"
#include "Money.h"

int main()
{
    Pair* pfraction_1 = new Fraction(1, 2);
    Pair* pfraction_2 = new Fraction(1, 2);
    Pair* pfraction_3 = new Fraction(1, 5);
    Pair* pfraction_4 = *pfraction_1 + pfraction_2;
    Pair* pfraction_5 = *pfraction_1 + pfraction_3;
    Fraction* pfract_1 = dynamic_cast<Fraction*>(pfraction_4);
    Fraction* pfract_2 = dynamic_cast<Fraction*>(pfraction_5);
    std::cout << *pfract_1;
    std::cout << *pfract_2;
    Fraction fract = *pfract_2 * (*pfract_2);
    std::cout << fract;
    fract = fract / (*pfract_2);
    std::cout << fract;
    Pair* pmoney_1 = new Money(1000, 70);
    Pair* pmoney_2 = new Money(50, 80);
    Pair* pmoney_3 = *pmoney_1 + pmoney_2;
    Money* pmon_1 = dynamic_cast<Money*>(pmoney_3);
    std::cout << *pmon_1;
    Pair* pmoney_4 = *pmoney_1 - pmoney_2;
    Money* pmon_2 = dynamic_cast<Money*>(pmoney_4);
    std::cout << *pmon_2;
    std::cout << (*pmon_1 == pmoney_1) << "\n";
    std::cout << (*pmon_1 >= pmoney_1) << "\n";
}
