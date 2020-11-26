#include "SpellHeal.h"

SpellHeal::SpellHeal():Spell()
{
}

SpellHeal::SpellHeal(Spell * s, float hAmount):Spell(*s),healAmount(hAmount)
{
}

float SpellHeal::getSpellEffect()
{
	return getHealAmount();
}

float SpellHeal::getHealAmount()
{
	return healAmount;
}

void SpellHeal::setHealAmount(float hAmount)
{
	healAmount = hAmount;
}
