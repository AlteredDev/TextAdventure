#include "SpellHeal.h"

SpellHeal::SpellHeal()
{
}

SpellHeal::SpellHeal(float hAmount):healAmount(hAmount)
{
}

void SpellHeal::castSpell(Character &c)
{
	//cout << "Vous lancez le sort de soin et " << c.getName() << " r�cup�re " << getHealAmount() << " points de vie." << endl;
	/*
	if ((c.getHP() + getHealAmount()) >= c.HPMax) {
		c.setHP(c.HPMax);
	}
	else {
		c.setHP(c.getHP() + getHealAmount());
	}
	*/

}

float SpellHeal::getHealAmount()
{
	return healAmount;
}

void SpellHeal::setHealAmount(float hAmount)
{
	healAmount = hAmount;
}
