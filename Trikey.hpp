#ifndef _TRIKEY_HPP
#define _TRIKEY_HPP

#include <string>
#include <unordered_map>

#include "StringLib.hpp"

typedef std::unordered_map<std::string, std::string, StringLib::Hasher, StringLib::KeyEquals> SectionHashTable;
typedef std::unordered_map<std::string, SectionHashTable*, StringLib::Hasher, StringLib::KeyEquals> HashTable;

class Trikey
{
	//Properties
	public:
	protected:
	private:
	HashTable data;
	
	
	//Methods
	public:
	Trikey(void);
	~Trikey(void);

	void newSection(const std::string& sectionName);
	void newSection(std::string& sectionName);
	void newSection(std::string* sectionName);


	void put(const std::string& sectionName, const std::string& key, const std::string& value);
	void put(std::string& sectionName, std::string& key, std::string& value);
	void put(std::string* sectionName, std::string* key, std::string* value);		

	std::string& get(const std::string& sectionName, const std::string& key);
	std::string& get(std::string& sectionName, std::string& key);	
	std::string& get(std::string* sectionName, std::string* key);	

	void printData(void);

	protected:
	private:
};

#endif
