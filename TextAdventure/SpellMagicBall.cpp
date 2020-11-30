#include "SpellMagicBall.h"
#include "Character.h"

SpellMagicBall::SpellMagicBall():Spell()
{
}

SpellMagicBall::SpellMagicBall(string vName, float vManaCost,float dmgAmount):Spell(vName,vManaCost), damageAmount(dmgAmount)
{
}

void SpellMagicBall::castSpell(Character * c)
{
	cout << "You cast the spell : " << getNameSpell() << " on " << c->getFirstName() << " " << c->getLastName() << "." << endl;
	if ((c->getHP() - damageAmount) <= 0) {
		c->die();
	}
	else {
		//faire calculs random pour effets de status a appliquer
		c->setHP(c->getHP() - damageAmount);
	}
}

void SpellMagicBall::addStatusEffect(Character * c)
{
}

float SpellMagicBall::getDamageAmount()
{
	return damageAmount;
}

void SpellMagicBall::setDamageAmount(float dmgAmount)
{
	damageAmount = dmgAmount;
}

string SpellMagicBall::getStatusEffect()
{
	return statusEffect;
}

void SpellMagicBall::setStatusEffect(string vStatusEffect)
{
	statusEffect = vStatusEffect;
}
