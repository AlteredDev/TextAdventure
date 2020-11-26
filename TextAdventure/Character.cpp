#include "Character.h"



Character::Character():Person()
{
	className = "";
	hp = 0;
	strength = 0;
	mana = 0;
	for (int i = 0; i < 4; i++) {
		//inventory[i].SetName("");
	}
	criticPerc = 0;
	for (int i = 0; i < 3; i++) {
		spells[i];
	}
	float speed = 0;
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

string Character::getCharFirstName()
{
	return getFirstName();
}

string Character::getCharLastName()
{
	return getLastName();
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

void Character::setActualWeapon(Weapon *newWeapon)
{
	actualWeapon = newWeapon;
}

Weapon* Character::getActualWeapon()
{
	return actualWeapon;
}

/*
Spell Character::getSpells(Spell & vSpells)
{
	return vSpells;
}

void Character::setSpells(Spell & vSpells)
{
}
*/

void Character::createCharacter()
{
	string stringInput;
	int intInput;
	system("cls");
	cout << "New character\n\nEnter the first name :\n";
	cin >> stringInput;
	setFirstName(stringInput);
	cout << "\nEnter the last name :\n";
	cin >> stringInput;
	setLastName(stringInput);
	cout << "\nEnter the age :\n";
	cin >> intInput; 
	while (cin.fail() || intInput < 1) {
		cin.clear(); cin.ignore();
		cout << "Enter an age between 18 and 99 :\n";
		cin.clear();  cin >> intInput;
	}
	setAge(intInput);
	
	int numClass;
	cout << "\nYou have the choice between many classes, Mage(1), Paladin(2) or Warrior(3)\n\nPlease enter the number corresponding to the class you will choose :\n";
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
		break;
	case 2:
		className = "Paladin";
		strength = 10;
		criticPerc = 0.5;
		hpMax = 90;
		hp = hpMax;
		manaMax = 5;
		mana = manaMax;
		break;
	case 3:
		className = "Warrior";
		strength = 15;
		criticPerc = 0.3;
		hpMax = 95;
		hp = hpMax;
		manaMax = 0;
		mana = manaMax;
		break;
	}


	cout << "\n\nYou will therefore be " << getFirstName() << " " << getLastName() << ", " << getAge() << " years old, a " << className <<".";
	Sleep(000); //delay when creating, so the player can read the summeriz
}

void Character::attack(Person &p)
{

}

void Character::defend()
{

}

void Character::castSpell(Spell &s, Person &p)
{
	if (s.getManaCostSpell() > getMana()) {
		cout << "You don't have enough mana to cast the spell." << endl;
	}
	else {
		cout << "You cast the spell of " << s.getNameSpell() << " on " << p.getFirstName() << " " << p.getLastName() << "." << endl;
		float val = s.castSpell();

		switch (s.getID())
		{
		case 1: // heal
			if ((getHP() + val) >= getHPMax()) {
				setHP(getHPMax());
			}
			else {
				setHP(getHP() + val);
			}
			break;
		case 2: // boost dmg
			actualWeapon->GetDamage() + val;
			break;
		}

	}

	//s.castSpell(c);
	/*
	if ((getHP() + getHealAmount()) >= getHPMax) {
		setHP(c.getHPMax);
	}
	else {
		setHP(getHP() + getHealAmount());
	}

	*/
	
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
}
