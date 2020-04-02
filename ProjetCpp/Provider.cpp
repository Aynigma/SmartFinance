#include "Provider.h"

int Provider::nextId = 0;
Provider Provider::internal = Provider("internal", "internal", "internal", "internal", -1, -1);

Provider::Provider(std::string managerName,
	std::string socialReason,
	std::string description,
	std::string domain,
	int creationYear,
	int popularity)
{
	this->id = nextId++;
	this->managerName = managerName;
	this->socialReason = socialReason;
	this->description = description;
	this->domain = domain;
	this->creationYear = creationYear;
	this->popularity = popularity;
}

//TODO
Provider::Provider()
{
}

Provider::~Provider() {}


bool Provider::operator==(Provider right)
{
	return(this->id == right.id &&
		this->managerName == right.managerName &&
		this->socialReason == right.socialReason &&
		this->description == right.description &&
		this->domain == right.domain &&
		this->creationYear == right.creationYear &&
		this->popularity == right.popularity
		);
}

bool Provider::operator!=(Provider right) { return !(*this == right); }


std::string Provider::toString()
{
	std::string output("(");
	output += "id : " + std::to_string(this->id) + "; ";
	output += "managerName :" + this->managerName + "; ";
	output += "socialReason :" + this->socialReason + "; ";
	output += "description :" + this->description + "; ";
	output += "domain :" + this->domain + "; ";
	output += "creationYear :" + std::to_string(this->creationYear) + "; ";
	output += "popularity :" + std::to_string(this->popularity) + "; ";
	output += ")";
	return output;
}

//TODO
std::string Provider::toHTMLString()
{
	return "";
}


int Provider::getId() { return this->id; }

std::string Provider::getManagerName() { return this->managerName; }
void Provider::setManagerName(std::string managerName) { this->managerName = managerName; }

std::string Provider::getSocialReason() { return this->socialReason; }
void Provider::setSocialReason(std::string socialReason) { this->socialReason = socialReason; }

std::string Provider::getDescription() { return this->description; }
void Provider::setDescription(std::string description) { this->description = description; }

std::string Provider::getDomain() { return this->domain; }
void Provider::setDomain(std::string domain) { this->domain = domain; }

int Provider::getCreationYear() { return this->creationYear; }
void Provider::setCreationYear(int creationYear) { this->creationYear = creationYear; }

int Provider::getPopularity() { return this->popularity; }
void Provider::setPopularity(int popularity) { this->popularity = popularity; }