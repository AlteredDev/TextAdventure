#include "Inventory.h"

Weapon* Inventory::equipWeapon()
{
	cout << "\n\nInventory :\n\n";
	bool possede = true;
	int i;
	for (i = 0; i < invSize; i++) {
		if (weaponTab[i] == NULL) {
			if (i == 0) {
				cout << "\tAucune arme possédé";
				possede = false;
			}
			break;
		}
		else { cout  << weaponTab[i]->GetName() << " (" << i << ")\n"; }
	}
	if (possede) {
		cout << "\nChoose your weapon :\n";
		int select;
		cin.clear(); cin >> select;
		while (cin.fail() || select < 0 || select > i-1) {
			cout << "\nEnter a valid number :\n";
			cin >> select;
		}
		return weaponTab[select];
	}
}

void Inventory::addWeapon(Weapon *newWeapon)
{
	bool plein = true;
	int i;
	for (i = 0; i < invSize; i++) {
		if (weaponTab[i] == NULL) {
			plein = false;
			break;
		}
	}
	if (plein) {cout << "\nWeapon inventory is full\n";}

	else {
		weaponTab[i] = newWeapon;
		cout << endl << newWeapon->GetName() << " added to the inventory\n";
	}
}

void Inventory::setInvSize(int size)
{
	for (int i = 0; i < size; i++) {
		weaponTab.push_back(NULL);
	}
	invSize = size;
}

vector<Weapon*> Inventory::getWeaponTab()
{
	return weaponTab;
}
