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

bool Battle::inBattle(vector<Character *> allie, vector<Character *> ennemie)
{
	vector<Character *> battleCharactersTab;
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
			cout << "---------------------------------------------------------------------------------\n\n";
			cout << battleCharactersTab[i]->getFirstName() << " " << battleCharactersTab[i]->getLastName() << "with :" << battleCharactersTab[i]->getInitiative() << " is playing." << endl;

			if (battleCharactersTab[i] != nullptr) {

				//boucler a partir d'ici (faire une autre fonction recursive jusqu'a que allie.dead ou ennemie.dead
				if (battleCharactersTab[i]->getIsPNJ()) {
					for (Character* c : battleCharactersTab) {
						if (!c->getIsPNJ()) {
							battleCharactersTab[i]->attack(*c);
						}
					}
				}
				else {
					cout << "What do you want to do :" << endl;
					cout << "[1] Attack" << endl;
					cout << "[2] Defend" << endl;
					cout << "[3] Cast a spell" << endl;
					cout << "[4] Show your inventory" << endl;
				}
				int intInput = rangeIntInput(1, 4);

				switch (intInput) {
				case 1:
					cout << "\nWho would you want to attack :\n\n";
					//je pense faut rajouter un ID pour la selection du perso a attaquer
					for (int a = 0; a < ennemie.size(); a++) {
						cout << ennemie[a]->getFirstName() << " " << ennemie[a]->getLastName() << " (" << a << ")" << endl;
					}
					intInput = rangeIntInput(0, ennemie.size());
					battleCharactersTab[i]->attack(*ennemie[intInput]);
					break;

				case 2:
					battleCharactersTab[i]->defend();
					break;

				case 3:
					if (battleCharactersTab[i]->spells[0] == nullptr) {
						cout << battleCharactersTab[i]->getFirstName() << " " << battleCharactersTab[i]->getLastName() << "\n do not have any spells...\n";
						system("pause"); break;
					}
					else {
						cout << "\nWhat spell do you want to cast :\n\n";
						for (int a = 0; a < battleCharactersTab[i]->spells.size(); a++) {
							cout << battleCharactersTab[i]->spells[a]->getNameSpell() << " (" << a << ")\n";
						}
						int spellSelect = rangeIntInput(0, battleCharactersTab[i]->spells.size());

						cout << "\nSelect the aimed character :\n\n";
						for (int a = 0; a < battleCharactersTab.size(); a++) {
							cout << battleCharactersTab[a]->getFirstName() << " " << battleCharactersTab[a]->getLastName() << " (" << a << ")\n";
						}
						int charSelect = rangeIntInput(0, battleCharactersTab.size());

						battleCharactersTab[i]->spells[spellSelect]->castSpell(battleCharactersTab[charSelect]);
					}
				case 4:

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
						verifyAllie++;
						if (verifyAllie == nbrAllie) { break; }
					}
				}
				if (victoryAllie) { return true; }

				int verifyEnnemie = 0;
				bool victoryEnnemie = false;
				for (Character* c : ennemie) {
					if (c->getIsDead()) {
						verifyEnnemie++;
						if (verifyEnnemie == nbrEnnemie) { break; }
					}
				}
				if (victoryEnnemie) { return false; }
			}
		}
	}
}
