#pragma once

struct X
{
	X(){ cout << "X()" << endl; }
	X(const X&){ cout << "X(const &X)" << endl; }
	X& operator=(const X& rhs) { cout << "X& operator=(const& rhs)" << endl; return *this; }
	~X(){ cout << "~X()" << endl; }
};

class Employee
{
public:
	Employee(){ mysn = sn++; }
	Employee(const string& s) :name(s){ mysn = sn++; }
	Employee(const Employee& rhs) :name(rhs.name){ mysn = sn++; }
	const Employee& operator=(const Employee& rhs){ name = rhs.name; return *this; }
	const string& get_name(){ return name; }
	int get_mysn(){ return mysn; }
protected:
private:
	static int sn;
	string name;
	int mysn;
};

class HasPtr
{
public:
	HasPtr(const string& s = string()):
		ps(new string(s)),i(0){}
	HasPtr(const HasPtr& p) :
		ps(new string(*p.ps)), i(p.i){}
	HasPtr& operator=(const HasPtr&);
	HasPtr& operator=(const string&);
	string & operator*();
	~HasPtr();
protected:
private:
	string * ps;
	int i;
};