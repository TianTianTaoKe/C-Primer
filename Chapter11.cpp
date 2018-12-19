#include "Chapter11.h"

void Exercise11_1()
{
	ifstream ifile("D:\\Code\\test\\Debug\\book.txt", ifstream::in);
	string word;
	map<string, int> wordCountMap;
	while (ifile >> word)
	{
		++wordCountMap[word];
	}
	for (auto &s : wordCountMap)
	{
		cout << s.first << "出现" << s.second << "次" << endl;
	}
}

void Trans(string &str)
{
	for (string::size_type i = 0; i < str.size(); ++i)
	{
		if (ispunct(str[i]))
		{
			str.erase(i);
		}
		else
		{
			str[i] = toupper(str[i]);
		}
	}
}

void Exercise11_2()
{
	ifstream ifile("D:\\Code\\test\\Debug\\book.txt", ifstream::in);
	string word;
	map<string, int> wordCountMap;
	while (ifile >> word)
	{
		Trans(word);
		++wordCountMap[word];
	}
	for (auto &s : wordCountMap)
	{
		cout << s.first << "出现" << s.second << "次" << endl;
	}
}