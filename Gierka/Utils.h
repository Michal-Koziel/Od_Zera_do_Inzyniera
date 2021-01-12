#ifndef Utils_hpp
#define Utils_hpp
#include<string>

class Utils
{
public:
	static void loadFileAsStringArray(std::string path, std::string* table);
	static void saveToFile(std::string path, std::string informations);
	static int parseInt(std::string number);
};

#endif
