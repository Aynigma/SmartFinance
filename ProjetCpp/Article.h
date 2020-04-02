#pragma once
#include <string>
#include <vector>

class Article
{
private:
	std::string content;
	std::vector<Article> children;

public:

	Article();
	Article(std::string content);
	Article(std::string content, Article child);
	Article(std::string content, std::vector<Article> children);
	
	~Article();

	bool operator == (Article right);
	bool operator != (Article right);
	
	std::string toString();
	std::string toHTMLString();

	void addChild(Article child);
	bool removeChild(Article child);
	std::vector<Article> getChildren();
	void setChildren(std::vector<Article> children);

	std::string getContent();
	void setContent(std::string content);

	

};

