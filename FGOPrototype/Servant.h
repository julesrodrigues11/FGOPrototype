#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

class Servant
{
private:
	std::string ServantClass;
	int StarRating;

	std::string Name;
	int Attack, MaxAttack, GrailAttack;
	int HP, CurrentHP, MaxHP, GrailHP;
	int Cost;

	int ServantID;
	int HealthFous, AttackFous;

	std::string VoiceActor;
	std::string Illustrator;

	std::string Attribute;
	std::string GrowthCurve;

	int StarAbsorption;
	float StarGeneration;

	float NPGainATK, NPGainDEF;
	int DeathRate;
	std::string Alignment1, Alignment2;
	std::string Gender;

	//Number of traits would differ from servant to servant
	//Hence, create a vector that would allow dynamism
	int NumOfTraits;
	std::vector <std::string> Traits;

	//Same with Passives
	int NumOfPassives;
	std::vector <std::string> Passives;

	//Skill Variables
	std::string Skill1, Skill2, Skill3;
	int Skill1Level, Skill2Level, Skill3Level;
	int SkillQP[10];

	//Card Variables
	int BusterCards, ArtsCards, QuickCards;
	int BusterHits, ArtsHits, QuickHits, ExtraHits;
	std::vector <Card> ServantCards;

	//Noble Phantasm Variables
	//Make a class for Noble Phantasm?
	std::string NoblePhantasm;
	std::string NPCardType;
	int NPHits;
	int NPLevel;
	std::string NPRank;
	std::string NPType;

	int CurrentAscension;
	int AscensionQP[4];

	//Stats
	std::string Strength, Endurance, Agility, Mana, Luck, NP;

	int CurrentBondLevel;
	int BondRequired[10];
	std::string Bond10CE;

	std::string EquippedCE;
	float NPGauge;
	float MaxNPGauge;

	//Number of description messages
	//Unlocked upon bond level and certain conditions met
	//Requires work, maybe change to vector eventually
	std::string description[8];

public:
	//Constructor
	Servant(std::ifstream& servantDB);
	
	//Other functions
	void GetData();
	void CheckCards();

	Card ReturnCard(int index);
	void SetNPLevel(int NP);

	//Functions to work on
	void LevelUp();
	void UpgradeNP();
	void UpgradeSkill();

};

