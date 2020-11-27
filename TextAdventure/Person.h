#ifndef PERSON_H
#define PERSON_H

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
protected:
	string firstName;
	string lastName;

	int age;
	float initiative;
	//a mettre une classe si on a + idée pour Race
	//string race;

public:
	Person();
	Person(string fName, string lName);

	//getter/setter
	string getFirstName();
	void setFirstName(string fName);

	string getLastName();
	void setLastName(string lName);

	int getAge();
	void setAge(int vAge);

	float getInitiative();
	void setInitiative(float vInitiative);

};

#endif // !PERSON_H