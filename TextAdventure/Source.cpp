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



	Weapon w1("Wood Shield", 3, 25, "Common");
	Weapon w2("Wood Sword", 20, 1, "Common");
	Weapon w3("Wizard Stick", 15, 1, "Common");
	Weapon w4("Bad Spear", 12, 1, "Common");
	Weapon w5("Spiked Shield", 5, 15, "Common");

	Character c1(&Person("Jinx", "Piltover", 23, 18.0f), true, false, false, "Mage", "Fed Yasuo", "Beauty Crime", 19.0f, 0.75f, 1.25f, 0.25f, 300.0f, 525.0f, 120.0f, 120.0f);
	Character c2(&Person("Gragas", "Grobidou", 30, 12.0f), true, false, false, "Warrior", "Alcohol", "Grassouillet", 15.0f, 0.75f, 1.25f, 0.25f, 725.0f, 725.0f, 25.0f, 25.0f);
	Character c3(&Person("OTPZed", "RQFlash", 30, 12.0f), false, false, false, "Warrior", "Light", "Shadows", 15.0f, 0.75f, 1.25f, 0.25f, 725.0f, 725.0f, 25.0f, 25.0f);
	Character c4(&Person("NeekoNii", "Lovenida", 21, 12.0f), false, false, false, "Paladin", "Alcohol", "Grassouillet", 11.0f, 0.75f, 1.25f, 0.25f, 880.0f, 880.0f, 75.0f, 75.0f);
	vector<Character*> starterPack;
	starterPack.push_back(&c1);
	starterPack.push_back(&c2);
	starterPack.push_back(&c3);
	starterPack.push_back(&c4);


	SpellHeal s1("Soin fort", 150.0f, 2000.0f);
	SpellHeal s2("Soin faible", 20.0f, 20.0f);
	Potion po1("Speed Potion", 2, false, 0, false, 0, true, 2);
	Potion po2("Health Potion", 1, false, 0, true, 5, false, 0);
	Potion po3("Strength Potion", 3, true, 2, false, 0, false, 0);
	//SpellBoost sb1("Initiative", 0.3f, 1.25);

	Inventory groupInv;
	Item groupItem;
	groupInv.setItemTab(&groupItem); //bind les Item à l'inv de group

	vector<Character> temp;
	vector<Character*> group;
	vector<Character*> ennemies;
	ennemies.push_back(&c1);
	ennemies.push_back(&c2);
	ennemies[0]->setActualWeapon(&w5);
	cout << ennemies[0]->getActualWeapon()->GetName() << endl;
	cout << ennemies[0]->getActualWeapon()->GetDefense() << endl;

	ennemies[1]->setActualWeapon(&w4);
	cout << ennemies[1]->getActualWeapon()->GetName() << endl;
	cout << ennemies[1]->getActualWeapon()->GetDefense() << endl;


	system("pause");

	/*

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
	groupInv.getItemTab()->addPotion(&po1);
	groupInv.getItemTab()->addPotion(&po2);
	groupInv.getItemTab()->addPotion(&po3);

	Battle b1;
	b1.inBattle(group, ennemies, groupInv);






	*/

	int intInput;

	//Intro
	cout << "Welcome, young adventurer, to TextAdventure!" << endl;
	cout << "You are going to start a whole new adventure.\nWould you like to create a character[1] or use an already created character[2] :\n" << endl;
	intInput = RangeIntInput(1, 2);

	if (intInput == 1) {
		cout << "\nHow many character do you want to create (1 min - 4 max) :\n";
		intInput = RangeIntInput(1, 4);

		for (int i = 0; i < intInput; i++) {
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
				//groupInv.addWeapon(&w3);
				group[i]->setActualWeapon(&w3);
				group[i]->spells.push_back(&s1);
				group[i]->spells.push_back(&s2);
				continue;
			}
			else if (group[i]->getClassName() == "Paladin") {
				//groupInv.addWeapon(&w4);
				group[i]->spells.push_back(&s2);
				group[i]->setActualWeapon(&w4);
				continue;
			}
			else if (group[i]->getClassName() == "Warrior") {
				//groupInv.addWeapon(&w2);
				group[i]->setActualWeapon(&w2);
				group[i]->spells.push_back(nullptr);
				continue;
			}
		}

		for (int i = 0; i < group.size(); i++) {
			cout << " [" << i << "]" << endl;
			group[i]->showInfo();
		}
		system("pause");
	}
	/**/
	if (intInput == 2) {
		cout << "\nHow many character do you want to play (1 min - 4 max) :\n";
		intInput = RangeIntInput(1, 4);

		groupInv.setInvSize(starterPack.size() * 4); //set inv size (only for the weapons)
		for (int i = 0; i < starterPack.size(); i++) {
			if (starterPack[i]->getClassName() == "Mage") {
				groupInv.addWeapon(&w3);
				starterPack[i]->setActualWeapon(&w3);
				continue;
			}
			else if (starterPack[i]->getClassName() == "Paladin") {
				groupInv.addWeapon(&w4);
				starterPack[i]->setActualWeapon(&w4);
				continue;
			}
			else if (starterPack[i]->getClassName() == "Warrior") {
				groupInv.addWeapon(&w2);
				starterPack[i]->setActualWeapon(&w2);
				continue;
			}
		}

		//cout << starterPack.size();
		for (int j = 0; j < 4; j++) {
			cout << " [" << j << "]" << endl;
			//cout << starterPack[j]->getFirstName() << endl;
			starterPack[j]->showInfo();
		}
		vector<Character*> starterPackTemp;
		starterPackTemp = starterPack;

		int intInputCharacter;

		for (int i = 0; i < intInput; i++) {

			cout << "Select the character you want to play :\n" << endl;
			intInputCharacter = RangeIntInput(0, starterPackTemp.size());

			group.push_back(starterPackTemp[intInputCharacter]);
			vector<Character*> starterPackTemp;
			for (int j = 0; j < starterPack.size(); j++) {
				if (j != intInputCharacter) {
					starterPackTemp.push_back(starterPack[j]);
				}
			}
			for (int p = 0; p < starterPackTemp.size(); p++) {
				cout << " [" << p << "]" << endl;
				//cout << starterPack[j]->getFirstName() << endl;
				starterPackTemp[p]->showInfo();
			}
			starterPack = starterPackTemp;
			
		}
		system("cls");
		for (int i = 0; i < group.size(); i++) {
			cout << " [" << i << "]" << endl;
			group[i]->showInfo();
		}
	}


	groupInv.getItemTab()->addPotion(&po1);
	groupInv.getItemTab()->addPotion(&po2);
	groupInv.getItemTab()->addPotion(&po3);

	Battle b1;
	b1.inBattle(group, ennemies, groupInv);





	return 0;
}

