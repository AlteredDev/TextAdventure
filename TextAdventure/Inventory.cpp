#include "Inventory.h"

Weapon* Inventory::equipWeapon()
{
	system("cls");
	cout << "\n\nInventory :\n\n";
	bool possede = true;
	int i;
	for (i = 0; i < invSize; i++) {
		if (weaponTab[i] == nullptr) {
			if (i == 0) {
				cout << "\tNo weapon possessed";
				possede = false;
			}
			break;
		}
		else { 
			cout  << " [" << i << "]\n";
			weaponTab[i]->showInfoWeapon();
		}
	}
	if (possede) {
		cout << "\nChoose your weapon :\n";
		int select;
		cin.clear(); cin >> select;
		while (cin.fail() || select < 0 || select > i-1) {
			cout << "\nEnter a valid number :\n";
			cin >> select;
		}
		Weapon* newWeapon = weaponTab[select];
		for (i = 0; i < invSize - select; i++) {
			//cout << 1 << endl;
			//if (weaponTab[select + i] == NULL) { break; }
			if (select + i + 1 >= weaponTab.size() || weaponTab[select + i + 1] == nullptr) {
				weaponTab[select + i] = nullptr;
				break; 
			}
			weaponTab[select + i] = weaponTab[select + i + 1];
			
		}
		return newWeapon;
	}
}

void Inventory::addWeapon(Weapon *newWeapon)
{
	bool plein = true;
	int i;
	for (i = 0; i < invSize; i++) {
		if (weaponTab[i] == nullptr) {
			plein = false;
			break;
		}
	}
	if (plein) {
		int input;
		system("cls");
		cout << "\nThe weapon inventory is full, can't add " << newWeapon->GetName() << "\n\nDo you want to throw a weapon away :\t[1]Yes [2]No\n";
		cin >> input;
		if (input == 1) {
			system("cls");
			cout << "Inventory :\n\n";
			int a;
			for (a = 0; a < invSize; a++) {
				cout << weaponTab[a]->GetName() << " [" << a << "]\n";
			}
			cout << "\nChoose the weapon to throw away :\n";
			int select;
			cin.clear(); cin >> select;
			while (cin.fail() || select < 0 || select > a - 1) {
				cout << "\nEnter a valid number :\n";
				cin >> select;
			}
			weaponTab[select] = newWeapon;
			cout << endl << newWeapon->GetName() << " added to the inventory\n";
		}
		else {
			cout << endl << newWeapon->GetName() << " not added to the inventory\n";
		}
	}

	else {
		weaponTab[i] = newWeapon;
		cout << endl << newWeapon->GetName() << " added to the inventory\n";
	}
}

void Inventory::setInvSize(int size)
{
	for (int i = 0; i < size; i++) {
		weaponTab.push_back(nullptr);
	}
	invSize = size;
}

vector<Weapon*> Inventory::getWeaponTab()
{
	return weaponTab;
}

void Inventory::setItemTab(Item* newItem)
{
	itemTab = newItem;
}

Item* Inventory::getItemTab()
{
	return itemTab;
}
