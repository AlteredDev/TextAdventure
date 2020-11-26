#include "Spell.h"

Spell::Spell()
{
}

Spell::Spell(int vID, string vName):id(vID), nameSpell(vName)
{
}

float Spell::getSpellEffect()
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
