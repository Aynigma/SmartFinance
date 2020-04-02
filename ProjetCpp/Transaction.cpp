#include "Transaction.h"
#include "ExpenseTransaction.h"
#include "EndowmentTransaction.h"
#include "Provider.h"
#include "Article.h"
#include <vector>

std::vector<Transaction> Transaction::transactions;

Transaction::Transaction(unsigned int amount, Date date)
{
	this->amount = amount;
	this->date = date;
	this->transactions.push_back(*this);
}

Transaction::Transaction(unsigned int amount)
{
	this->amount = amount;
	this->date = Date::today();
	this->transactions.push_back(*this);
}

Transaction::~Transaction()
{
}


bool Transaction::operator==(Transaction right)
{
	return (this->amount == right.amount && this->date == right.date);
}

bool Transaction::operator!=(Transaction right)
{
	return !(*this == right);
}


std::string Transaction::toString()
{
	std::string output("(");
	output += this->date.toString() + ", ";
	output += std::to_string(this->amount) + "€";
	output += ")";
	return output;
}


void Transaction::fundTransfert(unsigned int amount, Date date, Article source, Article recipient)
{
	ExpenseTransaction expense(amount, date, source, Provider::internal);
	EndowmentTransaction endowment(amount, date, recipient, false);
}

std::vector<Transaction> Transaction::getTransactions()
{
	return this->transactions;
}

unsigned int Transaction::getAmount()
{
	return this->amount;
}

Date Transaction::getDate()
{
	return this->date;
}
