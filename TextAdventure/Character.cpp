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

float Character::getCriticPercMultiplier()
{
	return criticPercMultiplier;
}

void Character::setCriticPercMultiplier(float vCritPercMultiplier)
{
	criticPercMultiplier = vCritPercMultiplier;
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

float Character::getHitPerc()
{
	return hitPerc;
}

void Character::setHitPerc(float vHitPerc)
{
	hitPerc = vHitPerc;
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

bool Character::getIsDefending()
{
	return isDefending;
}

void Character::setIsDefending(bool vIsDefending)
{
	isDefending = vIsDefending;
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
		setClassName("Mage");
		setStrength(15.0f);
		setCriticPerc(60.0f);
		setCriticPercMultiplier(2.0f);
		setHitPerc(0.80f);
		setHPMax(150.0f);
		setHP(getHPMax());
		setManaMax(60.0f);
		setMana(getMana());
		setInitiative(7.0f);
		break;
	case 2:
		setClassName("Paladin");
		setStrength(10.0f);
		setCriticPerc(40.0f);
		setCriticPercMultiplier(1.25f);
		setHitPerc(0.75f);
		setHPMax(300.0f);
		setHP(getHPMax());
		setManaMax(20.0f);
		setMana(getMana());
		setInitiative(13.0f);
		break;
	case 3:
		setClassName("Warrior");
		setStrength(12.0f);
		setCriticPerc(40.0f);
		setCriticPercMultiplier(1.75f);
		setHitPerc(0.80f);
		setHPMax(225.0f);
		setHP(getHPMax());
		setManaMax(0.0f);
		setMana(getMana());
		setInitiative(10.0f);
		break;
	}

	cout << "\n\nYou will therefore be " << getFirstName() << " " << getLastName() << ", " << getAge() << " years old, a " << className <<".\n";
	system("pause");
}

/*
Vérif si atk réussi, avec un random bool
Vérif si critic fonction, avec un random bool
Force perso x dégâts arme + ptit random de bonus atk -10 à 10 x critic - defense de weapon de c (si cible est en train de défendre, après set isDefending de cible à false)

après atk, vérif si c.hp <= 0, alors die()
*/
void Character::attack(Character &c)
{
	srand(time(NULL));
	int randAttack = rand() % 20 + (-10); // random entre -10 et 10
	int randHit = (rand() % 100);
	randHit /= 100;
	int randCrit = (rand() % 100);
	randCrit /= 100;

	float dmg = (getStrength() * getActualWeapon()->GetDamage()) + randAttack;

	if (randHit <= getHitPerc()) {
		if (randCrit <= getCriticPerc()) {
			dmg *= getCriticPercMultiplier();
		}
		if (c.getIsDefending()) {
			dmg -= c.getActualWeapon()->GetDefense();
		}
		c.setHP(c.getHP() - dmg);
		if (c.getHP() <= 0) {
			c.die();
		}
	}
	else {
		cout << getFirstName() << " " << getLastName() << " failed the attack on " << c.getFirstName() << " " << c.getLastName() << "." << endl;
	}

}

/*
vérif si actualWeapon.getDefense() > 0, peut défendre
*/
void Character::defend()
{
	if (getActualWeapon()->GetDefense() > 0) {
		setIsDefending(true);
	}
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
