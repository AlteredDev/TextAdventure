#include "SpellHeal.h"
#include "Character.h"

SpellHeal::SpellHeal():Spell()
{
}

SpellHeal::SpellHeal(string vName, float vManaCost, float hAmount):Spell(vName, vManaCost), healAmount(hAmount)
{
}

void SpellHeal::castSpell(Character * c)
{
	cout << "You cast the spell : " << getNameSpell() << " on " << c->getFirstName() << " " << c->getLastName() << "." << endl;
	if ((c->getHP() + healAmount) >= c->getHPMax()) {
		c->setHP(c->getHPMax());
	}
	else {
		c->setHP(c->getHP() + healAmount);
	}
	cout << c->getFirstName() << " " << c->getLastName() << " has recovered " << healAmount << " HP !" << endl;
}

float SpellHeal::getHealAmount()
{
	return healAmount;
}

void SpellHeal::setHealAmount(float hAmount)
{
	healAmount = hAmount;
}
