#include "Card.h"

Card::Card(bool isNP, std::string type, int hits, int id)
{
	Card::CardType = type;
	Card::CardHits = hits;
	Card::ID = id;
	Card::StarGeneration = 1.0f;
	Card::NPGeneration = 1.0f;
	Card::CommandCode = "";
	Card::IsNP = isNP;

	int tag = 0;
	std::string Cards[4] =
	{
		"Buster", "Arts", "Quick", "Extra"
	};

	if (type == "Buster")
	{
		tag = 0;
	}
	if (type == "Arts")
	{
		tag = 1;
	}
	if (type == "Quick")
	{
		tag = 2;
	}
	if (type == "Extra")
	{
		tag = 3;
	}

	switch (tag)
	{
	case(0):
		Card::StarGeneration = 0.5f;
		Card::NPGeneration = 0.0f;
		break;
	case(1):
		Card::NPGeneration = 2.0f;
		break;
	case(2):
		Card::StarGeneration = 1.0f;
		Card::NPGeneration = 1.0f;
		break;
	case(3):
		Card::StarGeneration = 1.0f;
		Card::NPGeneration = 1.0f;
		break;
	}
}

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

//Return Card Type
std::string Card::GetCardType()
{
	return Card::CardType;
}

//Return Card Hits
int Card::GetCardHits()
{
	return Card::CardHits;
}

int Card::GetCardID()
{
	return Card::ID;
}

//Return Command Code
std::string Card::GetCommandCode()
{
	return Card::CommandCode;
}

//Return whether Card is Noble Phantasm or not
bool Card::IsNoblePhantasm()
{
	return Card::IsNP;
}