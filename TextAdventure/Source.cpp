#include "Character.h"
#include "SpellHeal.h"

int main() {

	Spell s;
	s.setNameSpell("SOIN");
	SpellHeal sHeal(&s,12);

	

	Person p1("Jinx", "Piltover");

	Character c2;

	Character c1(&p1,"Marksman",28.0);
	c1.showInfo();



	c1.castSpell(sHeal, c1);

	Weapon w1("Bouclier", 1, 10, 20);
	Weapon w2("Epee", 20, 0, 10);
	Weapon w3("Baton de mage", 5, 0, 30);
	Weapon w4("Lance", 15, 0, 5);
	Weapon w5("Blouclier à pointe", 5, 7, 35);

	c1.getInvChar().addWeapon(&w1);
	c1.getInvChar().addWeapon(&w2);
	c1.getInvChar().addWeapon(&w3);
	c1.getInvChar().addWeapon(&w4);
	c1.getInvChar().addWeapon(&w5);
	c1.getInvChar().equipWeapon();


	return 0;
}

