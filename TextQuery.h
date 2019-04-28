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
	shared_ptr<vector<string> > file;
};

class TextQueryResult
{
public:
	TextQueryResult(const string &s, shared_ptr<set<int> >p, const shared_ptr<vector<string> > f) :sought(s), lines(p), file(f){}
	shared_ptr<vector<string> >get_file(){ return file; }
	set<int>::const_iterator begin() const{ return lines->begin(); }
	set<int>::const_iterator end() const{ return lines->end(); }
	string sought;
	shared_ptr<set<int> > lines;
	shared_ptr<vector<string> > file;
protected:
private:
};