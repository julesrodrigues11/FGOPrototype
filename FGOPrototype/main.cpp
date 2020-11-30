#include <iostream>
#include <fstream>
#include <string>
#include "Servant.h"

int main()
{
	//Pass servant ID into the constructor
	//Pull servant name from servant name text file
	//Open text file with the given name - Improvement
	std::string servantName = "Servants/";
	servantName += "Okita Souji";
	servantName += ".txt";

	std::ifstream servantDB;
	servantDB.open(servantName);

	Servant servant(servantDB);
	//servant.SetNPLevel(5);

	std::cout << std::endl;
	servant.GetData();

	servant.CheckCards();
	std::cout << std::endl;

	servantDB.close();
}