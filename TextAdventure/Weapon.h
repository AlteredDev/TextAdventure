#pragma once
#include <iostream>
#include <string>

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

	void SetName(string n);
	void SetDamage(float dmg);
	void SetDefense(float dfn);
	void setRarity(float vRarity);

	string GetName();
	float GetDamage();
	float GetDefense();
	float setRarity();
};

