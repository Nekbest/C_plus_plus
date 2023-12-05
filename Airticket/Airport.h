#include <iostream>
#include <string>

struct Date
{
	int year, month, day;
};

struct Airport
{
	std::string destination, flight_number, aircraft_model, full_name;
	Date date;
};
