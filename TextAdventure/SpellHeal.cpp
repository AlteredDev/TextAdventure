#include "SpellHeal.h"

SpellHeal::SpellHeal():Spell()
{
}

SpellHeal::SpellHeal(Spell *s, float hAmount):Spell(*s),healAmount(hAmount)
{
}

void SpellHeal::castSpell(Character &c)
{
	cout << "Vous lancez le sort de soin et " << c.getFirstName() << " récupère " << getHealAmount() << " points de vie." << endl;
	
	if ((c.getHP() + getHealAmount()) >= c.getHPMax()) {
		c.setHP(c.getHPMax());
	}
	else {
		c.setHP(c.getHP() + getHealAmount());
	}
	

}


float SpellHeal::getHealAmount()
{
	return healAmount;
}

void SpellHeal::setHealAmount(float hAmount)
{
	healAmount = hAmount;
}
