#include "Person.h"

Person::Person():firstName(""),lastName(""),age(0),initiative(0)
{
}

string Person::getFirstName()
{
	return firstName;
}

void Person::setFirstName(string fName)
{
	firstName = fName;
}
