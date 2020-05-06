#include "EndowmentTransaction.h"

std::vector<EndowmentTransaction> EndowmentTransaction::endowmentTransactions = {};

EndowmentTransaction::EndowmentTransaction(unsigned int amount, Date date, Article recipient, bool isInitial) : Transaction(amount, date)
{
	this->recipient = recipient;
	this->isInitial = isInitial;
	this->endowmentTransactions.push_back(*this);
}

EndowmentTransaction::EndowmentTransaction(unsigned int amount, Date date, Article recipient) : Transaction(amount, date)
{
	this->recipient = recipient;
	this->isInitial = false;
	this->endowmentTransactions.push_back(*this);
}

EndowmentTransaction::~EndowmentTransaction()
{
}

bool EndowmentTransaction::operator==(EndowmentTransaction right)
{
	return (this->amount == right.amount &&
		this->date == right.date &&
		this->recipient == right.recipient &&
		this->isInitial == right.isInitial);
}

bool EndowmentTransaction::operator!=(EndowmentTransaction right)
{
	return !(*this == right);
}


std::string EndowmentTransaction::toString()
{
	std::string output("(");
	output += this->date.toString() + ", ";
	output += std::to_string(this->amount) + ", ";
	output += recipient.toString() + ", ";
	output += (isInitial ? "initial" : "ponctual");
	output += ")";
	return output;
}

std::vector<EndowmentTransaction> EndowmentTransaction::getEndowmentTransactions()
{
	return EndowmentTransaction::endowmentTransactions;
}

Article EndowmentTransaction::getRecipient()
{
	return this->recipient;
}

bool EndowmentTransaction::getIsInitial()
{
	return this->isInitial;
}
