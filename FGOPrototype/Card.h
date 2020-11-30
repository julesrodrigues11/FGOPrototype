#pragma once
#include <iostream>
#include <string>
#include <vector>

class Card
{
private:
	//Private variables for Card class
	std::string CardType;
	int CardHits;
	int ID; //To tell which card in the list it is - To identify against duplicates
	std::vector<int>DamagePerHit;
	float StarGeneration;
	float NPGeneration;
	std::string CommandCode;
	bool IsNP = false;

public:
	//Public methods for Card Class
	//Constructor
	Card(bool isNP, std::string type, int hits, int id);

	//Getters
	float NPGen();
	float StarGen();
	std::string GetCardType();
	int GetCardHits();
	int GetCardID();
	std::string GetCommandCode();
	bool IsNoblePhantasm();

	//Setters
	void EquipCommandCode(); //Setter for Card Command Code (TO DO)
};

