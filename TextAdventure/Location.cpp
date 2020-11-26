#include "Location.h"

Location::Location()
{
}

Location::Location(int vID, string vNameLoc, string vDescLoc, bool vEffectLoc):idLocation(vID),nameLocation(vNameLoc),descriptionLocation(vDescLoc),effectLocation(vEffectLoc)
{
}

int Location::getIDLocation()
{
	return idLocation;
}

void Location::setIDLocation(int vID)
{
	idLocation = vID;
}

string Location::getNameLocation()
{
	return nameLocation;
}

void Location::setNameLocation(string vNameLoc)
{
	nameLocation = vNameLoc;
}

string Location::getDescLocation()
{
	return descriptionLocation;
}

void Location::setDescLocation(string vDescLoc)
{
	descriptionLocation = vDescLoc;
}

bool Location::getEffectLocation()
{
	return effectLocation;
}

void Location::setEffectLocation(bool vEffectLoc)
{
	effectLocation = vEffectLoc;
}
