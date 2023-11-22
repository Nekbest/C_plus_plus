#include <iostream>

#include <iostream>
#include "Triangle.h"


int main()
{
    setlocale(LC_ALL, "RU");
    Angle angle_1(120, 0), angle_2(30, 0), angle_3(30, 0);
    std::cout << angle_1 + angle_2 + angle_3;
    Triangle triangle(1, 1, 1, angle_1, angle_2, angle_3);
    std::cout << triangle.type() << "\n";
    std::cout << triangle.area() << "\n";
    std::cout << triangle.perimeter() << "\n";
}
