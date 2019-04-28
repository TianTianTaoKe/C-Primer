#include "stdafx.h"

#include "X.h"

int Employee::sn = 0;

HasPtr::~HasPtr()
{
	delete ps;
}

inline
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	string *newps = new string(*rhs.ps);
	delete ps;
	ps = newps;
	i = rhs.i;
	return *this;
}

HasPtr& HasPtr::operator=(const string& rhs)
{
	*ps = rhs;
	return  *this;
}

string& HasPtr::operator*()
{
	return *ps;
}