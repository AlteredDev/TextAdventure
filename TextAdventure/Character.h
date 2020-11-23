#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Spell.h"

using namespace std;

class Character
{
private:
	string name;
	string className;
	float hp;
	float hpMax;
	float strength;
	float mana;
	float manaMax;
	Weapon inventory[4];
	float criticPerc;
	Spell spells[3];
	float speed;

public:
	Character();
	void CreateCharacter();


};

