#include "servant.h"
#include <fstream>

Servant::Servant(std::ifstream &servantDB)
{
  std::string placeHolder = "";
  int lineNumber = 0;
  bool passive=false;
  int passiveCount=0;
  bool trait=false;
  int traitCount=0;
  //Consider making file inputs to feed data into objects
  //Servant::Name = name;
  //Servant::StarRating = starRating;
  //Servant::ServantClass = servantClass;
  std::cout << "Servant has been created" << std::endl;

  while(std::getline(servantDB, placeHolder))
  {
    switch(lineNumber)
    {
      case (0):
      Servant::Name = placeHolder;
      break;
      case(1):
      Servant::ServantClass = placeHolder;
      break;
      case(2):
      Servant::StarRating = std::stoi(placeHolder);
      break;
      case(3):
      Servant::Cost=std::stoi(placeHolder);
      break;
      case(4):
      Servant::Attack=std::stoi(placeHolder);
      break;
      case(5):
      Servant::MaxAttack=std::stoi(placeHolder);
      break;
      case(6):
      Servant::GrailAttack=std::stoi(placeHolder);
      break;
      case(7):
      Servant::HP=std::stoi(placeHolder);
      break;
      case(8):
      Servant::MaxHP=std::stoi(placeHolder);
      break;
      case(9):
      Servant::GrailHP=std::stoi(placeHolder);
      break;
      case(10):
      Servant::VoiceActor=placeHolder;
      break;
      case(11):
      Servant::Illustrator=placeHolder;
      break;
      case(12):
      Servant::StarAbsorption=std::stof(placeHolder);
      break;
      case(13):
      Servant::StarGeneration=std::stof(placeHolder);
      break;
      case(14):
      Servant::NPGainATK=std::stof(placeHolder);
      break;
      case(15):
      Servant::NPGainDEF=std::stof(placeHolder);
      break;
      case(16):
      Servant::Attribute=placeHolder;
      break;
      case(17):
      Servant::GrowthCurve=placeHolder;
      break;
      case(18):
      Servant::DeathRate=std::stoi(placeHolder);
      break;
      case(19):
      Servant::Alignment1=placeHolder;
      break;
      case(20):
      Servant::Alignment2=placeHolder;
      break;
      case(21):
      Servant::Gender=placeHolder;
      break;
      case(22):
      Servant::NumOfTraits=std::stoi(placeHolder);
      break;
      case(23):
      Servant::BusterCards=std::stoi(placeHolder);
      break;
      case(24):
      Servant::ArtsCards=std::stoi(placeHolder);
      break;
      case(25):
      Servant::QuickCards=std::stoi(placeHolder);
      break;
      case(26):
      Servant::BusterHits=std::stoi(placeHolder);
      break;
      case(27):
      Servant::ArtsHits=std::stoi(placeHolder);
      break;
      case(28):
      Servant::QuickHits=std::stoi(placeHolder);
      break;
      case(29):
      Servant::ExtraHits=std::stoi(placeHolder);
      break;
      case(30):
      Servant::Skill1=placeHolder;
      break;
      case(31):
      Servant::Skill2=placeHolder;
      break;
      case(32):
      Servant::Skill3=placeHolder;
      break;
      case(33):
      Servant::NumOfPassives=stoi(placeHolder);
      break;
      case(34):
      Servant::NoblePhantasm=placeHolder;
      break;
      case(35):
      Servant::NPRank=placeHolder;
      break;
      case(36):
      Servant::NPCardType=placeHolder;
      break;
      case(37):
      Servant::NPHits=stoi(placeHolder);
      break;
       case(38):
      Servant::NPType=placeHolder;
      break;
      case(39):
      Servant::Strength=placeHolder;
      break;
      case(40):
      Servant::Endurance=placeHolder;
      break;
      case(41):
      Servant::Agility=placeHolder;
      break;
      case(42):
      Servant::Mana=placeHolder;
      break;
      case(43):
      Servant::Luck=placeHolder;
      break;
      case(44):
      Servant::NP=placeHolder;
      break;
      case(45):
      Servant::Bond10CE=placeHolder;
      break;
      case(59):
      trait=true;
      break;
      case(69):
      passive=true;
      break;
      default:
      if(trait)
      {
        if(traitCount==NumOfTraits)
        {
          trait=false;
          break;
        }
        Servant::Traits.push_back(placeHolder);
        traitCount++;
      }
      if(passive)
      {
        if(passiveCount==NumOfPassives)
        {
          passive=false;
          break;
        }
        Servant::Passives.push_back(placeHolder);
        passiveCount++;
      }
      break;
    }
    lineNumber++;
  }

  Servant::CurrentAscension=1;
  Servant::CurrentHP=Servant::HP;
  Servant::CurrentBondLevel=0;
  Servant::HealthFous=0;
  Servant::AttackFous=0;
  Servant::Skill1Level=1;
  Servant::Skill2Level=1;
  Servant::Skill3Level=1;
  Servant::NPLevel=1;
  Servant::NPGauge=0;

  switch(Servant::NPLevel)
  {
    case(1):
    Servant::MaxNPGauge=100;
    break;
    case(2):
    Servant::MaxNPGauge=200;
    break;
    case(3):
    Servant::MaxNPGauge=200;
    break;
    case(4):
    Servant::MaxNPGauge=200;
    break;
    case(5):
    Servant::MaxNPGauge=300;
    break;
  }

  int BusterCount=0;
  int ArtsCount=0;
  int QuickCount=0;
  while(BusterCount<Servant::BusterCards)
  {
    Card Buster(false, "Buster", Servant::BusterHits);
    Servant::ServantCards.push_back(Buster);
    BusterCount++;
  }

  while(ArtsCount<Servant::ArtsCards)
  {
    Card Arts(false, "Arts", Servant::ArtsHits);
    Servant::ServantCards.push_back(Arts);
    ArtsCount++;
  }

  while(QuickCount<Servant::QuickCards)
  {
    Card Quick(false, "Quick", Servant::QuickHits);
    Servant::ServantCards.push_back(Quick);
    QuickCount++;
  }

  Card Extra(false, "Extra", Servant::ExtraHits);
  Servant::ServantCards.push_back(Extra);

  Card NP(true, Servant::NPCardType, Servant::NPHits);
  Servant::ServantCards.push_back(NP);


  std::cout << "Object " << Servant::Name << " has been created with allocated stats" << std::endl;
}

