#include "SpellFireball.h"

SpellFireball::SpellFireball():Spell()
{
}

SpellFireball::SpellFireball(Spell * s, float dmgAmount):Spell(*s),damageAmount(dmgAmount)
{
}

float SpellFireball::getSpellEffect()
{
	return getDamageAmount();
}

float SpellFireball::getDamageAmount()
{
	return damageAmount;
}

void SpellFireball::setDamageAmount(float dmgAmount)
{
	damageAmount = dmgAmount;
}
