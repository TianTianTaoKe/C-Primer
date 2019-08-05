#include "stdafx.h"

#include "Chapter14.h"
#include "Sales_data.h"
#include "X.h"

void Exercise14_9()
{
	Sales_data s;
	cin >> s;
	cout << s;
}

void Exercise14_36()
{
	ReadString readString(cin);
	vector<string> vecStr;
	while (true)
	{
		string line = readString();
		if (!line.empty())
		{
			vecStr.push_back(line);
		}
		else
			break;;
	}
}

void Exercise14_37()
{
	vector<int> vecInt = { 1, 2, 3, 4, 5, 4 };
	const int oldValue = 4;
	const int newValue = 400;
	IntCompare icmp(oldValue);
	std::replace_if(vecInt.begin(), vecInt.end(), icmp, newValue);
}

void Exercise14_38()
{
	ifstream ifile;
	ifile.open(".\\test.txt",ifstream::in);
	
	string word;
	vector<string> vecWord;
	int count = 0;
	while (ifile >> word)
	{
		vecWord.push_back(word);
	}
	const int minLen = 1;
	const int maxLen = 10;
	for (int i = minLen;i<= maxLen;++i)
	{
		CheckSize checkSize(i);
		cout << "Len : " << i << ",cnt :" << count_if(vecWord.begin(), vecWord.end(), checkSize) << endl;
	}
}

void Exercise14_39()
{
	ifstream ifile;
	ifile.open(".\\test.txt", ifstream::in);

	string word;
	vector<string> vecWord;
	int count = 0;
	while (ifile >> word)
	{
		vecWord.push_back(word);
	}

	StrLenBetween strLenBetween(1, 9);
	StrNotShorterThan strNotShorterThan(10);
	cout << "Len 1~9 ,cnt :" << count_if(vecWord.begin(), vecWord.end(), strLenBetween) << endl;
	cout << "Len >=10 ,cnt :" << count_if(vecWord.begin(), vecWord.end(), strNotShorterThan) << endl;
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void Exercise14_40(vector <string> &words,vector<string>::size_type sz)
{
	elimDups(words);
	IsShoter is;
	stable_sort(words.begin(), words.end(), is);

	StrNotShorterThan nst(sz);
	auto wc = find_if(words.begin(), words.end(), nst);
	auto count = words.end() - wc;

	cout << count << " words of length " << sz << "or longer" << endl;

	PrintClass ps;
	for_each(wc, words.end(), ps);
	cout << endl;
}

void Exercise14_42()
{
	/*
	(a) count_if(vec.begin(),vec.end(),bind2nd(greater<int>(),1024));
	(b) find_if(vec.begin(),vec.end(),bind2nd(not_equal_to<string>(),"pooh"));
	(c) transform(vec.begin(), vec.end(), vec.begin(), bind2nd(multiplies<int>(), 2));
	*/
}

bool Exercise14_43(vector<int>& ivec, int dividend)
{
	return count_if(ivec.begin(), ivec.end(), bind1st(modulus<int>(), dividend)) == 0;	
}

int Exercise14_44(string op, int a, int b)
{
	map<string, function<int(int, int)> > binOps = {
		{"+",std::plus<int>()},
		{"-",std::minus<int>()},
		{"*",std::multiplies<int>()},
		{"/",std::divides<int>()},
		{"%",std::modulus<int>()},
	};

	return binOps[op](a, b);
}

void Exercise14_46()
{
	/*
	Sale_data类不应该定义这两种类型转换，因为该类有多个成员变量，这些变量组合在一起才有意义，如果确实需要定义
	应该申明成explicit，防止Sals_data被默认转换成string或者double
	*/
}

void Exercise14_47()
{
	/*
	第一个表示类型转换成const int
	第二个表示常量函数	
	*/
}

void Exercise14_48()
{
	/*
	可以含有，用来判断数据成员是否有效
	bool类型转换运算符应该声明称explicit，因为需要在条件表达式中使用
	*/
}

void Exercise14_50()
{
	/*
	1.需要把LongDouble转换为int型，两个类型转换运算符都可以，有二义性
	2.需要把LongDouble转换为float型，直接调用operator float（）即可
	*/
}

void Exercise14_51()
{
	/*
	优先调用void calc（int）函数，因为double转换成int是标准类型转换，
	而转换成LongDouble则是转换为用户自定义类型，实际上是调用了转换构造函数，因此前者优先
	*/
}

void Exercise14_52()
{
	/*
	1.LongDouble不能转成成SmallInt,SallInt不能转换成LongDouble,成员函数operator+和非成员函数都不能用
	SmallInt可以转换为int，LongDouble可以转换成float或double，operator+（int，double）和operator+（
	int，float）都可以
	2.LongDoubled的operator+精确匹配
	*/
}

void Exercise14_53()
{
	/*
	内置的operator+（int，double）可行，3.14可以转化成int再转黄成SmallInt所以SmallInt的成员函数
	operator+也可行，二者都要类型转换，有二义性。改为double d = s1 + SmallInt（3.14）
	*/
}