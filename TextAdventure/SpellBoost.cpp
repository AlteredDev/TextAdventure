#include "SpellBoost.h"
#include "Character.h"

SpellBoost::SpellBoost():Spell()
{
}

SpellBoost::SpellBoost(string vName, float vManaCost, float vBoostAmount):Spell(vName, vManaCost), boostAmount(vBoostAmount)
{
}

void SpellBoost::castSpell(Character * c)
{
	if (getNameSpell() == "Strength") {	//boostAmount doit obtenir des valeurs >0  <10 (pour pas broken af)
		c->setStrength(c->getStrength() * boostAmount);
		cout << "The strength of " << c->getFirstName() << " " << c->getLastName() << " has been multiplied by " << boostAmount << endl;
		cout << "The strength of " << c->getFirstName() << " " << c->getLastName() << " is now : " << c->getStrength() << endl;
	}
	if (getNameSpell() == "HP") {	//boostAmount doit obtenir des valeurs >0  <10 (pour pas broken af)
		c->setHPMax(c->getHPMax() * boostAmount);
		cout << "The maximal HP of " << c->getFirstName() << " " << c->getLastName() << " has been multiplied by " << boostAmount << endl;
		cout << "The maximal HP of " << c->getFirstName() << " " << c->getLastName() << " is now : " << c->getHPMax() << endl;
	}
	if (getNameSpell() == "Initiative") {	//boostAmount doit obtenir des valeurs >0  <10 (pour pas broken af)
		c->setInitiative(c->getInitiative() * boostAmount);
		cout << "The initiative of " << c->getFirstName() << " " << c->getLastName() << " has been multiplied by " << boostAmount << endl;
		cout << "The initiative of " << c->getFirstName() << " " << c->getLastName() << " is now : " << c->getInitiative() << endl;
	}
	if (getNameSpell() == "WeaponDmg") {	//boostAmount doit obtenir des valeurs >0  <10 (pour pas broken af)
		c->getActualWeapon()->SetDamage(c->getActualWeapon()->GetDamage() * boostAmount);
		cout << "The damage of " << c->getActualWeapon()->GetName() << " has been multiplied by " << boostAmount << endl;
		cout << "The damage of " << c->getActualWeapon()->GetName() << " is now : " << c->getActualWeapon()->GetDamage() << endl;
	}
	if (getNameSpell() == "WeaponDefense") {	//boostAmount doit obtenir des valeurs >0  <10 (pour pas broken af)
		c->getActualWeapon()->SetDefense(c->getActualWeapon()->GetDefense() * boostAmount);
		cout << "The defense of " << c->getActualWeapon()->GetName() << " has been multiplied by " << boostAmount << endl;
		cout << "The defense of " << c->getActualWeapon()->GetName() << " is now : " << c->getActualWeapon()->GetDefense() << endl;
	}
}

float SpellBoost::getBoostAmount()
{
	return boostAmount;
}

void SpellBoost::setBoostAmount(float vBoostAmount)
{
	boostAmount = vBoostAmount;
}
