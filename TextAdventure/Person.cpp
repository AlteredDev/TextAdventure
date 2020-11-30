#include "Person.h"

Person::Person():firstName(""),lastName(""),age(0),initiative(0)
{
}

Person::Person(string fName, string lName, int vAge, float vIni):firstName(fName),lastName(lName),age(vAge),initiative(vIni)
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
