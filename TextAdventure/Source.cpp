#include "Battle.h"

int RangeIntInput(int min, int max) {
	int input; cin >> input;
	while (cin.fail() || input < min || input > max) {
		cin.clear(); cin.ignore();
		cout << "\nEnter a valid number :\n";
		cin >> input;
	}
	return input;
}

string rangeStringInput(string min, string max) {
	string input;
	string word = "";
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		word += toupper(input[i]);
	}

	if (word == min || word == max) {
		return word;
	}
	else {
		cin.clear(); cin.ignore();
		cout << "\nEnter a valid answer :\n";
		word = "";
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			word += toupper(input[i]);
		}
	}

	/*
	while (cin.fail() || word != min || word != max) {
		cin.clear(); cin.ignore();
		cout << "\nEnter a valid answer :\n";
		word = "";
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			word += toupper(input[i]);
		}
		cout << "word : " << word << "min : " << min << endl;
	}
	*/
	//return word;
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
	system("cls");

	Weapon w1("Stick Launcher", 14.0f, 9.0f, "Rare"); // Jinx
	Weapon w2("Diamond Sword", 15.0f, 9.0f, "Legendary"); // Remi
	Weapon w3("Wizard Stick", 9.0f, 5.0f, "Epic"); // KAO
	Weapon w4("Magic Mass", 12.0f, 15.0f, "Common"); // Rudhy
	Weapon w5("Broken Spiked Shield", 4.5f, 70.0f, "Common"); // Warrior
	Weapon w6("Magic Sword", 7.0f, 3.0f, "Common"); // Paladin
	Weapon w7("Magic Lance", 9.0f, 2.0f, "Common"); // Mage
	Weapon w8("Mimic Tongue", 10.0f, 30.0f, "Rare"); // Mimic
	Weapon w9("Mysterious Weapon", 14.0f, 20.0f, "Rare"); // Mysterious

	//Starter Pack personnages
	Character c1(&Person("Lady Jinx", "Piltovia", 22, 26.0f), false, false, false, "Range Mage", "Justice", "Beauty Crime++", 20.0f, 0.25f, 1.30f, 0.75f, 700.0f, 700.0f, 300.0f, 300.0f);
	Character c2(&Person("Sir Remi", "Daivedeux", 30, 15.0f), false, false, false, "Warrior", "???", "C++", 18.0f, 0.15f, 1.85f, 0.75f, 925.0f, 925.0f, 25.0f, 25.0f);
	Character c3(&Person("Lord Rudhy", "Altered", 20, 21.0f), false, false, false, "Paladin", "Shadow", "Light++", 15.5f, 0.20f, 1.50f, 0.75f, 900.0f, 900.0f, 150.0f, 150.0f);
	Character c4(&Person("Feyrosia", "KAO", 20, 28.0f), false, false, true, "Support Mage", "Mimic", "Heal++", 12.0f, 0.20f, 1.15f, 0.75f, 880.0f, 880.0f, 700.0f, 700.0f);

	//Ennemies possibles
	Character ennemy1(&Person("Mysterious", "Character", 30, 22.0f), true, false, false, "Mage", "Lure of profits", "", 17.0f, 0.20f, 1.25f, 0.75f, 850.0f, 850.0f, 100.0f, 100.0f);
	Character ennemy2(&Person("Mimic", "Mimico", 800, 5.0f), true, false, true, "Chest", "Fire", "Wood Resistance", 22.0f, 0.15f, 1.90f, 0.60f, 1000.0f, 1000.0f, 100.0f, 100.0f);

	//Init StarterPack
	vector<Character*> starterPack;
	starterPack.push_back(&c1);
	starterPack.push_back(&c2);
	starterPack.push_back(&c3);
	starterPack.push_back(&c4);
	
	//Spells dispos
	SpellHeal s1("Soin fort", 100.0f, 200.0f);
	SpellHeal s2("Soin faible", 20.0f, 20.0f);
	Potion po1("Speed Potion", 2, false, 0, false, 0, true, 2);
	Potion po2("Health Potion", 1, false, 0, true, 5, false, 0);
	Potion po3("Strength Potion", 3, true, 2, false, 0, false, 0);
	//SpellBoost sb1("Initiative", 0.3f, 1.25);

	Inventory groupInv;
	Item groupItem;
	groupInv.setItemTab(&groupItem); //bind les Item à l'inv de group

	string answer = "";
	vector<Character> temp;
	vector<Character*> group;
	vector<Character*> ennemies;

	int intInput;

	//Intro
	cout << "Welcome, young adventurer, to TextAdventure!" << endl;
	cout << "You are going to start a whole new adventure.\nWould you like to create a character[1] or use an already created character[2] :" << endl;
	intInput = RangeIntInput(1, 2);

	if (intInput == 1) {
		cout << "How many character do you want to create (1 min - 4 max) :" << endl;;
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
				group[i]->setActualWeapon(&w7);
				group[i]->spells.push_back(&s1);
				group[i]->spells.push_back(&s2);
				continue;
			}
			else if (group[i]->getClassName() == "Paladin") {
				//groupInv.addWeapon(&w4);
				group[i]->spells.push_back(&s2);
				group[i]->setActualWeapon(&w6);
				continue;
			}
			else if (group[i]->getClassName() == "Warrior") {
				//groupInv.addWeapon(&w2);
				group[i]->setActualWeapon(&w5);
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
	/*BETA TEST DE LA VERSION QUI TUE DE OUF EN DEVELOPPEMENT*/
	if (intInput == 2) {
		cout << "\nHow many character do you want to play (1 min - 4 max) :\n";
		intInput = RangeIntInput(1, 4);

		groupInv.setInvSize(starterPack.size() * 4); //set inv size (only for the weapons)
		for (int i = 0; i < starterPack.size(); i++) {
			if (starterPack[i]->getClassName() == "Range Mage") {
				groupInv.addWeapon(&w1);
				starterPack[i]->setActualWeapon(&w1);
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
			else if (starterPack[i]->getClassName() == "Support Mage") {
				groupInv.addWeapon(&w3);
				starterPack[i]->setActualWeapon(&w3);
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

		//A voir pourquoi pas set bon indice
		for (int i = 0; i < intInput; i++) {
			cout << "------------------------------------------------" << endl;
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
	system("cls");

	//Histoire bateau, juste pour plein de tests --> BETA

	if (group.size() > 1) {
		cout << "Your story begin as you and your team wake up in an unknown forest, no one of you know what happened..." << endl;
	}
	else {
		cout << "Your story begin as you wake alone in an unknown forest, you don't know what happened..." << endl;
	}

	cout << "You look around you and see two trails going to opposite directions..." << endl;
	cout << "Which path would you want to take ? [Left] | [Right]" << endl;
	answer = rangeStringInput("LEFT", "RIGHT");

	if (answer == "LEFT") {
		cout << "After a morning of walking, you see a stranger with a dark hood near a sign with erased indications. He makes discreet signs asking you to join him." << endl;
		cout << "Would you want to approach the mysterious stranger ? [Yes] | [No]" << endl;
		answer = rangeStringInput("YES", "NO");

		if (answer == "YES") {
			cout << "[Mysterious stranger] - You seem lost, can I offer my help to guide you on a safer path? ?" << endl;
			cout << "It looks suspicious but you have no idea where you are, would it be a good idea to ask for help ?" << endl;
			cout << "Would you want to listen the mysterious stranger ? [Yes] | [No]" << endl;
			answer = rangeStringInput("YES", "NO");

			if (answer == "NO") {
				cout << "You continue walking indefinitely until you find an exit.... Which you will never find." << endl;
				system("pause");
				main();
			}
			if (answer == "YES") {
				cout << "[Mysterious stranger] - Greaaaat, I see that you have beautiful potions, let me take one and I will guide you." << endl;
				cout << "These potions can be useful but are they really necessary ?" << endl;
				cout << "Let him take a potion ? [Yes] | [No]" << endl;
				answer = rangeStringInput("YES", "NO");

				if (answer == "NO") {
					if (group.size() > 2) {
						cout << "[Mysterious stranger] - Well you'll find the exit by yourself I guess...." << endl;
						cout << "You continue walking indefinitely until you find an exit.... Which you will never find." << endl;
						system("pause");
						main();
					}
					else {
						cout << "[Mysterious stranger] - I didn't want it to come to this, but times are rough, bro." << endl;
						cout << "You go into battle against the mysterious stranger." << endl;
						system("pause");
						ennemy1.setActualWeapon(&w9);
						ennemies.push_back(&ennemy1);
						if (!b1.inBattle(group, ennemies, groupInv)) {
							main();
						}
						else {
							cout << "You have defeated the mysterious stranger but you have no indication to find the way out...." << endl;
							cout << "You continue walking indefinitely until you find an exit.... Which you will never find." << endl;
							system("pause");
							main();
						}
					}
				}

				if (answer == "YES") {
					groupInv.getItemTab()->getPotionTab().pop_back();
					cout << "[Mysterious stranger] - Thank you." << endl;
					cout << "The mysterious stranger drops a flash bang and dissapear" << endl;
					cout << "[" << group[0]->getFirstName() << " " << group[0]->getLastName() << "] - Hey ! Shoot, I shouldn't have trusted this guy !" << endl;
					cout << "You continue walking indefinitely until you find an exit.... Which you will never find." << endl;
					system("pause");
					main();
				}
			}

		}
		if (answer == "NO") {
			cout << "You continue walking indefinitely until you find an exit.... Which you will never find." << endl;
			system("pause");
			main();
		}

	}
	if (answer == "RIGHT") {
		cout << "At the end of the trail, you find yourself in front of a cave." << endl;
		cout << "Would you like to enter the cave ? [Yes] | [No]" << endl;
		answer = rangeStringInput("YES", "NO");

		if (answer == "YES") {
			cout << "On a pedestal, you see a chest." << endl;
			cout << "Do you want to open the chest ? [Yes] | [No]" << endl;
			answer = rangeStringInput("YES", "NO");

			if (answer == "YES") {
				cout << "While you are opening the chest, you realize that it is not a real safe but a Mimic !" << endl;
				ennemy2.setActualWeapon(&w8);
				ennemies.push_back(&ennemy2);
				if (!b1.inBattle(group, ennemies, groupInv)) {
					main();
				}
				else {
					cout << "You have defeated the mimic, you find 1 potion of speed." << endl;
					groupInv.getItemTab()->addPotion(&po1);
					cout << "You turn around and come out of the cave and continue your adventure." << endl;
					system("pause");
					main();
				}
			}
			if (answer == "NO") {
				cout << "You herd in the dark cave for long hours, but don't find your way back...." << endl;
				system("pause");
				main();
			}

		}
		if (answer == "NO") {
			cout << "You continue walking indefinitely until you find an exit.... Which you will never find." << endl;
			system("pause");
			main();
		}
	}


	return 0;
}

