#ifndef ITEM_H
#define ITEM_H

#include "Potion.h"

class Item
{
private:
	vector<Potion*> potionTab;

public:
	void addPotion(Potion* newPotion);
	vector<Potion*> getPotionTab();
};

#endif // !ITEM_H