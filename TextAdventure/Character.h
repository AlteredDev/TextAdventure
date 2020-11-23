#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Class.h"
#include "Spell.h"

using namespace std;

class Character
{
private:
	Class classe;
	string name;
	string firstName;
	float pv;
	float strength;
	Weapon inventory[4];
	float criticPerc;
	Spell spells;
	float speed;

public:



};

