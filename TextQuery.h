#pragma once

class TextQueryResult;
class TextQuery
{
public:
	TextQuery(ifstream & ifile);
	TextQueryResult query(const string& sought) const;
protected:
private:
	map<string, shared_ptr< set<int> > > wm;
};

class TextQueryResult
{
public:
	TextQueryResult(const string &s, shared_ptr<set<int> >p):sought(s),lines(p){}
	string sought;
	shared_ptr<set<int> > lines;
protected:
private:
};