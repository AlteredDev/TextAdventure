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

public:
	Weapon getActualWeapon();
	void equipWeapon();
	void addWeapon(Weapon *newWeapon);
};

