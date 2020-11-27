#include "Potion.h"

Potion::Potion():name(""), timeTurn(0), isDamageBoost(false), damageBoost(0), isHeal(false), heal(0), isSpeed(false), speed(0)
{
}

Potion::Potion(string n, int tt, bool idb, float db, bool ih, float h, bool is, float s) : name(n), timeTurn(tt), isDamageBoost(idb), damageBoost(db), isHeal(ih), heal(h), isSpeed(is), speed(s)
{
}

string Potion::getName()
{
	return name;
}

int Potion::getTimeTurn()
{
	return timeTurn;
}

bool Potion::getIsDamageBoost()
{
	return isDamageBoost;
}

float Potion::getDamageBoost()
{
	return damageBoost;
}

bool Potion::getIsHeal()
{
	return isHeal;
}

float Potion::getHeal()
{
	return heal;
}

bool Potion::getIsSpeed()
{
	return isHeal;
}

float Potion::getSpeed()
{
	return speed;
}
