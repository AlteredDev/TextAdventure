#pragma once
#include <iostream>
#include <string>

using namespace std;

class Spell
{
private:
	//int id;
	//Rudhy tu fera pour me montrer
	string nameSpell;
	float manaCost;
	//float damage;

public:
	Spell();
	Spell(string n);

	//void castSpell(Character &c);

	string getName();
	void setName(string nSpell);

	float getManaCost();
	void getManaCost(float mCost);
};

