#pragma once
#include <string>

class Provider
{
private:
	static int nextId;
	int id;
	std::string managerName;
	std::string socialReason;
	std::string description;
	std::string domain;
	int creationYear;
	int popularity;

public:
	static Provider internal;

	Provider(std::string managerName,
		std::string socialReason,
		std::string description,
		std::string domain,
		int creationYear,
		int popularity);
	Provider();

	~Provider();


	bool operator==(Provider right);
	bool operator!=(Provider right);


	std::string toString();
	std::string toHTMLString();


	int getId();

	std::string getManagerName();
	void setManagerName(std::string managerName);

	std::string getSocialReason();
	void setSocialReason(std::string socialReason);

	std::string getDescription();
	void setDescription(std::string description);

	std::string getDomain();
	void setDomain(std::string domain);

	int getCreationYear();
	void setCreationYear(int creationYear);

	int getPopularity();
	void setPopularity(int popularity);

};

