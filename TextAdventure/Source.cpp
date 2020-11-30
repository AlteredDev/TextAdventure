#include "Battle.h"

int RangeIntInput(int min, int max) {
	int input; cin >> input;
	while (cin.fail() || input < min || input > max) {
		cin.clear(); cin.ignore();
		cout << "\nEnter en valid number :\n";
		cin >> input;
	}
	return input;
}

void showGroupInv(Inventory inv, vector<Character*> group) {
	system("cls");

	cout << "\nWeapon :\n\n";
	for (int i = 0; i < inv.getWeaponTab().size(); i++) {
		if (inv.getWeaponTab()[i] == nullptr) { break; }
		cout << "\t" << inv.getWeaponTab()[i]->GetName() << endl;
	}

	cout << "\n\nItems :\n\n";
	for (int i = 0; i < inv.getItemTab()->getPotionTab().size(); i++) {
		if (inv.getItemTab()->getPotionTab()[i] == nullptr) { continue; }
		cout << "\t" << inv.getItemTab()->getPotionTab()[i]->getName() << endl;
	}

	cout << "\n\nEquipment :\n\n";
	for (int i = 0; i < group.size(); i++) {
		if (group[i]->getActualWeapon() != nullptr) {
			cout << "\t" << group[i]->getFirstName() << " " << group[i]->getLastName() << " is equipped with a " << group[i]->getActualWeapon()->GetName() << endl;
		}
		else {
			cout << "\t" << group[i]->getFirstName() << " " << group[i]->getLastName() << " is unequipped" << endl;
		}
	}
	cout << endl; system("pause");
}


int main() {

	Character c1(&Person("Jinx","Piltover", 10),"Paladin",100,100);
	Character c2(&Person("Patrick", "Oui", 5), "Paladin", 25, 100);
	c1.setMana(12.0f);
	c2.setMana(12.0f);

	SpellHeal s1("SOIN",0.2f,25);
	SpellBoost sb1("Initiative", 0.3f, 1.25);

	cout << "debut heal" << endl;
	c1.spells.push_back(&s1);
	cout << c2.getHP() << endl;
	c1.spells[0]->castSpell(&c2);
	cout << c2.getHP() << endl;

	cout << "debut initiative" << endl;
	c2.spells.push_back(&sb1);
	cout << c1.getInitiative() << endl;
	c2.spells[0]->castSpell(&c1);
	cout << c2.getInitiative() << endl;
	

	Weapon w1("Wood Shield", 1, 10, 20);
	Weapon w2("Wood Sword", 20, 0, 10);
	Weapon w3("Wizard Stick", 5, 0, 30);
	Weapon w4("Bad Spear", 15, 0, 5);
	Weapon w5("Spiked Shield", 5, 7, 35);

	Potion po1("Speed Potion", 2, false, 0, false, 0, true, 2);
	Potion po2("Health Potion", 1, false, 0, true, 5, false, 0);
	Potion po3("Strength Potion", 3, true, 2, false, 0, false, 0);

	vector<Character*> group;
	Inventory groupInv;
	Item groupItem;
	groupInv.setItemTab(&groupItem); //bind les Item à l'inv de group

	vector<Character*> ennemies;

	int intInput;

	//Intro
	cout << "\n\tWelcome, young adventurer, to TextAdventure!\n\nYou are going to start a whole new adventure.\nWould you like to create a character (1) or use an already created character (2) :\n";
	intInput = RangeIntInput(1, 2);


	cout << "\nHow many characater do you want to create (1 min - 4 max) :\n";
	intInput = RangeIntInput(1, 4);


	vector<Character> temp;

	for (int i = 0; i < intInput; i++) {
		system("cls");
		Character newCharacter;
		temp.push_back(newCharacter);
		temp[i].createCharacter();
		temp[i].setInvChar(&groupInv);
		group.push_back(&temp[i]);
	}

	groupInv.setInvSize(group.size() * 4); //set inv size (only for the weapons)
	system("cls");
	for (int i = 0; i < group.size(); i++) {
		if (group[i]->getClassName() == "Mage") {
			groupInv.addWeapon(&w3);
			continue;
		}
		else if (group[i]->getClassName() == "Paladin") {
			groupInv.addWeapon(&w4);
			continue;
		}
		else if (group[i]->getClassName() == "Warrior") {
			groupInv.addWeapon(&w2);
			continue;
		}
	}

	showGroupInv(groupInv, group);
	groupInv.getItemTab()->addPotion(&po1);
	groupInv.getItemTab()->addPotion(&po2);
	groupInv.getItemTab()->addPotion(&po3);

	for (int i = 0; i < group.size(); i++) {
		group[i]->equipWeapon(&groupInv);
	}

	showGroupInv(groupInv, group);

	Battle b1;
	b1.inBattle(group, ennemies, groupInv);




	/*Spell s;
	s.setNameSpell("SOIN");
	SpellHeal sHeal(&s,12);
	SpellHeal s1(&s, 12);



	Person p1("Jinx", "Piltover");

	Character c2;

	Character c1(&p1,"Marksman",28.0, 58.0);
	c1.showInfo();
	c1.castSpell(s1, c1); // j'ai pas pointeur

	c1.showInfo();

	Person p1("Jinx", "Piltover");
	Character c1(&p1, "Marksman", 28.0, 58.0);


	Inventory i;
	c1.setInvChar(&i);

	i.addWeapon(&w1);
	i.addWeapon(&w2);
	i.addWeapon(&w3);
	i.addWeapon(&w4);
	i.addWeapon(&w5);
	c1.getInvChar().equipWeapon();*/



	return 0;
}

