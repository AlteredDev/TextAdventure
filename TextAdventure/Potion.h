#ifndef POTION_H
#define POTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Potion
{
private:
	string name;
	int timeTurn;
	bool isDamageBoost;
	float damageBoost;
	bool isHeal;
	float heal;
	bool isSpeed;
	float speed;

public:
	Potion();
	Potion(string n, int tt, bool idb, float db, bool ih, float h, bool is, float s);

	string getName();
	int getTimeTurn();
	bool getIsDamageBoost();
	float getDamageBoost();
	bool getIsHeal();
	float getHeal();
	bool getIsSpeed();
	float getSpeed();
};

#endif // !POTION_H