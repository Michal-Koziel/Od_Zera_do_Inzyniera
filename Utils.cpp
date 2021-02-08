#include "Utils.h"
#include <iostream>
#include <fstream>


void Utils::loadFileAsStringArray(std::string path, std::string* table) {
	std::ifstream file(path);
	std::string informations[18000];
	std::string helper;
	int i = 0;

	file >> helper;
	informations[i] += helper;
	i++;

	while (file >> helper){
		informations[i] += helper;
		i++;
	}
	
	file.close();

	for(int j=0;j<=i;j++)
		table[j]= informations[j];

}

void Utils::saveToFile(std::string path, std::string informations) {
	std::ofstream file(path);
	if (!file.is_open())
	{
		std::cout << "there is no file named" << path << std::endl;
	}
	file << informations;
	file.close();

}

int Utils::parseInt(std::string number) {
		return std::stoi(number);
}