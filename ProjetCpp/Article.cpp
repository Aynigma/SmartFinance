#include "Article.h"


Article::Article()
{
	this->content = "";
	this->children = {};
}

Article::Article(std::string content)
{
	this->content = content;
	this->children = {};
}

Article::Article(std::string content, Article child)
{
	this->content = content;
	this->children = std::vector<Article>{ child };
}

Article::Article(std::string content, std::vector<Article> children)
{
	this->content = content;
	this->children = children;
}

Article::~Article()
{
}

bool Article::operator==(Article right)
{

	if (this->content != right.content || this->children.size() != right.children.size())
	{
		return false;
	}

	for (size_t i = 0; i < this->children.size(); i++)
	{
		if ((this->children.at(i) != right.children.at(i))) {
			return false;
		}
	}
	
	return true;
}

bool Article::operator!=(Article right) { return !(*this == right); }


std::string Article::toString()
{
	std::string output("(" + this->content);
	if (this->children.size() > 0)
	{
		output += +"; ";
		for (size_t i = 0; i < this->children.size() - 1; i++)
		{
			Article child = this->children.at(i);
			output += child.toString() + ",";
		}
		output += this->children.at(this->children.size() - 1).toString();
	}

	output += ")";

	return output;
}

std::string Article::toHTMLString()
{
	std::string output("<div class='article'><span>" + this->content + "</span>");
	if (this->children.size() > 0)
	{
		output += +"<ol>";
		for (size_t i = 0; i < this->children.size() - 1; i++)
		{
			Article child = this->children.at(i);
			output += "<li>" + child.toHTMLString() + "</li>";
		}
		output += "<li>" + this->children.at(this->children.size() - 1).toHTMLString() + "</li>";
		output += "</ol>";
	}

	output += "</div>";

	return output;
}

std::string Article::getContent()
{
	return this->content;
}

void Article::setContent(std::string content)
{
	this->content = content;
}




std::vector<Article> Article::getChildren()
{
	return this->children;
}

void Article::setChildren(std::vector<Article> children)
{
	this->children = children;
}

void Article::addChild(Article child)
{
	this->children.push_back(child);
}


bool Article::removeChild(Article child)
{
	
	for (size_t i = 0; i < this->children.size(); i++)
	{
		if (this->children.at(i) == child) 
		{
			this->children.erase(this->children.begin() + i, this->children.begin() + i);
			return true;
		}
	}
	
	return false;
}

