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