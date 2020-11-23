#include "Character.h"

Character::Character():Person()
{
	cout << "Constructeur Personnage" << endl;
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

Inventory Character::getInvChar()
{
	return invChar;
}

void Character::setInvChar(Inventory & vInvChar)
{
	invChar = vInvChar;
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
	system("cls");
	cout << "Nouveau perso\n\nEntrer votre nom :";
	//cin.clear();  cin >> name;
	//setNomPerson()
	
	int numClass;
	cout << "\n\nVous avez le choix entre plusieurs classes,\nMage(1), Paladin(2) ou Warrior(3)\nVeuiller rentrer le chiffre correspondant à la classe que vous choisirez :\n\n";
	cin.clear();  cin >> numClass;
	while (cin.fail() || numClass < 1 || numClass > 3) {
		cout << "Veuillez rentrer un chiffre valide :";
		cin.clear();  cin >> numClass;
	}
	switch (numClass)
	{
	case 1:
		className = "Mage";

		break;
	case 2:
		className = "Paladin";
		break;
	case 3:
		className = "Warrior";
		break;
	}


	cout << "\n\nVous serez donc un " << className;
}

bool Character::attack(Person &p)
{
	return false;
}

bool Character::defend()
{
	return false;
}

void Character::castSpell(Spell s, Person & p)
{
	/*
	cout << "Vous lancez le sort de soin et " << p.getFirstName() << " récupère " << s.getHealAmount() << " points de vie." << endl;

	if ((getHP() + getHealAmount()) >= getHPMax) {
		setHP(c.getHPMax);
	}
	else {
		setHP(getHP() + getHealAmount());
	}


	*/
}

void Character::showInventory()
{
}

void Character::showInfo()
{
}

void Character::die()
{
}
