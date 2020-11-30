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
	string rarity;
	float damage;
	float defense;


public:
	Weapon();
	Weapon(string vName, float dmg, float vDefense, string vRarity);

	void SetName(string n);
	void SetDamage(float dmg);
	void SetDefense(float dfn);
	void setRarity(string vRarity);

	string GetName();
	float GetDamage();
	float GetDefense();
	string getRarity();

	void showInfoWeapon();
};

#endif // !WEAPON_H