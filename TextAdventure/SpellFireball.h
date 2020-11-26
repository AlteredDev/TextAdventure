#pragma once
#include "Spell.h"

class SpellFireball : public Spell
{
private:
	float damageAmount;

public:
	SpellFireball();
	SpellFireball(Spell *s, float dmgAmount);

	float getSpellEffect();

	float getDamageAmount();
	void setDamageAmount(float dmgAmount);
};
