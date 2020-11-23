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
	float pv;
	float strength;
	Weapon inventory[4];
	float criticPerc;
	Spell spells[3];
	float speed;

public:
	Character();
	void SetCharacter();


};

