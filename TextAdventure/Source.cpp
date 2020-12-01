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
		cout << "Votre histoire débute alors que votre équipe et vous même vous réveillez dans une fôret inconnue, aucun de vous n'avez de souvenir de ce qui s'est passé..." << endl;
	}
	else {
		cout << "Votre histoire débute alors que vous vous réveillez seul dans une fôret inconnue, vous n'avez de souvenir de ce qui s'est passé..." << endl;
	}

	cout << "Vous regardez autour de vous et appercevez deux sentiers allant chacun à l'opposé..." << endl;
	cout << "Quel chemin souhaitez vous emprunter ? [Left] | [Right]" << endl;
	answer = rangeStringInput("LEFT", "RIGHT");

	if (answer == "LEFT") {
		cout << "Après une matinée de marche, vous appercevez un inconnu à la capuche sombre près d'un panneau aux indications effacés, celui-ci vous fait des signes discrets vous demandant de le rejoindre." << endl;
		cout << "Souhaitez vous rejoindre le mystérieux personnage ? [Oui] | [Non]" << endl;
		answer = rangeStringInput("OUI", "NON");

		if (answer == "OUI") {
			cout << "[Mystérieux personnage] - Vous semblez perdu, puis-je vous proposer mon aide afin de vous guider vers un chemin plus sûr ?" << endl;
			cout << "Son allure semble suspecte mais vous n'avez aucune idée de l'endroit où vous vous trouvez, serait-ce une bonne idée de demander de l'aide ?" << endl;
			cout << "Souhaitez vous écouter ce mystérieux personnage ? [Oui] | [Non]" << endl;
			answer = rangeStringInput("OUI", "NON");

			if (answer == "NON") {
				cout << "Vous continuez de marcher indéfiniement jusqu'à trouver une sortie.... Que vous ne trouverez jamais." << endl;
				system("pause");
				main();
			}
			if (answer == "OUI") {
				cout << "[Mystérieux personnage] - Biennnnn, je vois que vous avez de belles potions, laissez moi en prendre une et je vous guiderez" << endl;
				cout << "Ces potions peuvent être utile mais sont-elles vraiment nécessaires ?" << endl;
				cout << "Laisser prendre une potion ? [Oui] | [Non]" << endl;
				answer = rangeStringInput("OUI", "NON");

				if (answer == "NON") {
					if (group.size() > 2) {
						cout << "[Mystérieux personnage] - Et bien vous trouverez la sortie par vous même je suppose...." << endl;
						cout << "Vous continuez de marcher indéfiniement jusqu'à trouver une sortie.... Que vous ne trouverez jamais." << endl;
						system("pause");
						main();
					}
					else {
						cout << "[Mystérieux personnage] - Je ne voulais pas en arriver là mais les temps sont durs frere" << endl;
						cout << "Vous rentrez en combat contre le mystérieux personnage" << endl;
						ennemy1.setActualWeapon(&w9);
						ennemies.push_back(&ennemy1);
						if (!b1.inBattle(group, ennemies, groupInv)) {
							main();
						}
						else {
							cout << "Vous avez vaincu le mystérieux personnage mais vous restez sans indication pour trouver la sortie..." << endl;
							cout << "Vous continuez de marcher indéfiniement jusqu'à trouver une sortie.... Que vous ne trouverez jamais." << endl;
							system("pause");
							main();
						}
					}
				}

				if (answer == "OUI") {
					groupInv.getItemTab()->getPotionTab().pop_back();
					cout << "[Mystérieux personnage] - Merci." << endl;
					cout << "Le mstérieux personnage lance une potion par terre et disparaît" << endl;
					cout << "[" << group[0]->getFirstName() << " " << group[0]->getLastName() << "] - Hey ! Et mince, je n'aurais pas du faire confiance à cette personne !" << endl;
					cout << "Vous continuez de marcher indéfiniement jusqu'à trouver une sortie.... Que vous ne trouverez jamais." << endl;
					system("pause");
					main();
				}
			}

		}
		if (answer == "NON") {
			cout << "Vous continuez de marcher indéfiniement jusqu'à trouver une sortie.... Que vous ne trouverez jamais." << endl;
			system("pause");
			main();
		}

	}
	if (answer == "RIGHT") {
		cout << "A la fin du sentier, vous vous retrouvez devant une caverne." << endl;
		cout << "Souhaitez vous entrer dans la caverne ? [Oui] | [Non]" << endl;
		answer = rangeStringInput("OUI", "NON");

		if (answer == "OUI") {
			cout << "Sur un pied d'estale, vous voyez un coffre." << endl;
			cout << "Souhaitez vous ouvrir le coffre ? [Oui] | [Non]" << endl;
			answer = rangeStringInput("OUI", "NON");

			if (answer == "OUI") {
				cout << "Alors que vous êtes en train d'ouvrir le coffre, vous vous appercevez que ce n'est pas un vrai coffre mais un Mimique !" << endl;
				ennemy2.setActualWeapon(&w8);
				ennemies.push_back(&ennemy2);
				if (!b1.inBattle(group, ennemies, groupInv)) {
					main();
				}
				else {
					cout << "Vous avez vaincu le mimique, vous trouvez 1 potion de speed" << endl;
					groupInv.getItemTab()->addPotion(&po1);
					cout << "Vous vous retournez et resortez de la caverne et continuez votre aventure" << endl;
					system("pause");
					main();
				}
			}
			if (answer == "NON") {
				cout << "Vous herrez dans la caverne sombre pendant de longues heures, mais ne retrouvez pas votre chemin..." << endl;
				system("pause");
				main();
			}

		}
		if (answer == "NON") {
			cout << "Vous continuez de marcher indéfiniement jusqu'à trouver une sortie.... Que vous ne trouverez jamais." << endl;
			system("pause");
			main();
		}
	}


	return 0;
}

