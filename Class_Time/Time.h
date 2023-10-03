
#pragma once
#include <iostream>
#include <string>

class Time
{
private:
	int* hours;
	int* minutes;
	int* seconds;
public:
	Time();
	Time(const Time& other_time);
	~Time();
	Time(int h, int m, int s);
	Time(std::string time);
	Time(int s);
	Time operator -(const Time& other_time);
	Time operator +(int sec);
	Time operator -(int sec);
	int in_seconds() const;
	int in_seconds();
	int in_minutes();
	friend std::ostream& operator <<(std::ostream& out, const Time& time);
	friend std::istream& operator >>(std::istream& out, const Time& time);
	bool operator ==(const Time& other_time);
	bool operator >=(const Time& other_time);
	bool operator <=(const Time& other_time);
	bool operator >(const Time& other_time);
	bool operator <(const Time& other_time);
	bool operator !=(const Time& other_time);
	Time& operator =(const Time& other_time);
};
