#include "Spell.h"

Spell::Spell()
{
}

Spell::Spell(string n):nameSpell(n)
{
}

/*
void Spell::castSpell(Character &c)
{
}
*/

string Spell::getName()
{
	return nameSpell;
}

void Spell::setName(string nSpell)
{
	nameSpell = nSpell;
}

float Spell::getManaCost()
{
	return manaCost;
}

void Spell::getManaCost(float mCost)
{
	manaCost = mCost;
}

