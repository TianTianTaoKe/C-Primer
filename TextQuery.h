#pragma once

class TextQueryResult;
class TextQuery
{
public:
	TextQuery(ifstream & ifile);
	TextQueryResult query(const string& sought);
protected:
private:
	map<string, set<int> > wm;
};

class TextQueryResult
{
public:
	TextQueryResult(){};
	string sought;
	set<int> lines;
protected:
private:
	
	
};