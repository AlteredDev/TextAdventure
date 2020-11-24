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

Character::Character(Person *p, string vClasseName, float vHP):Person(*p),className(vClasseName),hp(vHP)
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
		strength = 5;
		criticPerc = 0.7;
		hpMax = 80;
		manaMax = 15;
		break;
	case 2:
		className = "Paladin";
		strength = 10;
		criticPerc = 0.5;
		hpMax = 90;
		manaMax = 5;
		break;
	case 3:
		className = "Warrior";
		strength = 15;
		criticPerc = 0.3;
		hpMax = 95;
		manaMax = 0;
		break;
	}


	cout << "\n\nVous serez donc un " << className;
}

void Character::attack(Person &p)
{

}

void Character::defend()
{

}

void Character::castSpell(Spell s, Person & p)
{
	Character c;
	cout << "Vous lancez le sort de " << s.getNameSpell() << " sur " << p.getFirstName() << " " << p.getLastName() << "." << endl;
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

void Character::showInventory()
{
}

void Character::showInfo()
{
	/*
	cout << getFirstName() << " " << getLastName() << endl;
	cout << getAge() << " ans";
	*/
	cout << "Classe : " << getClassName() << " HP : " << getHP() << endl;
}

void Character::die()
{
}
