#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>


using std::vector;
using std::istringstream;
using std::ostringstream;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;
typedef vector<string> vecstr;


//8.13
struct PersonInfo
{
	string name;
	vecstr phones;
};
inline string format(const string &s){ return s; }
inline bool valid(const string &s){ return true; }

int Exercise8_13(int argc, char *argv[]);
