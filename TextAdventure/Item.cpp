#include "Item.h"

void Item::addPotion(Potion* newPotion)
{
	potionTab.push_back(newPotion);
}

vector<Potion*> Item::getPotionTab()
{
	return potionTab;
}