void Servant::GetData()
{
  std::cout << "Servant Name - " << Servant::Name << std::endl;
  std::cout << Servant::StarRating << " Star" << std::endl;
  std::cout << "Servant Class - " << Servant::ServantClass << std::endl;
  std::cout << "Max Health - " << Servant::MaxHP << std::endl;
  std::cout << "Max Attack - " << Servant::MaxAttack << std::endl;
  std::cout << "Voice Actor - " << Servant::VoiceActor << std::endl;
  std::cout << "Illustrator - " << Servant::Illustrator << std::endl;
  std::cout << "Alignments - " << Servant::Alignment1 << " " << Servant::Alignment2 << std::endl;
  std::cout << "-----------------------------------" << std::endl;

  std::cout << "Traits" << std::endl;
  for(int i =0;i<Traits.size();i++)
  {
    std::cout << Traits[i] << std::endl;
  }

  std::cout << "-----------------------------------" << std::endl;
  std::cout << "Passives" << std::endl;
  for(int i=0;i<Passives.size();i++)
  {
    std::cout << Passives[i] << std::endl;
  }
  std::cout << "-----------------------------------" << std::endl;

  std::cout << "Skill 1 - " << Servant::Skill1 << " Lv. " << Servant::Skill1Level << std::endl;
  std::cout << "Skill 2 - " << Servant::Skill2 << " Lv. " << Servant::Skill2Level << std::endl;
  std::cout << "Skill 3 - " << Servant::Skill3 << " Lv. " << Servant::Skill3Level << std::endl;

  std::cout << "Noble Phantasm - " << Servant::NoblePhantasm << " - Rank " << Servant::NPRank << " " << Servant::NPCardType << " ";
  if(Servant::NPHits!=0)
  {
    std::cout<<Servant::NPHits << " Hits" << std::endl << std::endl;
  }
  std::cout << Servant::NPType << std::endl << std::endl;

  std::cout << "Buster Cards - " << Servant::BusterCards << std::endl;
  std::cout << "Arts Cards - " << Servant::ArtsCards << std::endl;
  std::cout << "Quick Cards - " << Servant::QuickCards << std::endl;
  std::cout << std::endl;
  std::cout << "Buster Hits - " << Servant::BusterHits << std::endl;
  std::cout << "Arts Hits - " << Servant::ArtsHits << std::endl;
  std::cout << "Quick Hits - " << Servant::QuickHits << std::endl;
  std::cout << "Extra Hits - " << Servant::ExtraHits << std::endl << std::endl; 

  std::cout << "Current Bond Level - " << Servant::CurrentBondLevel << std::endl;
  std::cout << "Current Ascension - " << Servant::CurrentAscension << std::endl;
  std::cout << "Bond 10 CE - " << Servant::Bond10CE << std::endl;

  std::cout << std::endl << "NP Level - " << Servant::NPLevel <<std::endl;
  std::cout << "Current NP Gauge - " << Servant::NPGauge << std::endl;
  std::cout << "Max NP Gauge - " << Servant::MaxNPGauge << std::endl;
}

void Servant::CheckCards()
{
  std::cout << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  for (int i = 0; i < 7; i++)
  {
    Card card = Servant::ServantCards[i];
    std::cout << "Card Number - " << i+1;
    if(card.IsNoble())
    {
      std::cout << " (NP) " << std::endl;
    }
    else
    {
      std::cout << std::endl;
    }
    std::cout << "Card Type - " << card.GetCardType() << std::endl;
    std::cout << "Card NP Gen - " << card.NPGen() << std::endl;
    std::cout << "Card Star Gen - " << card.StarGen() << std::endl;
    std::cout << "Card Hits - " << card.GetCardHits() << std::endl;
    
    if(card.GetCommandCode()=="")
    {
      std::cout << "Command Code - Blank" << std::endl;
    }
    else
    {
      std::cout << "Command Code - " << card.GetCommandCode() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;
  }
}

Card Servant::ReturnCard(int index)
{
  return Servant::ServantCards[index];
}

void Servant::SetNPLevel(int NP)
{
  Servant::NPLevel=NP;
  switch(NP)
  {
    case(1):
    Servant::MaxNPGauge=100;
    break;
    case(2):
    Servant::MaxNPGauge=200;
    break;
    case(3):
    Servant::MaxNPGauge=200;
    break;
    case(4):
    Servant::MaxNPGauge=200;
    break;
    case(5):
    Servant::MaxNPGauge=300;
    break;
  }
}