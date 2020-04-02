#pragma once
#include <string>
#include <vector>
#include "Date.h"
#include "Article.h"


//TODO method to calculate budget of an article(global(with subs) or local)

class Transaction
{
private:
	//static std::vector<Transaction> transactions;

protected:
	unsigned int amount;
	Date date;
	static std::vector<Transaction> transactions;

public:
	Transaction(unsigned int amount, Date date);
	Transaction(unsigned int amount);

	~Transaction();


	bool operator==(Transaction right);
	bool operator!=(Transaction right);


	std::string toString();


	void fundTransfert(unsigned int amount, Date date, Article source, Article recipient);


	std::vector<Transaction>getTransactions();

	unsigned int getAmount();

	Date getDate();


	static unsigned int getBudget(Article target, bool addChildren);
};

