#include "Spell.h"

Spell::Spell()
{
}

Spell::Spell(string n):nameSpell(n)
{
}


float Spell::castSpell()
{
	return 0.0;
}

int Spell::getID()
{
	return id;
}

void Spell::setID(int vID)
{
	id = vID;
}


string Spell::getNameSpell()
{
	return nameSpell;
}

void Spell::setNameSpell(string nSpell)
{
	nameSpell = nSpell;
}

float Spell::getManaCostSpell()
{
	return manaCost;
}

void Spell::getManaCostSpell(float mCost)
{
	manaCost = mCost;
}

