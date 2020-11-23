#include "Weapon.h"

Weapon::Weapon()
{
}

void Weapon::SetName(string n)
{
	name = n;
}

void Weapon::SetDamage(float dmg)
{
	damage = dmg;
}

void Weapon::SetDefense(float dfn)
{
	defense = dfn;
}

void Weapon::setRarity(float vRarity)
{
	rarity = vRarity;
}

string Weapon::GetName() {return name;}

float Weapon::GetDamage() {return damage;}

float Weapon::GetDefense() {return defense;}

float Weapon::setRarity()
{
	return rarity;
}
