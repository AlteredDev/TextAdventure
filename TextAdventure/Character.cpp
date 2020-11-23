#include "Character.h"

Character::Character()
{
	cout << "Constructeur Personnage" << endl;
	name = "";
	pv = 0;
	strength = 0;
	for (int i = 0; i < 4; i++) {
		inventory[i].name = "";
	}
	criticPerc = 0;
	for (int i = 0; i < 3; i++) {
		spells[i].name = "";
	}
	float speed = 0;
}

void Character::SetCharacter()
{
	cout << "Nouveau perso\n\nEntrer votre nom :";
	cin.clear();  cin >> name;
	for (int i = 0; i < name.size(); i++) {
		toupper(name[i]);
		//if (name[i] < 65 ||)
	}
}
