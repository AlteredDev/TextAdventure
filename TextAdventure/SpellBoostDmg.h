#pragma once
#include "Spell.h"

class SpellBoostDmg : public Spell
{
private:
	float boostDamageAmount;

public:
	SpellBoostDmg();
	SpellBoostDmg(Spell *s, float dmgBoostAmount);

	float getSpellEffect();

	float getBoostDamageAmount();
	void setBoostDamageAmount(float dmgBoostAmount);
};

