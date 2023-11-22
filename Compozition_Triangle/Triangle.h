#pragma once
#include <iostream>
#include"Angle.h"

class Triangle {
private:
	double sideAB;
	double sideBC;
	double sideCA;
	Angle angleA;
	Angle angleB;
	Angle angleC;

public:
	Triangle(double AB, double BC, double CA, Angle A, Angle B, Angle C);
	void setSides(double AB, double BC, double CA);
	void setAngles(Angle A, Angle B, Angle C);
	double get_AB() const;
	double get_BC() const;
	double get_CA() const;
	Angle get_AngleA();
	Angle get_AngleB();
	Angle get_AngleC();
	double area();
	double perimeter();
	double height(int sideIndex);
	std::string type();
	Triangle& operator=(const Triangle& other);
};
