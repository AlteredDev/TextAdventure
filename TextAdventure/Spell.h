#pragma once
#include <iostream>
#include <string>

using namespace std;

class Spell // faire des enfants --> je vois pas comment arriver a utiliser enfants sans
{
protected:
	int id;
	string nameSpell;
	float manaCost;
	//float damage; // degueu
	//float healAmount; // degueu

public:
	Spell();
	Spell(int vID, string vName);

	virtual float getSpellEffect();

	int getID();
	void setID(int vID);

	string getNameSpell();
	void setNameSpell(string nSpell);

	float getManaCostSpell();
	void getManaCostSpell(float mCost);
};

