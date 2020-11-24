#include "Weapon.h"

Weapon::Weapon():name(""), damage(0), defense(0), rarity(0)
{
}

Weapon::Weapon(string n, float dmg, float dfn, float vRarity):name(n), damage(dmg), defense(dfn), rarity(vRarity)
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

void Weapon::showInfoWeapon()
{
	cout << "\tName : " << GetName() << "\tDamage : " << GetDamage() << endl;


}
