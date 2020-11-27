#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Weapon.h"
#include "Item.h"

using namespace std;

class Inventory
{
private:
	vector<Weapon*> weaponTab;
	Item* itemTab;
	int invSize = 0;

public:
	Weapon* equipWeapon();
	void addWeapon(Weapon *newWeapon);
	void setInvSize(int size);
	vector<Weapon*> getWeaponTab();
	void setItemTab(Item* newItem);
	Item* getItemTab();

};

