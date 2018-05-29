#pragma once
#include <string>
#include <iostream>
#include <vector>
using std::string;

class WindowMgr
{
public:
	void Clear(int);
};

class Screen
{
public:
	friend void WindowMgr::Clear(int);
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos pw, pos ph) :width(pw), heigth(ph), contents(ph*pw, ' '){}
	Screen(pos pw, pos ph,char ch) :width(pw), heigth(ph), contents(ph*pw, ch){}
	Screen Move(pos x, pos y);
	Screen Set(char ch);
	Screen Display(std::ostream& os);
	~Screen();
private:
	void DoDisplay(std::ostream& os);
	pos width = 0;
	pos heigth = 0;
	pos cursor = 0;
	string contents;
};

