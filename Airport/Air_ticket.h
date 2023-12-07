#pragma once
#include <iostream>
#include <string>

struct Date
{
	int year, month, day;
	bool operator <(Date date_2)
	{

		if (year < date_2.year ||
			year == date_2.year &&
			month < date_2.month ||
			year == date_2.year &&
			month == date_2.month &&
			day < date_2.day)
			return 1;
		else
			return 0;
	}
};

struct Airport
{
	std::string destination, flight_number, aircraft_model, full_name;
	Date date;
};
