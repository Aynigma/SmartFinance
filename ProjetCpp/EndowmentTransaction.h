#pragma once
#include "Transaction.h"
#include "Article.h"
class EndowmentTransaction :
	public Transaction
{
private:
	static std::vector<EndowmentTransaction> endowmentTransactions;
	Article recipient;
	bool isInitial;

public:
	EndowmentTransaction(unsigned int amount, Date date, Article recipient, bool isInitial);
	EndowmentTransaction(unsigned int amount, Date date, Article recipient);

	~EndowmentTransaction();


	bool operator==(EndowmentTransaction right);
	bool operator!=(EndowmentTransaction right);


	std::string toString();


	static std::vector<EndowmentTransaction> getEndowmentTransactions();
	Article getRecipient();
	bool getIsInitial();
};

