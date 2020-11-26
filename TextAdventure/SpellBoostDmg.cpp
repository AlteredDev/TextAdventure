#include "SpellBoostDmg.h"

SpellBoostDmg::SpellBoostDmg():Spell()
{
}

SpellBoostDmg::SpellBoostDmg(Spell * s, float dmgBoostAmount):Spell(*s), boostDamageAmount(dmgBoostAmount)
{
}

float SpellBoostDmg::getSpellEffect()
{
	return getBoostDamageAmount();
}

float SpellBoostDmg::getBoostDamageAmount()
{
	return boostDamageAmount;
}

void SpellBoostDmg::setBoostDamageAmount(float dmgBoostAmount)
{
	boostDamageAmount = dmgBoostAmount;
}
