#include "Date.h"
#include <ctime>

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date()
{
	*this = Date::today();
}

Date::~Date()
{
}

std::string Date::toString()
{
	std::string output("(");
	output += std::to_string(this->year) + "-";
	output += std::to_string(this->month) + "-";
	output += std::to_string(this->day) + ")";
	return output;
}

bool Date::operator==(Date right)
{
	return (this->year == right.year &&
		this->month == right.month &&
		this->day == right.day);
}

bool Date::operator!=(Date right)
{
	return !(*this == right);
}

bool Date::operator>(Date right)
{
	if (this->year > right.year)
	{
		return true;
	}
	else if(this->year == right.year)
	{
		if (this->month > right.month)
		{
			return true;
		}
		else if(this->month == right.month)
		{
			if (this->day > right.day) return true;
		}
	}

	return false;
}

bool Date::operator>=(Date right)
{
	return (*this > right ||*this == right);
}

bool Date::operator<(Date right)
{
	return (right > *this);
}

bool Date::operator<=(Date right)
{
	return (*this < right || *this == right);
}



Date Date::today()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
	return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}
