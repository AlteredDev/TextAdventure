#include "Battle.h"

int rangeIntInput(int min, int max) {
	int input; cin >> input;
	while (cin.fail() || input < min || input > max) {
		cin.clear(); cin.ignore();
		cout << "\nEnter en valid number :\n";
		cin >> input;
	}
	return input;
}

//Faire une methode inBattle() qui se boucle tant que des gens sont pas morts sinon ca va etre insanement long

bool Battle::inBattle(vector<Character*> allie, vector<Character*> ennemie, Inventory inv)
{
	vector<Character*> battleCharactersTab;
	int nbrAllie = 0;
	int nbrEnnemie = 0;

	//insterting allies
	for (int i = 0; i < allie.size(); i++) {
		battleCharactersTab.push_back(allie[i]);
		nbrAllie++;
	}
	//inserting ennemies
	for (int i = 0; i < ennemie.size(); i++) {
		battleCharactersTab.push_back(ennemie[i]);
		nbrEnnemie++;
	}

	while (1) {
		sort(battleCharactersTab.begin(), battleCharactersTab.end());

		for (int i = 0; i < battleCharactersTab.size(); i++) {
			system("cls");
			cout << "---------------------------------------------------------------------------------\n";

			if (battleCharactersTab[i] != nullptr) {
				battleCharactersTab[i]->verifyPotion();

				cout << "It is " << battleCharactersTab[i]->getFirstName() << " " << battleCharactersTab[i]->getLastName() << "'s turn\tHP = " << battleCharactersTab[i]->getHP() << "/" << battleCharactersTab[i]->getHPMax() << endl;
				cout << "\t\tMana = " << battleCharactersTab[i]->getMana() << "/" << battleCharactersTab[i]->getManaMax() << endl;
				//boucler a partir d'ici (faire une autre fonction recursive jusqu'a que allie.dead ou ennemie.dead
				if (battleCharactersTab[i]->getIsPNJ()) {
					for (int a = 0; a < allie.size(); a++) {
						if (allie[a] == nullptr) { continue; }
						battleCharactersTab[i]->attack(allie[a]);
						cout << endl;
						break;
					}
					system("pause");
				}
				else {
					bool hadAction = false;
					while (!hadAction) {
						cout << "\n\n\nWhat do you want to do :\n\n[1] Attack\n[2] Defend\n[3] Cast a spell\n[4] Show your inventory\n\n---------------------------------------------------------------------------------\n";

						int intInput = rangeIntInput(1, 4);

						switch (intInput) {
						case 1:
							cout << "\nWho would you want to attack :\n\n";
							//je pense faut rajouter un ID pour la selection du perso a attaquer
							for (int a = 0; a < ennemie.size(); a++) {
								cout << ennemie[a]->getFirstName() << " " << ennemie[a]->getLastName() << " [" << a << "]" << endl;
							}
							intInput = rangeIntInput(0, ennemie.size());
							battleCharactersTab[i]->attack(ennemie[intInput]);
							hadAction = true;
							break;

						case 2:
							battleCharactersTab[i]->defend();
							hadAction = true;
							break;

						case 3:
							if (battleCharactersTab[i]->spells[0] == nullptr) {
								cout << battleCharactersTab[i]->getFirstName() << " " << battleCharactersTab[i]->getLastName() << "\n do not have any spells...\n";
								system("pause"); system("cls");
							}
							else {
								cout << "\nWhat spell do you want to cast :\n\n";
								for (int a = 0; a < battleCharactersTab[i]->spells.size(); a++) {
									cout << battleCharactersTab[i]->spells[a]->getNameSpell() << " [" << a << "]\n";
								}
								int spellSelect = rangeIntInput(0, battleCharactersTab[i]->spells.size());

								if (!battleCharactersTab[i]->verifyManaForSpell(battleCharactersTab[i]->spells[spellSelect])) {
									break;
								}

								cout << "\nSelect the aimed character :\n\n";
								for (int a = 0; a < battleCharactersTab.size(); a++) {
									cout << battleCharactersTab[a]->getFirstName() << " " << battleCharactersTab[a]->getLastName() << " [" << a << "]\n";
								}
								int charSelect = rangeIntInput(0, battleCharactersTab.size());


								cout << battleCharactersTab[charSelect]->getMana() << "/" << battleCharactersTab[charSelect]->getManaMax() << endl;
								system("pause");

								battleCharactersTab[i]->spells[spellSelect]->castSpell(battleCharactersTab[charSelect]);
								hadAction = true;
							}
							break;

						case 4:
							system("cls");
							bool haveWeapon = false;
							bool haveItem = false;

							cout << "\nWeapon :\n\n";
							for (int i = 0; i < inv.getWeaponTab().size(); i++) {
								if (inv.getWeaponTab()[i] == nullptr) { break; }
								else {
									cout << "\t" << inv.getWeaponTab()[i]->GetName() << endl;
									haveWeapon = true;
								}
							}

							cout << "\n\nItems :\n\n";
							for (int i = 0; i < inv.getItemTab()->getPotionTab().size(); i++) {
								if (inv.getItemTab()->getPotionTab()[i] == nullptr) { continue; }
								else {
									cout << "\t" << inv.getItemTab()->getPotionTab()[i]->getName() << endl;
									haveItem = true;
								}
							}

							cout << "\n\nEquipment :\n\n";
							if (battleCharactersTab[i]->getActualWeapon() != nullptr) {
								cout << "\t" << battleCharactersTab[i]->getFirstName() << " " << battleCharactersTab[i]->getLastName() << " is equipped with a " << battleCharactersTab[i]->getActualWeapon()->GetName() << endl;
							}
							else {
								cout << "\t" << battleCharactersTab[i]->getFirstName() << " " << battleCharactersTab[i]->getLastName() << " is unequipped" << endl;
							}

							cout << "\n\n---------------------------------------------------------------------------------\n[1] Equip weapon\n[2] Use Item\n[3] Back\n";
							intInput = rangeIntInput(1, 3);
							switch (intInput)
							{
							case 1:
								if (haveWeapon) {
									battleCharactersTab[i]->equipWeapon(&inv);
									hadAction = true;
								}
								else { cout << battleCharactersTab[i]->getFirstName() << " " << battleCharactersTab[i]->getLastName() << " doesn't have any weapon\n"; }
								break;
							case 2:
								if (haveItem) {
									battleCharactersTab[i]->useItem(&inv);
									hadAction = true;
								}
								else { cout << battleCharactersTab[i]->getFirstName() << " " << battleCharactersTab[i]->getLastName() << " doesn't have any item\n"; }
								break;
							case 3:
								break;
							}
							system("pause"); system("cls");
							break;
						}
					}
				}


				for (int a = 0; a < battleCharactersTab.size(); a++) {
					if (battleCharactersTab[a]->getIsDead()) {
						battleCharactersTab[a] = nullptr;
					}
				}

				int verifyAllie = 0;
				bool victoryAllie = false;
				for (Character* c : allie) {
					if (c->getIsDead()) {
						cout << endl << c->getFirstName() << " " << c->getLastName() << " is dead";
						verifyAllie++;
						if (verifyAllie == nbrAllie) { break; }
					}
				}
				if (victoryAllie) { return true; }

				int verifyEnnemie = 0;
				bool victoryEnnemie = false;
				for (Character* c : ennemie) {
					if (c->getIsDead()) {
						cout << endl << c->getFirstName() << " " << c->getLastName() << " is dead";
						verifyEnnemie++;
						if (verifyEnnemie == nbrEnnemie) { break; }
					}
				}
				if (victoryEnnemie) { return false; }
			}
		}
	}
}
