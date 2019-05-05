#include "stdafx.h"
#include "TextQuery.h"

TextQuery::TextQuery(ifstream & ifile) :file(new StrVec )
{
	int iLine = 0;
	string strLine;
	while (getline(ifile, strLine))
	{
		file->push_back(strLine);
		++iLine;
		string strWord;
		istringstream strStream(strLine);
		while (strStream >> strWord)
		{
			shared_ptr<set<int> > &lines = wm[strWord];
			if (!lines)
			{
				lines.reset(new set<int>);
			}
			lines->insert(iLine);
		}
	}
}

TextQueryResult TextQuery::query(const string& sought) const
{
	static shared_ptr<set<int> >nodata(new set<int>);
	map<string, shared_ptr<set<int> > >::const_iterator isPos = wm.find(sought);
	if (wm.find(sought) != wm.end())
	{
		return TextQueryResult(sought, isPos->second,file);
	}
	else
		return TextQueryResult(sought, nodata,file);
}