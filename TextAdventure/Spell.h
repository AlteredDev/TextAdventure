#ifndef SPELL_H
#define SPELL_H

#include <string>
using namespace std;

class Character;

class Spell
{
public:
	int id;
	string nameSpell;
	float manaCost;

public:
	Spell();
	Spell(string vName, float vManaCost);

	virtual void castSpell(Character* c) = 0;

	//bool verifCastSpell(Character* c);

	int getID();
	void setID(int vID);

	string getNameSpell();
	void setNameSpell(string nSpell);

	float getManaCostSpell();
	void getManaCostSpell(float mCost);
};

#endif // !SPELL_H
