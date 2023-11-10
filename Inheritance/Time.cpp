	#include "Time.h"

	Time::Time()
	{
		value_1 = 0;
		value_2 = 0;
		value_3 = 0;
	}


	Time::Time(int h, int m, int s)
	{
		value_1 = h;
		value_2 = m;
		value_3 = s;
		normalized();
	}


	int Time::in_seconds() const
	{
		int result = value_1 * 60 * 60 + value_2 * 60 + value_3;
		return result;
	}


	int Time::in_minutes()
	{
		int result = value_1 * 60 + value_2;
		return result;
	}


	std::ostream& operator <<(std::ostream& out, const Time& time)
	{
		out << std::to_string(time.value_1) << ":" << std::to_string(time.value_2) << ":" << std::to_string(time.value_3) << "\n";
		return out;
	}


	Time Time::val_1_increase_1()
	{
		Triad triad = Triad::val_1_increase_1();
		Time res(triad.get_value_1(), triad.get_value_2(), triad.get_value_3());
		res.normalized();
		return res;
	}


	Time Time::val_2_increase_1()
	{
		Triad triad = Triad::val_2_increase_1();
		Time res(triad.get_value_1(), triad.get_value_2(), triad.get_value_3());
		res.normalized();
		return res;
	}

	Time Time::val_3_increase_1()
	{
		Triad triad = Triad::val_3_increase_1();
		Time res(triad.get_value_1(), triad.get_value_2(), triad.get_value_3());
		res.normalized();
		return res;
	}


	Time Time::val_2_increase_n(int n)
	{
		Triad triad = Triad::val_2_increase_1();
		this->value_2 = triad.get_value_2() + (n - 1);
		this->normalized();
		return *this;
	}


	Time Time::val_3_increase_n(int n)
	{
		Triad triad = Triad::val_3_increase_1();
		this->value_2 = triad.get_value_3() + (n - 1);
		this->normalized();
		return *this;
	}


	void Time::normalized()
	{
		int sec;
		sec = in_seconds();
		value_1 = sec / 60 / 60;
		value_2 = sec / 60 - value_1 * 60;
		value_3 = sec - value_1 * 60 * 60 - value_2 * 60;
	}
