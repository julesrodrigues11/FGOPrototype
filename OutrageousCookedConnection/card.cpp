#include "card.h"

//Return StarGen value
float Card::StarGen()
{
  return Card::StarGeneration;
}

//Return NPGen value
float Card::NPGen()
{
  return Card::NPGeneration;
}

//Constructor for Card
Card::Card(bool isNP, std::string type, int hits)
{
  Card::CardType=type;
  Card::CardHits=hits;
  Card::StarGeneration=1.0f;
  Card::NPGeneration=1.0f;
  Card::CommandCode="";
  Card::IsNP=isNP;

  int id;
  std::string Cards[4]=
  {
    "Buster", "Arts", "Quick", "Extra"
  };
  if(type=="Buster")
  {
    id=0;
  }
  else if(type=="Arts")
  {
    id=1;
  }
  else if(type=="Quick")
  {
    id=2;
  }
  else if(type=="Extra")
  {
    id=3;
  }

  switch(id)
  {
    case(0):
    Card::StarGeneration=0.5f;
    Card::NPGeneration=0.0f;
    break;
    case(1):
    Card::NPGeneration=2.0f;
    break;
    case(2):
    Card::StarGeneration=2.0f;
    break;
    case(3):
    Card::StarGeneration=1.0f;
    Card::NPGeneration=1.0f;
    break;
  }
}

std::string Card::GetCardType()
{
  return Card::CardType;
}

int Card::GetCardHits()
{
  return Card::CardHits;
}

std::string Card::GetCommandCode()
{
  return Card::CommandCode;
}

bool Card::IsNoble()
{
  return Card::IsNP;
}