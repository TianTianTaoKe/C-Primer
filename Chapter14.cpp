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
	CheckSize checkSize(1);
	string word;
	int count = 0;
	while (ifile >> word)
	{
		if (checkSize(word))
		{
			count++;
		}
	}
	cout << "count = " << count << endl;
}