#ifndef _CONFIG_H
#define _CONFIG_H

#include <string>

namespace Config
{
	void init(void);
	void uninit(void);

	std::string& convertSettingToString(const std::string& sectionName, const std::string& settingName);
	std::string* convertSettingToStringPointer(const std::string& sectionName, const std::string& settingName);	

	char convertSettingToChar(const std::string& sectionName, const std::string& settingName);
	bool convertSettingToBool(const std::string& sectionName, const std::string& settingName);
	short convertSettingToShort(const std::string& sectionName, const std::string& settingName); 
	int convertSettingToInt(const std::string& sectionName, const std::string& settingName);
	long convertSettingToLong(const std::string& sectionName, const std::string& settingName);
	float convertSettingToFloat(const std::string& sectionName, const std::string& settingName);
	double convertSettingToDouble(const std::string& sectionName, const std::string& settingName);

	void getNewLine(std::ifstream& file, std::string& line, int& lineNumber);

	void parseSection(std::ifstream& file, std::string& line, int& lineNumber);

	void printSections(void);
}


#endif
