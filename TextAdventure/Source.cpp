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


	return 0;
}

