#include "Location.h"

Location::Location()
{
}

Location::Location(int vID, string vNameLoc, string vDescLoc, bool vHasEffectLoc, string vEffectLoc):idLocation(vID),nameLocation(vNameLoc),descriptionLocation(vDescLoc),hasEffectLocation(vHasEffectLoc), effectLocation(vEffectLoc)
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

string Location::getEffectLocation()
{
	return effectLocation;
}

void Location::setEffectLocation(string vEffectLoc)
{
	effectLocation = vEffectLoc;
}

bool Location::getHasEffectLocation()
{
	return hasEffectLocation;
}

void Location::setHasEffectLocation(bool vHasEffectLoc)
{
	hasEffectLocation = vHasEffectLoc;
}
