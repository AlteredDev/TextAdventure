#include "Character.h"

Character::Character():Person()
{
	className = "";
	hp = 0;
	strength = 0;
	mana = 0;
	criticPerc = 0;
}

Character::Character(Person *p, string vClasseName, float vHP, float vHPMax):Person(*p),className(vClasseName),hp(vHP),hpMax(vHPMax)
{
}

string Character::getClassName()
{
	return className;
}

void Character::setClassName(string vClassName)
{
	className = vClassName;
}

string Character::getWeakness()
{
	return weakness;
}

void Character::setWeakness(string vWeakness)
{
	weakness = vWeakness;
}

float Character::getStrength()
{
	return strength;
}

void Character::setStrength(float vStrength)
{
	strength = vStrength;
}

float Character::getCriticPerc()
{
	return criticPerc;
}

void Character::setCriticPerc(float vCritPerc)
{
	criticPerc = vCritPerc;
}

float Character::getHP()
{
	return hp;
}

void Character::setHP(float vHP)
{
	hp = vHP;
}

float Character::getHPMax()
{
	return hpMax;
}

void Character::setHPMax(float vHPMax)
{
	hpMax = vHPMax;
}

float Character::getMana()
{
	return mana;
}

void Character::setMana(float vMana)
{
	mana = vMana;
}

float Character::getManaMax()
{
	return manaMax;
}

void Character::setManaMax(float vManaMax)
{
	manaMax = vManaMax;
}

bool Character::getIsDead()
{
	return isDead;
}

void Character::setIsDead(bool dead)
{
	isDead = dead;
}

bool Character::getIsPNJ()
{
	return PNJ;
}

void Character::setIsPNJ(bool vPNJ)
{
	PNJ = vPNJ;
}

Inventory Character::getInvChar()
{
	return *invChar;
}

void Character::setInvChar(Inventory  *vInvChar)
{
	invChar = vInvChar;
}

void Character::equipWeapon(Inventory* Inv)
{
	actualWeapon = Inv->equipWeapon();
	cout << getFirstName() << " " << getLastName() << " is now equipped of a " << actualWeapon->GetName() << ".\n";
}

void Character::useItem(Inventory* Inv)
{
	int output = Inv->getItemTab()->useItem();

	if (output == 0) { cout << "There's no items in the inventory"; }

	if (output == 1) {
		if (actualPotion.getName() == "") {
			actualPotion = Inv->getItemTab()->getUsedPotion();
			cout << getFirstName() << " " << getLastName() << " drank a " << actualPotion.getName() << ".";
		}
		else{
			cout << getFirstName() << " " << getLastName() << " has already a " << actualPotion.getName() << " in use.";
		}
	}
	cout << endl << endl;
	system("pause");
}

void Character::verifyPotion()
{
	if (actualPotion.getName() != "") {
		if (actualPotion.getTimeTurn() > 0) {
			if (actualPotion.getInitTimeTurn() == actualPotion.getTimeTurn()) {
				if (actualPotion.getIsDamageBoost()) {
					strength += actualPotion.getDamageBoost();
				}
				if (actualPotion.getIsHeal()) {
					hp += actualPotion.getHeal();
				}
				if (actualPotion.getIsSpeed()) {
					setInitiative(getInitiative() + actualPotion.getSpeed());
				}
			}
			actualPotion.setTimeTurn(actualPotion.getTimeTurn() - 1);
		}
		else {
			actualPotion.getName() = "";
			if (actualPotion.getIsDamageBoost()) {
				strength -= actualPotion.getDamageBoost();
			}
			if (actualPotion.getIsHeal()) {
				hp -= actualPotion.getHeal();
			}
			if (actualPotion.getIsSpeed()) {
				setInitiative(getInitiative() - actualPotion.getSpeed());
			}
		}
	}
}

void Character::setActualWeapon(Weapon *newWeapon)
{
	actualWeapon = newWeapon;
}

Weapon* Character::getActualWeapon()
{
	return actualWeapon;
}

// a faire peut etre dans Location ?
void Character::changeLocation(Location l)
{
	if (l.getHasEffectLocation()) {
		if (l.getEffectLocation() == "Strength--") {
			setStrength(getStrength() - (getStrength() * 0.1f)); // baisse de 10% force
		}
		if (l.getEffectLocation() == "Strength++") {
			setStrength(getStrength() + (getStrength() * 0.1f)); // augmentation de 10% force
		}
		if (l.getEffectLocation() == "Initiative--") {
			setInitiative(getInitiative() - (getInitiative() * 0.1f)); // baisse de 10% initiative
		}
		if (l.getEffectLocation() == "Initiative++") {
			setInitiative(getInitiative() - (getInitiative() * 0.1f)); // augmentation de 10% initiative
		}
		if (l.getEffectLocation() == "HP--") {
			setHP(getHP() - (getHP() * 0.05f)); // baisse de 5% sante
		}
	}
}

void Character::createCharacter()
{
	string stringInput;
	int intInput;
	system("cls");
	cout << "New character\nEnter the first name :\n";
	cin >> stringInput;
	setFirstName(stringInput);
	cout << "Enter the last name :\n";
	cin >> stringInput;
	setLastName(stringInput);
	cout << "Enter the age :\n";
	cin >> intInput; 
	while (cin.fail() || intInput < 18) {
		cin.clear(); cin.ignore();
		cout << "Enter an age (18 or greater) :\n";
		cin.clear();  cin >> intInput;
	}
	setAge(intInput);
	
	int numClass;
	cout << "\nYou have the choice between many classes, Mage(1), Paladin(2) or Warrior(3)\nPlease enter the number corresponding to the class you will choose :\n";
	cin.clear();  cin >> numClass;
	while (cin.fail() || numClass < 1 || numClass > 3) {
		cin.clear(); cin.ignore();
		cout << "Enter a valid number :\n";
		cin.clear();  cin >> numClass;
	}
	switch (numClass)
	{
	case 1:
		className = "Mage";
		strength = 5;
		criticPerc = 0.7;
		hpMax = 80;
		hp = hpMax;
		manaMax = 15;
		mana = manaMax;
		setInitiative(7);
		break;
	case 2:
		className = "Paladin";
		strength = 10;
		criticPerc = 0.5;
		hpMax = 90;
		hp = hpMax;
		manaMax = 5;
		mana = manaMax;
		setInitiative(13);
		break;
	case 3:
		className = "Warrior";
		strength = 15;
		criticPerc = 0.3;
		hpMax = 95;
		hp = hpMax;
		manaMax = 0;
		mana = manaMax;
		setInitiative(10);
		break;
	}


	cout << "\nYou will therefore be " << getFirstName() << " " << getLastName() << ", " << getAge() << " years old, a " << className <<".";
	Sleep(000); //delay when creating, so the player can read the summeriz
}

void Character::attack(Person &p)
{

}

void Character::defend()
{

}

void Character::showInfo()
{
	/*
	cout << getFirstName() << " " << getLastName() << endl;
	cout << getAge() << " ans";
	*/
	cout << getFirstName() << " " << getLastName() << endl << "Class : " << getClassName() << endl << " HP : " << getHP() << "/" << getHPMax() << "\nEquipped weapon : " << actualWeapon->GetName() << endl;
}

void Character::die()
{
	cout << getFirstName() << " " << getLastName() << " is dead." << endl;
	setIsDead(true);
}
