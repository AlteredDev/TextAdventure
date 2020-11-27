#include "Item.h"

void Item::addPotion(Potion* newPotion)
{
	int i;
	for (i = 0; i < potionTab.size(); i++) {
		if (potionTab[i] == nullptr) {
			potionTab[i] = newPotion;
			break;
		}
	}
	if (i == potionTab.size()) {
		potionTab.push_back(newPotion);
	}
}

vector<Potion*> Item::getPotionTab()
{
	return potionTab;
}

int Item::useItem()
{
	system("cls");
	cout << "\n\nInventory :\n\n\nPotion :\n\n";
	bool possede = false;
	int i;
	for (i = 0; i < potionTab.size(); i++) {
		if (potionTab[i] == nullptr) {
			continue;
		}
		else {
			cout << potionTab[i]->getName() << " (" << i << ")\n";
			possede = true;
		}
	}

	if (possede) {
		cout << "\nChoose the item to use :\n";
		int select;
		cin.clear(); cin >> select;
		while (cin.fail() || select < 0 || select > potionTab.size()) {
			cout << "\nEnter a valid number :\n";
			cin >> select;
		}
		if (select >= 0 && select <= potionTab.size()) {
			usedPotion = equipPotion(select);
			return 1;
		}
	}
	else {
		return 0;
	}
}

Potion Item::equipPotion(int index)
{
	Potion usedPotion = *potionTab[index];
	potionTab[index] = nullptr;

	for (int i = index; i-1 < potionTab.size(); i++) {
		if (potionTab[i + 1] == nullptr) {
			break;
		}
		else {
			potionTab[i] = potionTab[i + 1];
		}
	}
	return usedPotion;
}

Potion Item::getUsedPotion()
{
	return usedPotion;
}
