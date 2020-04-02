#pragma once
#include <string>
class Date
{
private:

	unsigned int day;
	unsigned int month;
	unsigned int year;

public:
	Date(unsigned int day, unsigned int month, unsigned int year);
	Date();

	~Date();


	std::string toString();


	bool operator==(Date right);
	bool operator!=(Date right);
	bool operator>(Date right);
	bool operator>=(Date right);
	bool operator<(Date right);
	bool operator<=(Date right);


	static Date today();
};

