#pragma once
//mettre tous les include car + haute class
#include <iostream>
#include <string>

using namespace std;

/*
- nom, prenom , age, initiative, histoire, race
( get/set
*/
class Person
{
protected:
	string firstName;
	string lastName;

	int age;
	int initiative;
	//a mettre une classe si on a + idée pour Race
	//string race;

public:
	Person();

	string getFirstName();
	void setFirstName(string fName);

	//getter/setter

};

