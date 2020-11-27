#ifndef SPELLHEAL_H
#define SPELLHEAL_H

#include "Spell.h"

class SpellHeal : public Spell
{
private:
	float healAmount;

public:
	SpellHeal();
	SpellHeal(string vName, float vManaCost, float hAmount);

	void castSpell(Character* c);

	float getHealAmount();
	void setHealAmount(float hAmount);
};

#endif // !SPELLHEAL_H