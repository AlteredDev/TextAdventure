#pragma once
#include "Character.h"

class Weapon : public Character
{
private:
	string name;
	float damage;
	float defense;

public:
	string GetName();
};

