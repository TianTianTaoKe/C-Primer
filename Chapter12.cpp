#include "stdafx.h"

#include "Chapter12.h"
#include "TextQuery.h"


void Exercise12_2()
{
	StrBlob b1;
	{
		StrBlob b2 = { "a", "b", "c" };
		b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;
	
	const StrBlob b3 = b1;
	
	cout << b3.front() << " " << b3.back() << endl;
}

vector<int> * new_vector()
{
	return new (nothrow)vector<int>;
}

void read_ints(vector<int>* pv)
{
	int v;
	while (cin >> v)
	{
		pv->push_back(v);
	}
}

void print_ints(vector<int>* pv)
{
	for (const auto& v : *pv)
	{
		cout << v << " ";
	}
	cout << endl;
}

void Exercise12_6()
{
	vector <int> * pv = new_vector();
	if (!pv)
	{
		cout << "内存不足" << endl;
	}
	read_ints(pv);
	print_ints(pv);
	delete pv;
	pv = nullptr;
}

shared_ptr<vector<int> > new_vectorEX()
{
	return make_shared<vector <int> >();
}

void read_ints(shared_ptr<vector<int> > spv)
{
	int v;
	while (cin >> v)
	{
		spv->push_back(v);
	}
}

void print_ints(shared_ptr<vector<int> > spv)
{
	for (const auto& v : *spv)
	{
		cout << v << " ";
	}
	cout << endl;
}

void Exercise12_7()
{
	shared_ptr<vector <int>> spv = new_vectorEX();
	if (!spv)
	{
		cout << "内存不足" << endl;
	}
	read_ints(spv);
	print_ints(spv);
}

struct destination
{

};

struct connection
{

};

connection connect(destination* pd)
{
	cout << "打开连接" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "关闭连接" << endl;
}

void end_connection(connection* p)
{
	disconnect(*p);
}

void Exercise12_14()
{
	destination d;
	connection c = connect(&d);
	shared_ptr<connection>p(&c, end_connection);
	cout << endl;
}

void Exercise12_15()
{
	destination d;
	connection c = connect(&d);
	shared_ptr<connection>p(&c, [](connection *p){disconnect(*p); });
	cout << endl;
}

void Exercise12_16()
{
	unique_ptr<int> ui(new int(42));
	unique_ptr<int> ui2;
}

void Exercise12_19()
{
	StrBlob b1;
	{
		StrBlob b2 = { "a", "b", "c" };
		b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;

	const StrBlob b3 = b1;

	cout << b3.front() << " " << b3.back() << endl;

	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
	{
		cout << it.deref() << endl;
	}
}

void Exercise12_20()
{
	ifstream ifile("E:\\代码\\C-Primer\\Debug\\123.txt",ifstream::in);
	if (!ifile)
	{
		cout << "文件打开失败" << endl;
	}
	string strLine;
	StrBlob strBlob;
	while (getline(ifile,strLine))
	{
		strBlob.push_back(strLine);
	}

	for (auto it = strBlob.begin(); neq(it, strBlob.end()); it.incr())
	{
		cout << it.deref() << endl;
	}
}

void Exercise12_22()
{
	const StrBlob b1 = { "a", "b", "c" };

	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
	{
		const string& str = it.deref();
		cout << it.deref() << endl;
	}
}

char* addStr(const char* str1, const char* str2)
{
	size_t strlen1 = strlen(str1);
	size_t strlen2 = strlen(str2);
	size_t strlenAll = strlen1 + strlen2 + 1;
	char * newStr = new char[strlenAll]();
	strcpy_s(newStr, strlen1 + 1, str1);
	strcat_s(newStr, strlenAll, str2);
	return newStr;
}

char* addStr(const string& str1, const string& str2)
{
	string newStr = str1 + str2;
	char *newCharArr = new char[newStr.size() + 1];
	strcpy_s(newCharArr, newStr.size() + 1, newStr.c_str());
	return newCharArr;
}

void Exercise12_23()
{
	char* str1 =  addStr("123", "456");
	char* str2 = addStr(string("123"), string("456"));
	cout << str2 << endl;
}

void Exercise12_24()
{
	char c;
	char *r = new char[20]();
	int l = 0;
	while (cin.get(c))
	{
		if (isspace(c))
			continue;
		r[l++] = c;
		if (l == 19)
		{
			cout << endl;
			cout << "到达上限" << endl;
			break;
		}
	}
	r[l - 1] = 0;

	cout << r << endl;

	delete [] r;
}

void Exercise12_26()
{
	std::allocator<string> alloc;
	auto const p = alloc.allocate(10);
	string s;
	string *q = p;
	while (q != p + 10 && cin >> s)
	{
		alloc.construct(q++, s);
	}
	const size_t size = q - p;

	for (size_t i = 0; i < size; ++i)
	{
		cout << p[i] << endl;
	}

	while (q != p)
	{
		alloc.destroy(--q);
	}
	alloc.deallocate(p, 10);
}

void Exercise12_27()
{
	ifstream ifile("123.txt", ifstream::in);
	TextQuery textQuery(ifile);
	TextQueryResult queryResult = textQuery.query("the");
	cout << queryResult.sought << " ";
	for (const auto& i : *queryResult.lines)
	{
		cout << i << " ";
	}
	cout << endl;
}

typedef map<string, set<int> > strToSetInt;

bool is_space_line(const string& strLine)
{
	bool is_space = true;
	for (auto &c:strLine)
	{
		if (!isspace(c))
			is_space = false;
	}
	return is_space;
}

void read_text(ifstream &ifile,strToSetInt& wm)
{
	int iLine = 0;
	string strLine;
	vector <string> strLineVec;
	while (getline(ifile, strLine))
	{
		if (is_space_line(strLine))
			continue;
		strLineVec.push_back(strLine);
		++iLine;
		string strWord;
		istringstream strStream(strLine);
		while (strStream >> strWord)
		{
			wm[strWord].insert(iLine);
		}
	}
}

void query_print(const string &str, strToSetInt &wm,ostream &os)
{
	set<int> lines;
	if (wm.find(str) != wm.end())
	{
		lines = wm[str];
	}

	os << str << " ";
	for (const auto& i : lines)
	{
		os << i << " ";
	}
	os << endl;
}

void Exercise12_28()
{
	ifstream ifile("E:\\code\\Test\\Debug\\123.txt", ifstream::in);
	if (!ifile)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	strToSetInt wm;
	read_text(ifile, wm);
	do
	{
		cout << "请输入要查找的单词:" << endl;
		string str;
		if (!(cin >> str) || str == "q")
			break;
		query_print(str, wm, cout);
	} while (true);
}