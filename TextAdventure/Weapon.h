#pragma once
#include "Character.h"

class Weapon : public Character
{
private:
	string name;
	float damage;
	float defense;

public:
	void SetName();
	void SetDamage();
	void SetDefense();

	string GetName();
	float GetDamage();
	float GetDefense();
};

