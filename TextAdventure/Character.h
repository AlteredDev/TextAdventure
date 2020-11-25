#pragma once
#include <windows.h>
#include "Person.h"
#include "Spell.h"
#include "Inventory.h"

class Character : public Person
{
private:
	bool PNJ;
	string className;
	string weakness;
	float strength;
	float criticPerc;

	float hp;
	float hpMax;

	float mana;
	float manaMax;

	Inventory* invChar;
	Weapon actualWeapon;
	Spell spells[3];

public:
	Character();
	Character(Person *p, string vClasseName, float vHP, float vHPMax);

	//Setter/Getter
	string getClassName();
	void setClassName(string vClassName);

	string getWeakness();
	void setWeakness(string vWeakness);

	float getStrength();
	void setStrength(float vStrength);

	float getCriticPerc();
	void setCriticPerc(float vCritPerc);

	float getHP();
	void setHP(float vHP);

	float getHPMax();
	void setHPMax(float vHPMax);

	float getMana();
	void setMana(float vMana);

	float getManaMax();
	void setManaMax(float vManaMax);

	Inventory getInvChar();
	void setInvChar(Inventory *vInvChar);



	/*
	Spell getSpells(Spell &vSpells);
	void setSpells(Spell &vSpells);
	*/

	//creation du character (+ class etc...)
	void createCharacter();
	//attaquer un ennemi --> attackFailed/AttackSucced
	void attack(Person &p);
	//se défendre (ssi Weapon.defense > 0)
	void defend();
	//cast un spell S sur la personne p
	void castSpell(Spell &s, Person &p);
	//montrer l'inventaire actuel du personnage
	void showInventory();
	//montrer/rappeller les infos character
	void showInfo();
	//mourrir de la mort qui tue
	void die();
};

