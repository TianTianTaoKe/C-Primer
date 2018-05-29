#include "Screen.h"

Screen::~Screen()
{

}
Screen  Screen::Move(pos y, pos x)
{
	cursor = y * width + x;
	return *this;
}

Screen Screen::Set(char ch)
{
	contents[cursor] = ch;
	return *this;
}

Screen Screen::Display(std::ostream& os)
{
	os << contents;
	return *this;
}