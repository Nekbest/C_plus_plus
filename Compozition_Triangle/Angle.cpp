#pragma once
#include <iostream>
#include "Angle.h"
#include <cmath>
#include <string>

using namespace std;

Angle::Angle(int dAngle, int mAngle)
{
	deg = dAngle;
	mint = mAngle;
	toRange();
}

Angle::Angle()
{
	deg = mint = 0;
}

void Angle::setDegAngle(int dAngle)
{
	deg = dAngle;
	toRange();
}

void Angle::setMintAngle(int mAngle)
{
	mint = mAngle;
	toRange();
}

int Angle::getDegAngle() const
{
	return deg;
}

int Angle::getMintAngle() const
{
	return mint;
}

double Angle::toRad()
{
	return deg * pi / 180;
}

void Angle::toRange()
{
	if (mint < 0)
		mint *= -1;
	while (deg < 0)
		deg += 360;
	while (mint >= 60)
	{
		mint -= 60;
		deg += 1;
	}
	while (deg > 360)
		deg -= 360;
}

void Angle::increase(const Angle& other_angle)
{
	deg += other_angle.getDegAngle();
	mint += other_angle.getMintAngle();
	toRange();
}

void Angle::decrease(const Angle& other_angle)
{
	deg -= other_angle.getDegAngle();
	mint -= other_angle.getMintAngle();
	toRange();
}

Angle& Angle::operator=(const Angle& other)
{
	deg = other.getDegAngle();
	mint = other.getMintAngle();
	toRange();
	return *this;
}

double Angle::sinn()
{
	return sin((deg + mint / 60.0) * pi / 180);
}

bool Angle::operator ==(const Angle& other_angle)
{
	return (deg == other_angle.getDegAngle() && mint == other_angle.getMintAngle());
}

bool Angle::operator !=(const Angle& other_angle)
{
	return !(*this == other_angle);
}

bool Angle::operator >(const Angle& other_angle)
{
	return ((deg > other_angle.getDegAngle()) || (deg == other_angle.getDegAngle() && mint > other_angle.getMintAngle()));
}

bool Angle::operator <=(const Angle& other_angle)
{
	return !(*this > other_angle);
}

bool Angle::operator <(const Angle& other_angle)
{
	return ((deg < other_angle.getDegAngle()) || (deg == other_angle.getDegAngle() && mint < other_angle.getMintAngle()));
}

bool Angle::operator >=(const Angle& other_angle)
{
	return !(*this < other_angle);
}

std::ostream& operator <<(std::ostream& out, const Angle& angle)
{
	out << angle.getDegAngle() << "\260" << angle.getMintAngle() << "'" << "\n";
	return out;
}

std::istream& operator >>(std::istream& out, Angle& angle)
{
	int deg, mint;
	out >> deg >> mint;
	angle.setDegAngle(deg);
	angle.setMintAngle(deg);
	return out;
}

Angle Angle::operator+(const Angle& other_angle)
{
	Angle new_angle(deg + other_angle.getDegAngle(), mint + other_angle.getMintAngle());
	return new_angle;
}

Angle Angle::operator-(const Angle& other_angle)
{
	Angle new_angle(deg - other_angle.getDegAngle(), mint - other_angle.getMintAngle());
	return new_angle;
}
