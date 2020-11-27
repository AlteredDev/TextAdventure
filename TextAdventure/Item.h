#pragma once
#include "Potion.h"

class Item
{
private:
	vector<Potion*> potionTab;

public:
	void addPotion(Potion* newPotion);
	vector<Potion*> getPotionTab();
};

