#pragma once
#include "Transaction.h"
#include "Article.h"
#include "Provider.h"
#include "Date.h"

class ExpenseTransaction :
	public Transaction
{
private:
	static std::vector<ExpenseTransaction> expenseTransactions;
	Article source;
	Provider recipient;

public:
	ExpenseTransaction(unsigned int amount, Date date, Article source, Provider recipient);

	~ExpenseTransaction();


	bool operator==(ExpenseTransaction right);
	bool operator!=(ExpenseTransaction right);


	std::string toString();


	static std::vector<ExpenseTransaction> getExpenseTransactions();
	Article getSource();
	Provider getRecipient();

};

