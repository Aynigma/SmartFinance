#pragma once
#include <string>
#include <vector>
#include "Date.h"
#include "Article.h"


class Transaction
{
protected:
	unsigned int amount;
	Date date;

public:
	Transaction(unsigned int amount, Date date);
	Transaction(unsigned int amount);

	virtual ~Transaction();


	bool operator==(Transaction right);
	bool operator!=(Transaction right);


	virtual std::string toString();


	static void fundTransfert(unsigned int amount, Date date, Article source, Article recipient);


	unsigned int getAmount();

	Date getDate();


	static int getBudget(Article target, bool addChildren);
};

