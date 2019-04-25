#include "stdafx.h"

#include "Chapter11.h"

void Exercise11_3()
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

void Exercise11_4()
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

typedef map<string, vector<string> > strToVecStr;

void addFamily(strToVecStr &families, const string &strFamily)
{
	families[strFamily];
}

void addChild(strToVecStr &families, const string &strFamily, const string &strChild)
{
	families[strFamily].push_back(strChild);
}

void Exercise11_7()
{
	strToVecStr families;
	addFamily(families, "张");
	addChild(families, "张","三");
	addChild(families, "张", "四");

	addFamily(families, "李");
	addChild(families, "李", "一");
	addChild(families, "李", "二");

	for (auto f:families)
	{
		cout << f.first << "家的孩子: ";
		for (auto c:f.second)
		{
			cout << c << " ";
		}
		cout << endl;
	}
}

void Exercise11_8()
{
	ifstream ifile("E:\\代码\\C-Primer\\Debug\\123.txt", ifstream::in);
	string strWord;
	vector<string> uniqueWords;
	while (ifile>>strWord)
	{
		Trans(strWord);
		if (find(uniqueWords.begin(), uniqueWords.end(), strWord) == uniqueWords.end())
		{
			uniqueWords.push_back(strWord);
		}
	}

	for (const auto & w:uniqueWords)
	{
		cout << w << " ";
	}
	cout << endl;
}

void Exercise11_9()
{
	ifstream ifile("E:\\代码\\C-Primer\\Debug\\123.txt", ifstream::in);
	int iLine = 0;
	map<string, list<int> > wordLineList;
	string strLine;
	while (getline(ifile,strLine))
	{
		++iLine;
		string strWord;
		istringstream strStream(strLine);
		while (strStream >> strWord)
		{
			if (find(wordLineList[strWord].begin(), wordLineList[strWord].end(), iLine) == wordLineList[strWord].end())
			{
				wordLineList[strWord].push_back(iLine);
			}
		}
	}

	for (const auto& l : wordLineList)
	{
		cout << l.first << ": ";
		for (auto i : l.second)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}

void Exercise11_12()
{
	vector<pair<string, int> >vecStringIntPair;
	pair<string, int> pair1("1", 1);
	pair<string, int> pair2("2", 2);
	pair<string, int> pair3("3", 3);

	vecStringIntPair.push_back(pair<string, int> ("1", 1));
	vecStringIntPair.push_back({"2",2});
	vecStringIntPair.push_back(make_pair("3",3));

	for (const auto& p:vecStringIntPair)
	{
		cout << p.first << ":" << p.second << endl;
	}
}

void addFamily(map<string, vector<pair<string, string> > > &families, const string &strFamily)
{
	families[strFamily];
}

void addChild(map<string, vector<pair<string, string> > > &families, const string &strFamily, const string &strChild, const string &strBirthDay)
{
	families[strFamily].push_back({strChild,strBirthDay});
}

void Exercise11_14()
{
	map<string,vector<pair<string,string> > > families;

	addFamily(families, "张");
	addChild(families, "张", "一","19901010");
	addChild(families, "张", "二", "19900909");

	addFamily(families, "李");
	addChild(families, "李", "一", "199011111");
	addChild(families, "李", "二", "19901212");

	for (auto f : families)
	{
		cout << f.first << "家的孩子: ";
		for (auto c : f.second)
		{
			cout << c.first << ":" << c.second << " ";
		}
		cout << endl;
	}
}

void Exercise11_20()
{
	unordered_map <string, int> wordCount;
	ifstream ifile("E:\\代码\\C-Primer\\Debug\\123.txt", ifstream::in);
	string word;
	while (ifile >> word)
	{
		auto ret = wordCount.insert(pair<string, int>(word, 0));
		ret.first->second++;
	}
	for (const auto &m : wordCount)
	{
		cout << m.first << "出现" << m.second << "次" << endl;
	}
}

typedef std::multimap<string, string > strToStrMMap;


void addChild(strToStrMMap &families, const string &strFamily, const string &strChild)
{
	families.insert({ strFamily, strChild });
}

void Exercise11_23()
{
	strToStrMMap families;
	addChild(families, "张", "三");
	addChild(families, "张", "四");

	addChild(families, "李", "一");
	addChild(families, "李", "二");

	for (auto f : families)
	{
		cout << f.first << "家的孩子: ";
		cout << f.second << " ";
		cout << endl;
	}
}

void removeBook(strToStrMMap &books, const string strAuthor)
{
	auto mmapIterRange = books.equal_range(strAuthor);
	if (mmapIterRange.first != mmapIterRange.second)
	{
		books.erase(mmapIterRange.first, mmapIterRange.second);
	}
}

void printBook(const strToStrMMap &books)
{
	for (auto s:books)
	{
		cout << s.first << " " << s.second << endl;
	}
}

void Exercise11_31()
{
	strToStrMMap books;
	books.insert({ "金庸", "射雕英雄传" });
	books.insert({ "古龙", "多情剑客无情剑" });
	books.insert({ "金庸", "神雕侠侣" });

	printBook(books);
	removeBook(books, "金庸");
	cout << endl;
	printBook(books);
}

typedef unordered_map<string, string> strTostrMap;

void readRule(ifstream &ifile, strTostrMap &ruleMap)
{
	string strLine;
	while (getline(ifile,strLine))
	{
		istringstream strStream(strLine);
		string strWord, strTransWord;
		if (strStream>>strWord && getline(strStream,strTransWord))
		{
			if (strTransWord.size() > 1)
			{
				strTransWord = strTransWord.substr(1);
				ruleMap[strWord] = strTransWord;
			}
		}
	}
}

string transWord(const strTostrMap &ruleMap, const string &strWord)
{
	auto mapIter = ruleMap.find(strWord);
	if (mapIter != ruleMap.end())
	{
		return mapIter->second;
	}
	else
		return strWord;
}

void Exercise11_33()
{
	ifstream ifileRule("E:\\代码\\C-Primer\\Debug\\rule.txt", ifstream::in);
	ifstream ifileBook("E:\\代码\\C-Primer\\Debug\\123.txt", ifstream::in);
	strTostrMap ruleMap;
	readRule(ifileRule, ruleMap);

	string strLine;
	while (getline(ifileBook,strLine))
	{
		istringstream strStream(strLine);
		string strWord;
		bool isFirstWord = true;
		while (strStream >> strWord)
		{			
			if (isFirstWord)
			{
				isFirstWord = false;
			}
			else
			{
				cout << " ";
			}
			strWord = transWord(ruleMap, strWord);
			cout << strWord;
		}
		cout << endl;
	}
}