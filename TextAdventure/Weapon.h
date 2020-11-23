#pragma once
#include "Character.h"

class Weapon
{
private:
	string name;
	float damage;
	float defense;

public:
	Weapon();

	void SetName(string n);
	void SetDamage(float dmg);
	void SetDefense(float dfn);

	string GetName();
	float GetDamage();
	float GetDefense();
};

