#pragma once
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class Ennemy : public Person
{
private:
	string badGuyName;
	string weakness;
	float strength;
	float criticPerc;
	float loot;

	float hp;
	float hpMax;

	float mana;
	float manaMax;

	Spell spellsEnnemy[3];

public:
	Ennemy();

	//Faire les getter/setter

	//creation de l'ennemi ( etc...)
	void createEnnemy();
	//attaquer un ennemi --> attackFailed/AttackSucced
	bool attack(Character &e);
	//cast un spell S sur la personne p
	void castSpell(Spell s, Person &p);
	//montrer/rappeller les infos character
	void showInfo();
	//mourrir de la mort qui tue
	void die();

};

