#include "Person.h"

Person::Person():firstName("Jean"),lastName("Jinx"),age(0),initiative(0)
{
}

Person::Person(string fName, string lName, float ini):firstName(fName),lastName(lName),initiative(ini)
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

string Person::getLastName()
{
	return lastName;
}

void Person::setLastName(string lName)
{
	lastName = lName;
}

int Person::getAge()
{
	return age;;
}

void Person::setAge(int vAge)
{
	age = vAge;
}

float Person::getInitiative()
{
	return initiative;
}

void Person::setInitiative(float vInitiative)
{
	initiative = vInitiative;
}
