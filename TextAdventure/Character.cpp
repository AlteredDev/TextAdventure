#include "Character.h"

Character::Character()
{
	cout << "Constructeur Personnage" << endl;
	name = "";
	className = "";
	hp = 0;
	strength = 0;
	mana = 0;
	for (int i = 0; i < 4; i++) {
		inventory[i].SetName("");
	}
	criticPerc = 0;
	for (int i = 0; i < 3; i++) {
		spells[i];
	}
	float speed = 0;
}

void Character::CreateCharacter()
{
	system("cls");
	cout << "Nouveau perso\n\nEntrer votre nom :";
	cin.clear();  cin >> name;
	
	int numClass;
	cout << "\n\nVous avez le choix entre plusieurs classes,\nMage(1), Paladin(2) ou Warrior(3)\nVeuiller rentrer le chiffre correspondant à la classe que vous choisirez :\n\n";
	cin.clear();  cin >> numClass;
	while (cin.fail() || numClass < 1 || numClass > 3) {
		cout << "Veuillez rentrer un chiffre valide :";
		cin.clear();  cin >> numClass;
	}
	switch (numClass)
	{
	case 1:
		className = "Mage";

		break;
	case 2:
		className = "Paladin";
		break;
	case 3:
		className = "Warrior";
		break;
	}


	cout << "\n\nVous serez donc un " << className;


}
