#include "Inventory.h"

Weapon Inventory::getActualWeapon()
{
	return actualWeapon;
}

void Inventory::equipWeapon()
{
	cout << "\n\nVoici votre inventaire :\n";
	bool possede = true;
	int i;
	for (i = 0; i < 4; i++) {
		if (weaponTab[i] == NULL) {
			if (i == 0) {
				cout << "\tAucune arme possédé";
				possede = false;
			}
			break;
		}
		else { cout << endl << weaponTab[i]->GetName() << " (" << i << ")\n"; }
	}
	if (possede) {
		cout << "\nVeuillez choisir une arme :\n";
		int select;
		cin.clear(); cin >> select;
		while (cin.fail() || select < 0 || select > i-1) {
			cout << "\nVeuillez entrer un chiffre valide :\n";
			cin >> select;
		}
		actualWeapon = *weaponTab[select];
		cout << actualWeapon.GetName() << " équipé\n";
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
		cout << endl << newWeapon->GetName() << " ajouté à votre inventaire\n";
	}
}
