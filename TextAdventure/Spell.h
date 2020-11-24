#pragma once
#include <iostream>
#include <string>

using namespace std;

class Spell
{
private:
	//int id;
	string nameSpell;
	float manaCost;
	//float damage;

public:
	Spell();
	Spell(string n);

	virtual void castSpell();

	string getNameSpell();
	void setNameSpell(string nSpell);

	float getManaCostSpell();
	void getManaCostSpell(float mCost);
};

