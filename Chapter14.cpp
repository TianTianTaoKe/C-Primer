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