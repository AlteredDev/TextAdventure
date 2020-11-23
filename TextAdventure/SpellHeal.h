#pragma once
#include "Spell.h"

class SpellHeal : public Spell
{
private :
	float healAmount;

public:
	SpellHeal();
	SpellHeal(float hAmount);

	void castSpell(Character &c);

	float getHealAmount();
	void setHealAmount(float hAmount);

};

