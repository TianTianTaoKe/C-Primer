#include "stdafx.h"
#include "TextQuery.h"

TextQuery::TextQuery(ifstream & ifile)
{
	int iLine = 0;
	string strLine;
	while (getline(ifile, strLine))
	{
		++iLine;
		string strWord;
		istringstream strStream(strLine);
		while (strStream >> strWord)
		{
			wm[strWord].insert(iLine);
		}
	}
}

TextQueryResult TextQuery::query(const string& sought)
{
	TextQueryResult queryResult;
	queryResult.sought = sought;
	if (wm.find(sought) != wm.end())
	{
		queryResult.lines = wm[sought];
	}
	return queryResult;
}