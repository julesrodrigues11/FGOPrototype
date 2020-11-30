#include <iostream>
#include <fstream>
#include <string>
#include "servant.h"

int main()
{
  //Pass servant ID into the constructor
  //Pull servant name from servant name text file
  //Open text file with the given name
  std::string servantName = "Servants/";
  servantName += "Okita Souji";
  servantName += ".txt";

  std::ifstream servantDB;
  servantDB.open(servantName);

  Servant servant(servantDB);
  servant.SetNPLevel(5);

  std::cout << std::endl;
  servant.GetData();

  servant.CheckCards();
  std::cout << std::endl;

  /*
  Quick q1;
  Buster b1;
  Arts a1;

  std::cout << "Quick" << std::endl;
  std::cout << "NP Gen - " << q1.NPGen() << std::endl;
  std::cout << "Star Gen - " << q1.StarGen() << std::endl;
  std::cout << std::endl;

  std::cout << "Buster" << std::endl;
  std::cout << "NP Gen - " << b1.NPGen() << std::endl;
  std::cout << "Star Gen - " << b1.StarGen() << std::endl;
  std::cout << std::endl;

  std::cout << "Arts" << std::endl;
  std::cout << "NP Gen - " << a1.NPGen() << std::endl;
  std::cout << "Star Gen - " << a1.StarGen() << std::endl;
  std::cout << std::endl;
  */

  servantDB.close();
}