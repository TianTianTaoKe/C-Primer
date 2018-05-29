#include <iostream>
#include <string>
#include <vector>
#include "Chapter6.h"
#include "Chapter8.h"
#include "Chapter9.h"
#include "Sales_data.h"
#include "Screen.h"
#include <fstream>
#include <sstream>
#include <math.h>

#define NDEBUG
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;

typedef vector<string> vecstr;

std::istream& f(std::istream& in)
{
	string v;
	while (in >> v)
	{
		if (in.bad())
		{
			throw std:: runtime_error("IO流错误");
		}
		if (in.fail())
		{
			std::cerr << "数据错误，请重试：" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	in.clear();
	return in;
}




//const int  buf;
int cnt = 0;
const int  sz = cnt;

int main(int argc, char * argv[])
{
	unsigned char a = 1;
	unsigned char b = 2;
	const int i = 1;
	int arr[i] = { 0 };
	int score = a - b;
	cout << score << endl;
	system("pause");
	print();
}

