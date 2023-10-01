#include "class_Time.h"

Time::Time()
{
	hours = new int(0);
	minutes = new int(0);
	seconds = new int(0);
}


Time::~Time()
{
	delete hours;
	delete minutes;
	delete seconds;
}


Time::Time(const Time& other_time)
{
	hours = new int(*other_time.hours);
	minutes = new int(*other_time.minutes);
	seconds = new int(*other_time.seconds);
}


Time::Time(int h, int m, int s)
{
	hours = new int(h);
	minutes = new int(m);
	seconds = new int(s);
}


Time::Time(std::string time)
{
	hours = new int(stoi(time.substr(0, 2)));
	minutes = new int(stoi(time.substr(3, 2)));
	seconds = new int(stoi(time.substr(6, 2)));
}


Time::Time(int sec)
{
	hours = new int(sec / 60 / 60);
	minutes = new int(sec / 60 - *hours * 60);
	seconds = new int(sec - *hours * 60 * 60 - *minutes * 60);
}


Time Time::operator -(const Time& other_time)
{
	int resoult = this->in_seconds() - other_time.in_seconds();
	return Time(resoult);
}


Time Time::operator +(int sec)
{
	int resoult = this->in_seconds() + sec;
	return Time(resoult);
}


Time Time::operator -(int sec)
{
	int resoult = in_seconds() - sec;
	return Time(resoult);
}


int Time::in_seconds() const
{
	int result = *hours * 60 * 60 + *minutes * 60 + *seconds;
	return result;
}


int Time::in_seconds()
{
	int result = *hours * 60 * 60 + *minutes * 60 + *seconds;
	return result;
}


int Time::in_minutes()
{
	int result = *hours * 60 + *minutes;
	return result;
}


std::ostream& operator <<(std::ostream& out, const Time& time)
{
	out << std::to_string(*time.hours) << ":" << std::to_string(*time.minutes) << ":" << std::to_string(*time.seconds);
	return out;
}


std::istream& operator >>(std::istream& out, const Time& time)
{
	out >> *time.hours >> *time.minutes >> *time.seconds;
	return out;
}


bool Time::operator ==(const Time& other_time)
{
	return (this->in_seconds() == other_time.in_seconds());
}


bool Time::operator >=(const Time& other_time)
{
	return (this->in_seconds() >= other_time.in_seconds());
}


bool Time::operator <=(const Time& other_time)
{
	return (this->in_seconds() <= other_time.in_seconds());
}


bool Time::operator >(const Time& other_time)
{
	return (this->in_seconds() > other_time.in_seconds());
}


bool Time::operator <(const Time& other_time)
{
	return (this->in_seconds() < other_time.in_seconds());
}


bool Time::operator !=(const Time& other_time)
{
	return (this->in_seconds() != other_time.in_seconds());
}


Time& Time::operator =(const Time& other_time)
{
	*hours = *other_time.hours;
	*minutes = *other_time.minutes;
	*seconds = *other_time.seconds;
	return *this;
	/*return Time(other_time.in_seconds());*/
}