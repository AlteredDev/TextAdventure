#ifndef CHARACTER_H
#define CHARACTER_H

#include "Person.h"
#include "SpellHeal.h"
#include "SpellBoost.h"
#include "SpellMagicBall.h"
#include "Inventory.h"
#include "Location.h"

class Character : public Person
{
public:
	bool PNJ;
	bool isDead = false;
	bool isDefending = false;
	string className;
	string weakness;
	string statusEffect;
	float strength;
	float criticPerc;
	float criticPercMultiplier;
	float hitPerc;

	float hp;
	float hpMax;

	float mana;
	float manaMax;

	Inventory* invChar;
	Weapon* actualWeapon = nullptr;
	//Spell spells[3];

	vector<Spell *> spells;
	Potion actualPotion;

public:
	Character();
	Character(Person *p, bool vPNJ, bool vIsDead, bool vIsDefending, string vClassName, string vWeakness, string vStatusEffect, float vStrength, float vCriticPerc, float vCriticPercMultiplier, float vHitPerc, float vHP, float vHPMax, float vMana, float vManaMax);

	//Setter/Getter
	string getClassName();
	void setClassName(string vClassName);

	string getWeakness();
	void setWeakness(string vWeakness);

	string getStatusEffect();
	void setStatusEffect(string vStatusEffect);

	float getStrength();
	void setStrength(float vStrength);

	float getCriticPerc();
	void setCriticPerc(float vCritPerc);

	float getCriticPercMultiplier();
	void setCriticPercMultiplier(float vCritPercMultiplier);

	float getHP();
	void setHP(float vHP);

	float getHPMax();
	void setHPMax(float vHPMax);

	float getMana();
	void setMana(float vMana);

	float getManaMax();
	void setManaMax(float vManaMax);

	float getHitPerc();
	void setHitPerc(float vHitPerc);

	bool getIsDead();
	void setIsDead(bool dead);

	bool getIsPNJ();
	void setIsPNJ(bool vPNJ);

	bool getIsDefending();
	void setIsDefending(bool vIsDefending);

	Inventory getInvChar();
	void setInvChar(Inventory *vInvChar);

	void setActualWeapon(Weapon *newWeapon);
	Weapon* getActualWeapon();

	bool operator < (Character character) {
		return (getInitiative() < character.getInitiative());
	}


	//equipe l'arme de l'inventaire
	void equipWeapon(Inventory* Inv);
	//utilise un item de l'inventaire
	void useItem(Inventory* Inv);
	//V�rif si a use potion, si oui donne les effet le temps d'effet de la popo
	void verifyPotion();
	//changer la Location (applique des effets au personnage)
	void changeLocation(Location l);
	//creation du character (+ class etc...)
	void createCharacter();
	//attaquer un ennemi --> attackFailed/AttackSucced
	void attack(Character *c);
	//se d�fendre (ssi Weapon.defense > 0)
	void defend();
	//montrer l'inventaire actuel du personnage
	void showInfo();
	//mourrir de la mort qui tue
	void die();
	//cast un spell + verifs
	bool verifyManaForSpell(Spell *s);
};

#endif // !CHARACTER_H