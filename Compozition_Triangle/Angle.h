#pragma once

#include <cmath>
#include <string>

class Angle
{
private:
	const double pi = 3.1415926535;
	int deg;
	int mint;

public:
	Angle(int a, int b);
	Angle();
	void setDegAngle(int degrees);
	void setMintAngle(int minutes);
	int getDegAngle() const;
	int getMintAngle() const;
	double toRad();
	void toRange();
	void increase(const Angle& other_angle);
	void decrease(const Angle& other_angle);
	double sinn();
	Angle& operator=(const Angle& other_angle);
	bool operator==(const Angle& other_angle);
	bool operator>=(const Angle& other_angle);
	bool operator<=(const Angle& other_angle);
	bool operator>(const Angle& other_angle);
	bool operator<(const Angle& other_agnle);
	bool operator!=(const Angle& other_angle);
	friend std::ostream& operator <<(std::ostream& out, const Angle& angle);
	friend std::istream& operator >>(std::istream& out, Angle& angle);
	Angle operator+(const Angle& other_angle);
	Angle operator-(const Angle& other_angle);
};
