#include "Spell.h"
#include "Character.h"

Spell::Spell()
{
}

Spell::Spell(string vName, float vManaCost):nameSpell(vName), manaCost(vManaCost)
{
}

bool Spell::verifCastSpell(Character * c)
{
	if (getManaCostSpell() > c->getMana()) {
		cout << "You don't have enough mana to cast the spell." << endl;
		return false;
	}
	else {
		return true;
	}
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
