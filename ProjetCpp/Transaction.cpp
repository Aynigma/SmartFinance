#include "Transaction.h"
#include "ExpenseTransaction.h"
#include "EndowmentTransaction.h"
#include "Provider.h"
#include "Article.h"
#include <vector>

Transaction::Transaction(unsigned int amount, Date date)
{
	this->amount = amount;
	this->date = date;
}

Transaction::Transaction(unsigned int amount)
{
	this->amount = amount;
	this->date = Date::today();
}

Transaction::~Transaction(){}


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
	output += std::to_string(this->amount);
	output += ")";
	return output;
}


void Transaction::fundTransfert(unsigned int amount, Date date, Article source, Article recipient)
{
	EndowmentTransaction endowment(amount, date, recipient, false);
	ExpenseTransaction expense(amount, date, source, Provider::internal);
}



unsigned int Transaction::getAmount()
{
	return this->amount;
}

Date Transaction::getDate()
{
	return this->date;
}

int Transaction::getBudget(Article target, bool addChildren)
{
	int sum = 0;

	for (size_t i = 0; i < EndowmentTransaction::getEndowmentTransactions().size(); i++)
	{
		EndowmentTransaction endowmentTransaction = EndowmentTransaction::getEndowmentTransactions().at(i);
		if (endowmentTransaction.getRecipient() == target)
		{
			sum += endowmentTransaction.getAmount();
		}
	}

	for (size_t i = 0; i < ExpenseTransaction::getExpenseTransactions().size(); i++)
	{
		ExpenseTransaction expenseTransaction = ExpenseTransaction::getExpenseTransactions().at(i);
		if (expenseTransaction.getSource() == target)
		{
			sum -= expenseTransaction.getAmount();
		}
	}

	if (addChildren)
	{
		std::vector<Article> children = target.getChildren();
		for (Article child : children)
		{
			sum += getBudget(child, true);
		}
	}

	return sum;
}
