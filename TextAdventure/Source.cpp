#include "Character.h"
#include "SpellHeal.h"

int RangeIntInput(int min, int max) {
	int input; cin >> input;
	while (cin.fail() || input < min || input > max) {
		cin.clear(); cin.ignore();
		cout << "\nEnter en valid number :\n";
		cin >> input;
	}
	return input;
}

void showGroupInv(Inventory Inv, vector<Character> Group) {
	system("cls");

	cout << "\nWeapon :\n\n";
	for (int i = 0; i < Inv.getWeaponTab().size(); i++) {
		if (Inv.getWeaponTab()[i] == NULL) {break;}
		cout << "\t" << Inv.getWeaponTab()[i]->GetName() << endl;
	}

	cout << "\n\nItems :\n\n";

	cout << "\n\nEquipment :\n\n";
	for (int i = 0; i < Group.size(); i++) {
		if (Group[i].getActualWeapon() != NULL) {
			cout << "\t" << Group[i].getFirstName() << " " << Group[i].getLastName() << " is equipped with a " << Group[i].getActualWeapon()->GetName() << endl;
		}
		else {
			cout << "\t" << Group[i].getFirstName() << " " << Group[i].getLastName() << " is unequipped" << endl;
		}
	}
}

int main() {

	Weapon w1("Wood Shield", 1, 10, 20);
	Weapon w2("Wood Sword", 20, 0, 10);
	Weapon w3("Wizard Stick", 5, 0, 30);
	Weapon w4("Bad Spear", 15, 0, 5);
	Weapon w5("Spiked Shield", 5, 7, 35);

	vector<Character> group;
	Inventory groupInv;

	vector<Character> ennemies;

	int intInput;

	//Intro
	cout << "\n\tWelcome, young adventurer, to TextAdventure!\n\nYou are going to start a whole new adventure.\nWould you like to create a character (1) or use an already created character (2) :\n";
	intInput = RangeIntInput(1, 2);


	cout << "\nHow many characater do you want to create (1 min - 4 max) :\n";
	intInput = RangeIntInput(1, 4);


	for (int i = 0; i < intInput; i++) {
		system("cls");
		Character newCharacter;
		group.push_back(newCharacter); //inserting the character
		group[i].createCharacter(); //creation du perso
		group[i].setInvChar(&groupInv); //bind l'inv du perso à celui du group
	}
	groupInv.setInvSize(group.size() * 4); //set inv size
	system("cls");
	for (int i = 0; i < group.size(); i++) {
		if (group[i].getClassName() == "Mage") {
			groupInv.addWeapon(&w3);
			continue;
		}
		else if (group[i].getClassName() == "Paladin") {
			groupInv.addWeapon(&w4);
			continue;
		}
		else if (group[i].getClassName() == "Warrior") {
			groupInv.addWeapon(&w2);
			continue;
		}
	}

	showGroupInv(groupInv, group);

	for (int i = 0; i < group.size(); i++) {
		group[i].equipWeapon(&groupInv);
	}


	showGroupInv(groupInv, group);

	//Vérifier à chaque tour de jeu si un Character isDead() -->
	//		SI true : enlever tableau + appel destructeur
	//		SI false : rien


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

