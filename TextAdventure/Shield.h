#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"

using namespace std;

class Shield : public Weapon
{
protected:
	string name = "Bouclier";
};

