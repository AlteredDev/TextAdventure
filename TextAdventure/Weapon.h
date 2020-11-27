#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon
{
private:
	string name;
	float damage;
	float defense;
	float rarity;

public:
	Weapon();
	Weapon(string n, float dmg, float dfn, float vRarity);

	void SetName(string n);
	void SetDamage(float dmg);
	void SetDefense(float dfn);
	void setRarity(float vRarity);

	string GetName();
	float GetDamage();
	float GetDefense();
	float setRarity();

	void showInfoWeapon();
};

#endif // !WEAPON_H