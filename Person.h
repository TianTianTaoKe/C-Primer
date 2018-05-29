#pragma once
#include <string>
#include <iostream>

using std::string;
class Person
{
public:
	Person() = default;
	Person(const string &name, const string &add) :strName(name), strAddr(add){}
	~Person();
	string GetName() const { return strName; }
	string GetAddr() const { return strAddr; }
private:
	string strName;
	string strAddr;
	friend std::istream& readPerson(std::istream &, Person &);
	friend std::ostream& printPerson(std::ostream &, const Person &);
};

std::istream& readPerson(std::istream &, Person &);
std::ostream& printPerson(std::ostream &, const Person &);

