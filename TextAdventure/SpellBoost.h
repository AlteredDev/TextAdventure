#ifndef SPELLBOOST_H
#define SPELLBOOST_H

#include "Spell.h"

class SpellBoost : public Spell
{
private:
	float boostAmount;

public:
	SpellBoost();
	SpellBoost(string vName, float vManaCost, float vBoostAmount);

	void castSpell(Character* c);

	float getBoostAmount();
	void setBoostAmount(float vBoostAmount);
};

#endif // !SPELLBOOST_H