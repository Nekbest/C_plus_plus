#include <iostream>
#include"Triangle.h"

Triangle::Triangle(double AB, double BC, double CA, Angle A, Angle B, Angle C)
{
	sideAB = AB;
	sideBC = BC;
	sideCA = CA;
	angleA = A;
	angleB = B;
	angleC = C;
}

void Triangle::setSides(double AB, double BC, double CA)
{
	sideAB = AB;
	sideBC = BC;
	sideCA = CA;
}

void Triangle::setAngles(Angle A, Angle B, Angle C)
{
	angleA = A;
	angleB = B;
	angleC = C;
}

double Triangle::area() {
	return 0.5 * sideAB * sideBC * angleB.sinn();
}

double Triangle::perimeter() {
	return sideAB + sideBC + sideCA;
}

double Triangle::height(int sideIndex) {
	switch (sideIndex)
	{
		case 1:
			return 2 * area() / sideAB;
		case 2:
			return 2 * area() / sideBC;
		case 3:
			return 2 * area() / sideCA;
		default:
			return -1;
	}
}

std::string Triangle::type()
{
	if ((angleA.getDegAngle() == 90 && angleA.getMintAngle() == 0) || (angleB.getDegAngle() == 90 && angleB.getMintAngle() == 0) || (angleC.getDegAngle() == 90 && angleC.getMintAngle() == 0))
	{
		return "Прямоугольный";
	}
	else if ((sideAB == sideBC) && (sideBC == sideCA))
	{
		return "Равносторонний";
	}
	else if (sideAB == sideBC || sideBC == sideCA || sideAB == sideCA)
	{
		return "Равнобедренный";
	}
	else
	{
		return "Разносторонний";
	}
}

Triangle& Triangle::operator =(const Triangle& other)
{
	sideAB = other.get_AB();
	sideBC = other.get_BC();
	sideCA = other.get_CA();
	angleA = get_AngleA();
	angleB = get_AngleB();
	angleC = get_AngleC();
	return *this;
}

double Triangle::get_AB() const
{
	return sideAB;
}

double Triangle::get_BC() const
{
	return sideBC;
}

double Triangle::get_CA() const
{
	return sideCA;
}

Angle Triangle::get_AngleA()
{
	return angleA;
}

Angle Triangle::get_AngleB()
{
	return angleB;
}

Angle Triangle::get_AngleC()
{
	return angleC;
}
