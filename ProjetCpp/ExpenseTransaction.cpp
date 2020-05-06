#include "ExpenseTransaction.h"
#include <vector>

std::vector<ExpenseTransaction> ExpenseTransaction::expenseTransactions = {};

ExpenseTransaction::ExpenseTransaction(unsigned int amount, Date date, Article source, Provider recipient) : Transaction(amount, date)
{
	this->source = source;
	this->recipient = recipient;
	this->expenseTransactions.push_back(*this);
}

ExpenseTransaction::~ExpenseTransaction()
{
}

bool ExpenseTransaction::operator==(ExpenseTransaction right)
{
	return (this->amount == right.amount &&
		this->date == right.date &&
		this->source == right.source && 
		this-> recipient == right.recipient);
}

bool ExpenseTransaction::operator!=(ExpenseTransaction right)
{
	return !(*this == right);
}

std::string ExpenseTransaction::toString()
{
	std::string output("(");
	output += this->date.toString() + ", ";
	output += std::to_string(this->amount) + ", ";
	output += this->source.toString() + ", ";
	output += this->recipient.toString();
	output += ")";
	return output;
}

std::vector<ExpenseTransaction> ExpenseTransaction::getExpenseTransactions()
{
	return ExpenseTransaction::expenseTransactions;
}

Article ExpenseTransaction::getSource()
{
	return this->source;
}

Provider ExpenseTransaction::getRecipient()
{
	return this->recipient;
}
