#pragma once
#include <iostream>
#include <string>

using namespace std;

class Location
{
private:
	int idLocation;

	string nameLocation;
	string descriptionLocation;

	bool hasEffectLocation;
	string effectLocation;

public:
	Location();
	Location(int vID, string vNameLoc, string vDescLoc, bool vHasEffectLoc, string vEffectLoc);

	//Getter/Setter
	int getIDLocation();
	void setIDLocation(int vID);

	string getNameLocation();
	void setNameLocation(string vNameLoc);

	string getDescLocation();
	void setDescLocation(string vDescLoc);

	bool getHasEffectLocation();
	void setHasEffectLocation(bool vHasEffectLoc);

	string getEffectLocation();
	void setEffectLocation(string vEffectLoc);

};

