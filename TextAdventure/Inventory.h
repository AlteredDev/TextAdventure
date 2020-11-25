#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Weapon.h"

using namespace std;

class Inventory
{
private:
	Weapon* weaponTab[4] = {};
	Weapon actualWeapon;
	int invSize = 0;

public:
	Weapon getActualWeapon();
	void equipWeapon();
	void addWeapon(Weapon *newWeapon);
	void setInvSize(int size);
};

