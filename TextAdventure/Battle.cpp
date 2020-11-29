#include "Battle.h"

void Battle::startBattle(vector<Character> allie, vector<Character> ennemie)
{
	vector<Character> battleCharactersTab;

	//insterting allies
	for (int i = 0; i < allie.size(); i++) { battleCharactersTab.push_back(allie[i]); }
	//inserting ennemies
	for (int i = 0; i < ennemie.size(); i++) { battleCharactersTab.push_back(ennemie[i]); }

	sort(battleCharactersTab.begin(), battleCharactersTab.end());


	system("cls");
	cout << "---------------------------------------------------------------------------------\n\n";
	for (int i = 0; i < battleCharactersTab.size(); i++) {
		cout << battleCharactersTab[i].getInitiative() << endl;
	}

}
