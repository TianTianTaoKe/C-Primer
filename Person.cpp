#include "Person.h"




Person::~Person()
{
}

std::istream & readPerson(std::istream & is, Person & person)
{
	is >> person.strName >> person.strAddr;
	return is;
}

std::ostream & printPerson(std::ostream & os, const Person &person)
{
	os << person.GetName() << " " << person.GetAddr();
	return os;
}