#ifndef ITEM_H
#define ITEM_H

#include "Potion.h"

class Item
{
private:
	vector<Potion*> potionTab;
	Potion usedPotion;

public:
	void addPotion(Potion* newPotion);
	vector<Potion*> getPotionTab();
	int useItem();
	Potion equipPotion(int index);
	Potion getUsedPotion();
};

#endif // !ITEM_H