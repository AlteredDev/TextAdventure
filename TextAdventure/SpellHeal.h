#pragma once
#include "Spell.h"
#include "Character.h"

class SpellHeal : public Spell
{
private :
	float healAmount;

public:
	SpellHeal();
	SpellHeal(Spell *s, float hAmount);

	void castSpell(Character &c);

	float getHealAmount();
	void setHealAmount(float hAmount);

};

