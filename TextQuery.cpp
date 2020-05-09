#include "stdafx.h"

#include <iterator>
using std::inserter;

#include "TextQuery.h"
#include "MyTemplate.h"

TextQuery::TextQuery(ifstream & ifile) :file(new StrVec,DebugDelete() )
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

TextQueryResult NotQuery::eval(const TextQuery& text) const
{
	auto result = query.eval(text);
	auto retLine = make_shared<set<int> >();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0;n != sz;++n)
	{
		if (beg == end || n != *beg)
		{
			retLine->insert(n);
		}
		else if (beg != end)
		{
			++beg;
		}
	}
	return TextQueryResult(rep(), retLine, result.get_file());
}

TextQueryResult AndQuery::eval(const TextQuery& text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);

	auto retLine = make_shared<set<int> >();
	set_intersection(left.begin(),left.end(),
		right.begin(), right.end(),
		inserter(*retLine,retLine->begin()));
	retLine->insert(left.begin(), left.end());

	return TextQueryResult(rep(), retLine, left.get_file());
}

TextQueryResult OrQuery::eval(const TextQuery& text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);

	auto retLine = make_shared<set<int> >(right.begin(), right.end());
	retLine->insert(left.begin(), left.end());

	return TextQueryResult(rep(), retLine, left.get_file());
}