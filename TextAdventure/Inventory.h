#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Weapon.h"

using namespace std;

class Inventory
{
private:
	vector<Weapon*> weaponTab;
	int invSize = 0;

public:
	Weapon* equipWeapon();
	void addWeapon(Weapon *newWeapon);
	void setInvSize(int size);
	vector<Weapon*> getWeaponTab();
};

