#include "Spell.h"

Spell::Spell()
{
}

Spell::Spell(string n):nameSpell(n)
{
}


void Spell::castSpell()
{
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

