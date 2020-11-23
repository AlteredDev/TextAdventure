#pragma once
#include "Character.h"

class Spell
{
protected:
	string nameSpell;
	float manaCost;
	//float damage;

public:
	Spell();
	Spell(string n);

	virtual void castSpell(Character &c) = 0;

	string getName();
	void setName(string nSpell);

	float getManaCost();
	void getManaCost(float mCost);
};

