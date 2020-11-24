#include "Inventory.h"

Weapon Inventory::getActualWeapon()
{
	return actualWeapon;
}

void Inventory::equipWeapon()
{
	cout << "\nVeuillez selectionnez votre arme :\n\n";
	bool possede = true;
	for (int i = 0; i < 4; i++) {
		if (weaponTab[i] == NULL) {
			if (i == 0) {
				cout << "Aucune arme possédé";
				possede = false;
			}
			break;
		}
		cout << endl << weaponTab[i]->GetName() << " (" << i << ") \n\n";
	}
	if (possede) {
		int select;
		cin >> select;
		actualWeapon = *weaponTab[select];
		cout << actualWeapon.GetName() << " équipé";
	}
}

void Inventory::addWeapon(Weapon *newWeapon)
{
	bool plein = true;
	int i;
	for (i = 0; i < 4; i++) {
		if (weaponTab[i] == NULL) {
			plein = false;
			break;
		}
	}
	if (plein) {cout << "\nInventaire d'arme plein";}

	else {
		weaponTab[i] = newWeapon;
		cout << "\nArme ajouté";
	}
}
