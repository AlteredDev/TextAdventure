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

void Battle::startBattle(vector<Character *> allie, vector<Character *> ennemie)
{
	vector<Character *> battleCharactersTab;

	//insterting allies
	for (int i = 0; i < allie.size(); i++) { battleCharactersTab.push_back(allie[i]); }
	//inserting ennemies
	for (int i = 0; i < ennemie.size(); i++) { battleCharactersTab.push_back(ennemie[i]); }

	sort(battleCharactersTab.begin(), battleCharactersTab.end());

	system("cls");
	cout << "---------------------------------------------------------------------------------\n\n";
	for (int i = 0; i < battleCharactersTab.size(); i++) {
		cout << battleCharactersTab[i]->getFirstName() << " " << battleCharactersTab[i]->getLastName()  << "with :" << battleCharactersTab[i]->getInitiative() << " is playing." << endl;


		//boucler a partir d'ici (faire une autre fonction recursive jusqu'a que allie.dead ou ennemie.dead
		if (battleCharactersTab[i]->getIsPNJ()) {
			for (Character *c : battleCharactersTab) {
				if (!c->getIsPNJ()) {
					battleCharactersTab[i]->attack(*c);
				}
			}
		}
		else {
			cout << "What do you want to do ?" << endl;
			cout << "[1] Attack" << endl;
			cout << "[2] Defend" << endl;
			cout << "[3] Cast a spell" << endl;
			cout << "[4] Show your inventory" << endl;
		}
		int intInput = rangeIntInput(1, 4);

		switch (intInput) {
		case 1:
			cout << "Who would you want to attack ?" << endl;
			//je pense faut rajouter un ID pour la selection du perso a attaquer
			for (Character *c : battleCharactersTab) {
				if (c->getIsPNJ()) {
					cout << c->getFirstName() << " " << c->getLastName()  << endl;
				}
			}
		}

		for (Character *c : battleCharactersTab) {
			if (c->getIsDead()) {
				//il meurt; a changer et enlver du tableau
				cout << "dead" << endl;
			}
		}

	}

}
