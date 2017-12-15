//Chase Churchill
//Fantasy Character Generator

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class Character //Abstract class
{
public:
	Character(int _health = 100, int _age = 20, int _intelligence = 5, int _strength = 5);
	string firstName;
	string lastName;
	string characterType;
	

	//Pure virtual functions
	virtual void GenerateFirstName() = 0;
	virtual void GenerateLastName() = 0;
	virtual void SayName() const = 0;
	virtual void DisplayStats() = 0;
	virtual void ModifyBaseStats() = 0;

protected:
	int health;
	int strength;
	int intelligence;
	int age;
};

//base class constructor
Character::Character(int _health, int _age, int _intelligence, int _strength) :
	health(_health), age(_age), intelligence(_intelligence), strength(_strength)
	

{}


class Mage : public Character 
{
public:
	Mage(int _health = 90, int _age = 30, int _intelligence = 8, int _strength = 3);
	string characterType = "Mage";
	string firstName;
	string lastName;
	void GenerateFirstName();
	void GenerateLastName();
	void ModifyBaseStats();
	void DisplayStats();
	void SayName() const;
	string firstNames[5] = { "Aldus", "Caldor", "Walder", "Logan", "Aimon" };
	string lastNames[5] = { "Darkwhisper", "Frostfang", "Starcaller", "Dreamweaver", "Earthshaper" };
	
};

//derived class constructor
Mage::Mage(int _health, int _age, int _intelligence, int _strength):
	Character(_health, _age, _intelligence, _strength)
{}

void Mage::SayName() const
{
	cout << "Your " << characterType << " is named " << firstName << " " << lastName << endl;
}

void Mage::GenerateFirstName()
{
	int randomNumber = rand();
	int nameNumber = (randomNumber % 5);
	firstName = firstNames[nameNumber];
}

void Mage::GenerateLastName()
{
	int randomNumber = rand();
	int nameNumber = (randomNumber % 5);
	lastName = lastNames[nameNumber];
}

void Mage::ModifyBaseStats()
{
	int randomNumber = rand();
	int healthModifier = (randomNumber % 61) - 30;
	health += healthModifier;

	int ageModifier = (randomNumber % 26) - 5;
	age += ageModifier;

	int intelligenceModifier = (randomNumber % 5) - 2;
	intelligence += intelligenceModifier;

	int strengtheModifier = (randomNumber % 7) - 2;
	strength += strengtheModifier;
}

void Mage::DisplayStats()
{
	cout << "\nYour mage's stats are:\nAge: " << age;
	cout << "\nHealth: " << health;
	cout << "\nStrength: " << strength;
	cout << "\nIntelligence: " << intelligence << "\n";
}

class Warrior : public Character
{
public:
	Warrior(int _health = 120, int _age = 25, int _intelligence = 3, int _strength = 8);
	string characterType = "Warrior";
	string firstName;
	string lastName;
	void SayName() const;
	void GenerateFirstName();
	void GenerateLastName();
	void DisplayStats();
	void ModifyBaseStats();
	string firstNames[5] = { "Gorgon", "Reynar", "Arthur", "Stannis", "Throg" };
	string lastNames[5] = { "Stonebreaker", "Firedrinker", "Oakheart", "Oathbreaker", "Lionfang" };

};

//derived class constructor
Warrior::Warrior(int _health, int _age, int _intelligence, int _strength) :
	Character(_health, _age, _intelligence, _strength)
{}

void Warrior::SayName() const
{
	cout << "Your " << characterType << " is named " << firstName << " " << lastName << endl;
}

void Warrior::DisplayStats()
{
	cout << "\nYour warriors's stats are:\nAge: " << age;
	cout << "\nHealth: " << health;
	cout << "\nStrength: " << strength;
	cout << "\nIntelligence: " << intelligence << "\n";
}

void Warrior::GenerateFirstName()
{
	int randomNumber = rand();
	int nameNumber = (randomNumber % 5);
	firstName = firstNames[nameNumber];
}

void Warrior::GenerateLastName()
{
	int randomNumber = rand();
	int nameNumber = (randomNumber % 5);
	lastName = lastNames[nameNumber];
}

void Warrior::ModifyBaseStats()
{
	int randomNumber = rand();
	int healthModifier = (randomNumber % 61) - 30;
	health += healthModifier;

	int ageModifier = (randomNumber % 26) - 5;
	age += ageModifier;

	int intelligenceModifier = (randomNumber % 7) - 2;
	intelligence += intelligenceModifier;

	int strengtheModifier = (randomNumber % 5) - 2;
	strength += strengtheModifier;
}

void CreateCharacter()
{
	string choice;
	cout << "Welcome to the Fantasy Character Generator!\n\nDo you want to create a Warrior or a Mage ? \n";
	cin >> choice;
	transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
	cout << "\n";
	while (choice != "MAGE" || choice != "WARRIOR")
	{


		if (choice == "MAGE")
		{
			Character* pCharacter = new Mage();
			pCharacter->GenerateFirstName();
			pCharacter->GenerateLastName();
			pCharacter->ModifyBaseStats();
			pCharacter->SayName();
			pCharacter->DisplayStats();
			break;
		}
		else if (choice == "WARRIOR")
		{
			Character* pCharacter2 = new Warrior();
			pCharacter2->GenerateFirstName();
			pCharacter2->GenerateLastName();
			pCharacter2->ModifyBaseStats();
			pCharacter2->SayName();
			pCharacter2->DisplayStats();
			break;
		}
		else
		{
			cout << "Please enter either Mage or Warrior: \n";
			cin >> choice;
			transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
		}

		
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	string choice = "Y";

	while (choice == "Y")
	{
		choice == "N";
		CreateCharacter();
		cout << "Do you want to generate another character? Y/N\n";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
		system("cls");
	}


	system("pause");
	return 0;
}


