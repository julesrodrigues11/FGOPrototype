#include <iostream>
#include <string>
#include <vector>
#include "card.h"

class Servant
{
  private:
    std::string ServantClass;
    int StarRating;

    std::string Name;
    int Attack, MaxAttack;
    int HP, CurrentHP, MaxHP;
    int Cost;
    int ServantID;
    int GrailHP, GrailAttack;

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
    //Set in constructor and initialise an array with that many traits
    int NumOfTraits;
    std::vector<std::string> Traits;

    int NumOfPassives;
    //Resize to NumOfPassives later on
    //Or make Vector to make it resizable
    std::vector <std::string> Passives;

    std::string Skill1, Skill2, Skill3;
    int Skill1Level, Skill2Level, Skill3Level;
    int skillQP [10];

    int BusterCards, ArtsCards, QuickCards;
    int BusterHits, ArtsHits, QuickHits, ExtraHits;
    //Card ServantCards[6];
    std::vector <Card> ServantCards;

    std::string NoblePhantasm;
    std::string NPCardType;
    int NPHits;
    int NPLevel;
    std::string NPRank;
    std::string NPType;

    int CurrentAscension;
    int AscensionQP [4];

    //Stats
    std::string Strength, Endurance, Agility, Mana, Luck, NP;

    int CurrentBondLevel;
    int BondRequired [10];
    std::string Bond10CE;

    std::string EquippedCE;
    float NPGauge;
    float MaxNPGauge;


    //Number of description messages
    //Unlocked upon bond level and certain criteria met
    std::string description [8];
  
  public:
    //Constructor
    Servant(std::ifstream &servantDB);
    //Other Functions

    void GetData();

    void CheckCards();

    Card ReturnCard(int index);

    void SetNPLevel(int NP);

    void LevelUp();
    void UpgradeNP();
    void UpgradeSkill();
};