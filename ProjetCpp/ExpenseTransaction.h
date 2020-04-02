#pragma once
#include "Transaction.h"
#include "Article.h"
#include "Provider.h"
#include "Date.h"

class ExpenseTransaction :
	public Transaction
{
private:
	Article source;
	Provider recipient;

public:
	ExpenseTransaction(unsigned int amount, Date date, Article source, Provider recipient);

	~ExpenseTransaction();


	bool operator==(ExpenseTransaction right);
	bool operator!=(ExpenseTransaction right);


	std::string toString();


	Article getSource();
	Provider getRecipient();

};

