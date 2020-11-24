#include "Person.h"

Person::Person():firstName("Jean"),lastName("Jinx"),age(0),initiative(0)
{
}

Person::Person(string fName, string lName):firstName(fName),lastName(lName)
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
