#include "stdafx.h"

#include "Chapter6.h"
#include "Chapter8.h"
#include "Chapter9.h"
#include "Chapter10.h"
#include "Chapter11.h"
#include "Chapter12.h"
#include "Chapter13.h"
#include "Screen.h"


using std::vector;
using std::initializer_list;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::pair;

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

class A
{
public:
	A();
	~A();
	int a;
private:

};

A::A()
{
	a = 10;
}

A::~A()
{
}

class B
{
public:
	A aa;
	int b;
	B();
	B(int v);
	~B();
	B(const B& rhs);
};

B::B()
{
	b = 15;
}
B::B(int v)
{
	b = v;
}
B::~B()
{

}
B::B(const B& rhs)
{
	b = rhs.b;
}


int main(int argc, char * argv[])
{
	Exercise13_47();
	
	system("pause");
}

