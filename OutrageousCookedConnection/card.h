#include <iostream>
#include <string>
#include <vector>

//Make a vector of card types in Servant class
//Or make an array, since fixed size
//Make one of each type, and add multiple to the array
class Card
{
  protected:
  std::string CardType;
  int CardHits;
  std::vector<int> DamagePerHit;
  float StarGeneration;
  float NPGeneration;
  std::string CommandCode;
  bool IsNP=false;

  public:
  Card(bool isNP, std::string type, int hits);
  float NPGen();
  float StarGen();
  std::string GetCardType();
  int GetCardHits();
  std::string GetCommandCode();
  bool IsNoble();

  void EquipCommandCode();
};

/*
class Buster:public Card
{
  public:
  SetCardType();
};

class Arts:public Card
{
  public:
  SetCardType();
};

class Quick:public Card
{
  public:
  SetCardType();
};
*/