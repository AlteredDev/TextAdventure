#pragma once
#include "Spell.h"

class SpellHeal : public Spell
{
private:
	float healAmount;

public:
	SpellHeal();
	SpellHeal(Spell *s, float hAmount);

	float getSpellEffect();

	float getHealAmount();
	void setHealAmount(float hAmount);
};

