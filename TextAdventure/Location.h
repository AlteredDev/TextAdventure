#pragma once
#include "Character.h"

class Location
{
private:
	int idLocation;

	string nameLocation;
	string descriptionLocation;

	bool effectLocation;

public:
	Location();
	Location(int vID, string vNameLoc, string vDescLoc, bool vEffectLoc);

	//Getter/Setter
	int getIDLocation();
	void setIDLocation(int vID);

	string getNameLocation();
	void setNameLocation(string vNameLoc);

	string getDescLocation();
	void setDescLocation(string vDescLoc);

	bool getEffectLocation();
	void setEffectLocation(bool vEffectLoc);

};

