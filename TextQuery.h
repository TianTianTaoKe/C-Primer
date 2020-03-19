#pragma once

#include "X.h"

class TextQueryResult;
class TextQuery
{
public:
	TextQuery(ifstream & ifile);
	TextQueryResult query(const string& sought) const;
	using line_no = std::vector<std::string>::size_type;

protected:
private:
	map<string, shared_ptr< set<int> > > wm;
	shared_ptr<StrVec > file;
};

class TextQueryResult
{
public:
	TextQueryResult() = default;
	TextQueryResult(const string &s, shared_ptr<set<int> >p, const shared_ptr<StrVec > f) :sought(s), lines(p), file(f){}
	shared_ptr<StrVec >get_file(){ return file; }
	set<int>::const_iterator begin() const{ return lines->begin(); }
	set<int>::const_iterator end() const{ return lines->end(); }
	string sought;
	shared_ptr<set<int> > lines;
	shared_ptr<StrVec > file;
protected:
private:
};

class QueryBase
{
public:
	friend class Query;
protected:
	using LineNo = TextQuery::line_no;
	virtual ~QueryBase() = default;
private:
	virtual TextQueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;
};

class WordQuery:public QueryBase
{
	friend class Query;
	WordQuery(const string& s) :queryWord(s) { cout << "WordQuery(const string& s)" << endl; }
	TextQueryResult eval(const TextQuery& t) const { return t.query(queryWord); }
	string rep() const { cout << "WordQuery" << endl; return queryWord; }
	string queryWord;
};

class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string& s) :q(new WordQuery(s)) { cout << "Query(const string& s)" << endl; }
	TextQueryResult eval(const TextQuery& t) const { return q->eval(t); }
	string rep() const { cout << "Query " << endl; return q->rep(); }

private:
	Query(shared_ptr<QueryBase> query) :q(query) { cout << "Query(shared_ptr<QueryBase> query)" << endl; }
	shared_ptr<QueryBase> q;
};

class NotQuery:public QueryBase
{
	friend Query operator~(const Query&);
	NotQuery(const Query& q) :query(q) { cout << "NotQuery(const Query& q)" << endl; }
	string rep() const { cout << "NotQuery" << endl; return "~(" + query.rep() + ")"; }
	TextQueryResult eval(const TextQuery&) const;
	Query query;
};

inline Query operator~(const Query& operand)
{
	return shared_ptr<QueryBase>(new NotQuery(operand));
}

class BinaryQuery :public QueryBase
{
protected:
	BinaryQuery(const Query& l, const Query& r, std::string s) :lhs(l), rhs(r), opSym(s) { cout << "BinaryQuery(const Query& l, const Query& r, std::string s)" << endl; }
	string rep() const 
	{
		cout << "BinaryQuery" << endl;
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}

	Query lhs, rhs;
	string opSym;
};

class AndQuery :public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) :BinaryQuery(left, right, "&") { cout << "AndQuery(const Query& left, const Query& right)" << endl; }
	TextQueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs)
{
	return shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& left, const Query& right) :BinaryQuery(left, right, "|") { cout << "OrQuery(const Query& left, const Query& right)" << endl; }
	TextQueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query& lhs, const Query& rhs)
{
	return shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

inline ostream& operator<<(std::ostream& os, const Query& query)
{
	return os << query.rep();
}

