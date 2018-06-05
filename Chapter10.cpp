#include "Chapter10.h"

void Exercise10_1()
{
	vector<int> veci = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 6, 7, 6 };
	int nCount = count(veci.cbegin(), veci.cend(), 6);
	cout << nCount << endl;
}

void Exercise10_2()
{
	list<string> listStr = { "123", "234", "345", "234" };
	int nCount = count(listStr.cbegin(), listStr.cend(), "234");
	cout << nCount << endl;
}

void Exercise10_3()
{
	vector<int> veci = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sum = accumulate(veci.cbegin(), veci.cend(), 0);
	cout << sum << endl;
}

void Exercise10_6()
{
	vector<int> veci = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	fill_n(veci.begin(), veci.size(), 0);
	for (auto i : veci)
	{
		cout << i << endl;
	}
}

void Exercise10_9()
{
	vector<int> veci = { 2, 2, 1, 2, 5,7, 7, 8, 7, 10 };
	for (auto i : veci)
	{
		cout << i << endl;
	}
	sort(veci.begin(), veci.end());
	for (auto i : veci)
	{
		cout << i << endl;
	}
	auto end_unique =  unique(veci.begin(), veci.end());
	for (auto i : veci)
	{
		cout << i << endl;
	}
	veci.erase(end_unique, veci.end());
	for (auto i : veci)
	{
		cout << i << endl;
	}
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void Exercise10_11()
{
	vector<string> veci = { "abc","erty","tyu","art","abc","tyu" };
	for (const auto &i : veci)
	{
		cout << i << endl;
	}
	cout << endl;

	sort(veci.begin(), veci.end());
	for (const auto &i : veci)
	{
		cout << i << endl;
	}
	cout << endl;

	auto end_unique = unique(veci.begin(), veci.end());
	for (const auto &i : veci)
	{
		cout << i << endl;
	}
	cout << endl;

	veci.erase(end_unique, veci.end());
	for (const auto &i : veci)
	{
		cout << i << endl;
	}
	cout << endl;

	stable_sort(veci.begin(), veci.end(), isShorter);
	for (const auto &i : veci)
	{
		cout << i << endl;
	}
}

bool compareIsbn(const Sales_data& book1, const Sales_data& book2)
{
	return book1.isbn() < book2.isbn();
}

void Exercise10_12(const char * filePath)
{
	ifstream inFile(filePath);
	if (!inFile)
	{
		cout << "�������ļ�ʧ��" << endl;
		return;
	}

	vector <Sales_data> vecSalesData;
	Sales_data temp;
	while (read(inFile,temp))
	{
		vecSalesData.push_back(temp);
	}

	sort(vecSalesData.begin(), vecSalesData.end(), compareIsbn);
	for (const auto &s:vecSalesData)
	{
		print(cout, s);
		cout << endl;
	}
}

void PrintWords(vector<string>::iterator iterBegin, vector<string>::iterator iterEnd)
{
	vector<string>::iterator iter;
	for (iter = iterBegin; iter != iterEnd; ++iter)
	{
		cout << *iter << endl;
	}
	cout << endl;
}

bool FiveOrMore(const string &str)
{
	return str.size() >= 5;
}

void Exercise10_13()
{
	vector<string> veci = { "abc", "ertyy", "tyu", "artyy", "abc", "tyuu" };
	PrintWords(veci.begin(),veci.end());
	vector<string>::iterator iter = partition(veci.begin(), veci.end(), FiveOrMore);
	PrintWords(veci.begin(), iter);
}

void Exercise10_15()
{
	int a = 10;
	auto f = [a](int b)->int{return a + b; };
	cout << f(3) << endl;
}

void Exercise10_16()
{
	vector<string> veci = { "abc", "erty", "tyu", "art", "abc", "tyu" };
	PrintWords(veci.begin(), veci.end());

	sort(veci.begin(), veci.end());
	PrintWords(veci.begin(), veci.end());

	auto end_unique = unique(veci.begin(), veci.end());
	PrintWords(veci.begin(), veci.end());

	veci.erase(end_unique, veci.end());
	PrintWords(veci.begin(), veci.end());

	stable_sort(veci.begin(), veci.end(), isShorter);
	PrintWords(veci.begin(), veci.end());

	int sz = 4;

	auto wc = find_if(veci.begin(), veci.end(), [sz](const string &a){return a.size() >= sz; });
	auto count = veci.end() - wc;
	for_each(wc, veci.end(), [](const string & a){cout << a << " "; });
}

void Exercise10_17(const char * filePath)
{
	ifstream inFile(filePath);
	if (!inFile)
	{
		cout << "�������ļ�ʧ��" << endl;
		return;
	}

	vector <Sales_data> vecSalesData;
	Sales_data temp;
	while (read(inFile, temp))
	{
		vecSalesData.push_back(temp);
	}

	sort(vecSalesData.begin(), vecSalesData.end(), [](const Sales_data& sd1, const Sales_data& sd2){return sd1.isbn() < sd2.isbn(); });
	for (const auto &s : vecSalesData)
	{
		print(cout, s);
		cout << endl;
	}
}

void Exercise10_18()
{
	vector<string> veci = { "abcy", "erty", "tyu", "art", "abcy", "tyu" };
	PrintWords(veci.begin(), veci.end());

	sort(veci.begin(), veci.end());
	PrintWords(veci.begin(), veci.end());

	auto end_unique = unique(veci.begin(), veci.end());
	PrintWords(veci.begin(), veci.end());

	veci.erase(end_unique, veci.end());
	PrintWords(veci.begin(), veci.end());

	stable_sort(veci.begin(), veci.end(), isShorter);
	PrintWords(veci.begin(), veci.end());

	int sz = 4;

	auto wc = partition(veci.begin(), veci.end(), [sz](const string &a){return a.size() >= sz; });
	
	for_each(veci.begin(),wc, [](const string & a){cout << a << " "; });
}

void Exercise10_19()
{
	vector<string> veci = { "abcy", "erty", "tyu", "art", "abcy", "tyu" };
	PrintWords(veci.begin(), veci.end());

	sort(veci.begin(), veci.end());
	PrintWords(veci.begin(), veci.end());

	auto end_unique = unique(veci.begin(), veci.end());
	PrintWords(veci.begin(), veci.end());

	veci.erase(end_unique, veci.end());
	PrintWords(veci.begin(), veci.end());

	stable_sort(veci.begin(), veci.end(), isShorter);
	PrintWords(veci.begin(), veci.end());

	int sz = 4;

	auto wc = stable_partition(veci.begin(), veci.end(), [sz](const string &a){return a.size() >= sz; });

	for_each(veci.begin(), wc, [](const string & a){cout << a << " "; });
}

void Exercise10_20()
{
	vector<string> veci = { "abcy", "erty", "tyutyt", "art", "abcy", "tyu" };
	int count = count_if(veci.begin(), veci.end(), [](const string &str){return str.size() >= 6; });
	cout << count << endl;
}

void Exercise10_21()
{
	int a = 10;
	auto f = [&a]{return (--a) == 0; };
	int i = 0;
	while (!f())
	{
		cout << ++i << endl;
	}
}