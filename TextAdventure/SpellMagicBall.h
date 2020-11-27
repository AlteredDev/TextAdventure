#ifndef SPELLMAGICBALL_H
#define SPELLMAGICBALL_H

#include "Spell.h"

class SpellMagicBall : public Spell
{
private:
	float damageAmount;
	string statusEffect;

public:
	SpellMagicBall();
	SpellMagicBall(string vName, float vManaCost, float dmgAmount);

	void castSpell(Character * c);

	void addStatusEffect(Character * c);

	//GETTER/SETTER
	float getDamageAmount();
	void setDamageAmount(float dmgAmount);

	string getStatusEffect();
	void setStatusEffect(string vStatusEffect);
};

#endif // !SPELLMAGICBALL_H
