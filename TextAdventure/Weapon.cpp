#include "Weapon.h"

Weapon::Weapon():name(""), damage(1), defense(1), rarity("Common")
{
}

Weapon::Weapon(string vName, float dmg, float vDefense, string vRarity):name(vName), damage(dmg), defense(vDefense), rarity(vRarity)
{
	float multiplier = 1.00f;
	if (getRarity() == "Rare") {
		multiplier = 1.25f;
	}
	if (getRarity() == "Epic") {
		multiplier = 1.50f;
	}
	if (getRarity() == "Legendary") {
		multiplier = 1.75f;
	}
	SetDamage(GetDamage() * multiplier);
	SetDefense(GetDefense() * multiplier);
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

void Weapon::setRarity(string vRarity)
{
	rarity = vRarity;
}

string Weapon::GetName() {return name;}

float Weapon::GetDamage() {return damage;}

float Weapon::GetDefense() {return defense;}

string Weapon::getRarity()
{
	return rarity;
}

void Weapon::showInfoWeapon()
{
	cout << "\tName : " << GetName() << endl;
	cout << "\tDamage : " << GetDamage() << "\tDefense : " << GetDefense() << endl;
	cout << "\tRarity : " << getRarity() << endl;
}
