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

string Weapon::GetName() {return name;}

float Weapon::GetDamage() {return damage;}

float Weapon::GetDefense() {return defense;}
