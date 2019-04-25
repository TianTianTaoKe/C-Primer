#include "stdafx.h"

#include "Chapter9.h"

bool Exercise9_4(vecint::const_iterator begin, vecint::const_iterator end, int val)
{
	for (vecint::const_iterator iter = begin; iter != end;++iter)
	{
		if (*iter == val)
		{
			return true;
		}
	}
	return false;
}

vecint::iterator  Exercise9_5(vecint::iterator begin, vecint::iterator end, int val)
{
	for (vecint::iterator iter = begin; iter != end; ++iter)
	{
		if (*iter == val)
		{
			return iter;
		}
	}
	
	return end;
}

//9.13
list<int> ilist = { 1, 2, 3, 4, 5 };
vector<int> iVec = { 1, 2, 3, 4, 5 };
vector<double>dVec(ilist.begin(), ilist.end());
vector<double>dVec2(iVec.begin(), iVec.end());

//9.14
void Exercise9_14()
{
	list<char *>chList{ "1", "2", "3" };
	vector<string > strVec1;
	strVec1.assign(chList.begin(), chList.end());
}

bool Exercise9_15(vecint &a, vecint&b)
{
	return a == b;
}

bool Exercise9_16(list<int>& iLIst, vecint& iVec)
{
	if (iLIst.size() != iVec.size())
	{
		return false;
	}
	auto lb = iLIst.cbegin();
	auto le = iLIst.cend();
	auto vb = iVec.cbegin();
	for (; lb != le;lb++,vb++)
	{
		if (*lb != *vb)
		{
			return false;
		}
	}
	return true;
}

void Exercise9_18()
{
	string word;
	deque<string> dqStr;
	while (cin >> word)
	{
		dqStr.push_back(word);
	}
	for (const auto &str:dqStr)
	{
		cout << str << endl;
	}
}

void Exercise9_19()
{
	string word;
	list<string> lStr;
	while (cin >> word)
	{
		lStr.push_back(word);
	}
	for (const auto &str : lStr)
	{
		cout << str << endl;
	}
}

void Exercise9_20()
{
	list <int> ilist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	deque<int> oddDq, evenDq;
	for (auto iter = ilist.cbegin(); iter != ilist.cend();++iter)
	{
		if (*iter & 1)
		{
			oddDq.push_back(*iter);
		}
		else
		{
			evenDq.push_back(*iter);
		}
	}
}

void Exercise9_22()
{
	vecint iv = { 1, 2, 3, 2, 5, 2, 7, 8, 9, 10 };
	//int someVal = 2,newCount = 0,OrgSize = iv.size();
	//vecint::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	//while (iter != iv.begin() + OrgSize/2 + newCount)
	//{
	//	if (*iter == 2)
	//	{
	//		iter = iv.insert(iter, 2 * someVal);
	//		iter++; iter++;
	//		++newCount;
	//	}
	//	else
	//	{
	//		iter++;
	//	}
	//}
	vecint::iterator iter = iv.begin();
	int OrgSize = iv.size(), someVal = 2;
	for (int i = 0; i < OrgSize/2;++i)
	{
		if (*iter == someVal)
		{
			iter = iv.insert(iter, 2 * someVal);
			++iter; ++iter;
		}
		else
			++iter;
	}

	for (iter = iv.begin(); iter != iv.end();++iter)
	{
		cout << *iter << endl;
	}
}

void Exercise9_26()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vecint iv(ia, ia + 11);
	vecint::iterator iIter = iv.begin();
	while (iIter != iv.end())
	{
		if (!(*iIter & 1))
		{
			iIter = iv.erase(iIter);
		}
		else
			++iIter;
	}
	list <int> il(ia, ia + 11);
	list<int>::iterator lIter = il.begin();
	while (lIter != il.end())
	{
		if (*lIter & 1)
		{
			lIter = il.erase(lIter);
		}
		else
			++lIter;
	}
}

void Exercise9_27()
{
	forward_list<int> iFlist = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	forward_list<int>::iterator prev = iFlist.before_begin();
	forward_list<int>::iterator curr = iFlist.begin();
	while (curr != iFlist.end())
	{
		if ((*curr) & 1)
		{
			curr = iFlist.erase_after(prev);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}
}

void Exercise9_28(forward_list<string> &strFlist, string &findStr, string &addStr)
{
	forward_list<string>::iterator iter = strFlist.begin();
	forward_list<string>::iterator prev = strFlist.before_begin();
	while (iter != strFlist.end())
	{
		if (*iter == findStr)
		{
			strFlist.insert_after(iter, addStr);
			break;
		}
		++iter;
		++prev;
	}
	if (iter == strFlist.end())
	{
		strFlist.insert_after(prev, addStr);
	}
}

void Exercise9_31()
{
	forward_list<int> iFlist = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	forward_list<int>::iterator prev = iFlist.before_begin();
	forward_list<int>::iterator curr = iFlist.begin();
	while (curr != iFlist.end())
	{
		if (!(*curr) & 1)
		{
			curr = iFlist.erase_after(prev);
		}
		else
		{
			curr = iFlist.insert_after(curr, *curr);
			prev = curr;
			++curr;
		}
	}
}

void Exercise9_38()
{
	vector<int> iVec;
	for (int i = 0; i < 1000;++i)
	{
		cout << iVec.size() << " " << iVec.capacity() << endl;
		iVec.push_back(0);
	}
}

void Exercise9_42(string &s)
{
	s.reserve(100);
	char c;
	while (cin>>c)
	{
		s.push_back(c);
	}
}

void Exercise9_43(string &s,string oldVal,string newVal)
{
	if (oldVal.empty())
	{
		return;
	}
	string::iterator iter = s.begin();
	while (iter != s.end())
	{
		auto iter1 = iter;
		auto iter2 = oldVal.begin();
		while (iter2 != oldVal.end() && iter1 != s.end() && *iter1 == *iter2)
		{
			++iter1;
			++iter2;
		}
		if (iter2 == oldVal.end())
		{
			iter = s.erase(iter, iter1);
			iter = s.insert(iter, newVal.begin(), newVal.end());
			iter += newVal.size();
		}
		else
			++iter;
	}
}

void Exercise9_44(string &s, string oldVal, string newVal)
{
	if (oldVal.empty())
	{
		return;
	}
	string::size_type pos = 0;
	while (pos < s.size() - oldVal.size() + 1)
	{
		auto pos1 = pos;
		auto pos2 = 0;
		while (pos2 < oldVal.size()  && s[pos1] == oldVal[pos2])
		{
			++pos1;
			++pos2;
		}
		if (pos2 == oldVal.size())
		{
			s.replace(pos,oldVal.size(), newVal);
			pos += newVal.size();
		}
		else
			++pos;
	}
}

void Exercise9_45(string &s, string prefix, string suffix)
{
	s.insert(s.begin(), 1, ' ');
	s.insert(s.begin(), prefix.begin(),prefix.end());
	s.append(" ");
	s.append(suffix);
}

void Exercise9_46(string &s, string prefix, string suffix)
{
	s.insert(0, 1, ' ');
	s.insert(0, prefix);
	s.insert(s.size()," ");
	s.insert(s.size(), suffix);
}

void Exercise9_47()
{
	string str = "ab2c3d7R4E6";
	string strNum = "1234567890";
	string strLetter = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int pos = 0;
	while ((pos = str.find_first_of(strNum, pos)) != string::npos)
	{
		cout << pos << " ";
		++pos;
	}
	cout << endl;
	pos = 0;
	while ((pos = str.find_first_not_of(strLetter,pos)) != string::npos)
	{
		cout << pos << " ";
		++pos;
	}
	cout << endl;
}

void Exercise9_49(ifstream &in)
{
	int iMaxLength = 0;
	string str, strLongest;
	string strTmep = "bdfghjklpqty";
	while (in >> str)
	{
		if (str.find_first_of(strTmep) != string::npos)
		{
			continue;
		}
		if (str.size() > iMaxLength)
		{
			iMaxLength = str.size();
			strLongest = str;
		}
	}
	cout << strLongest;
}

int Exercise9_50(vecstr & strVec)
{
	double sum = 0;
	for (auto &str:strVec)
	{
		sum += stod(str);
	}
	return sum;
}

//9.51
 const  string strMonthName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
 const  string strMonthAbbr[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
 const  int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

data::data(string ds)
{
	istringstream is(ds);
	vecstr strVec;
	string strTemp;
	while (is>>strTemp)
	{
		strVec.push_back(strTemp);
	}
	if (strVec.size() == 0 || strVec.size() > 3)
	{
		throw invalid_argument("参数格式不对");
	}
	if (strVec.size() == 1)
	{
		strTemp = strVec.at(0);
		month = stoi(strTemp);
		if (month > 12 || month < 1)
		{
			throw invalid_argument("不是合法日期");
		}
		int pos = strTemp.find('/');
		if (pos == string::npos)
		{
			throw invalid_argument("分隔符非法");
		}
		strTemp = strTemp.substr(pos + 1);
		day = stoi(strTemp);
		if (day > days[month - 1] || day < 1)
		{
			throw invalid_argument("不是合法日期");
		}
		pos = strTemp.find('/');
		if (pos == string::npos)
		{
			throw invalid_argument("分隔符非法");
		}
		strTemp = strTemp.substr(pos + 1);
		year = stoi(strTemp);
	}
	else if (strVec.size() > 1)
	{
		month = GetMonth(strVec.at(0));
		day = stoi(strVec.at(1));
		if (day > days[month - 1] || day < 1)
		{
			throw invalid_argument("不是合法日期");
		}
		if (strVec.size() == 2)
		{
			strTemp = strVec.at(1);
			int pos = strTemp.find(',');
			if (pos == string::npos)
			{
				throw invalid_argument("分隔符非法");
			}
			strTemp = strTemp.substr(pos + 1);
			year = stoi(strTemp);
		}
		else if (strVec.size() == 3)
		{
			year = stoi(strVec.at(2));
		}
	}
}

unsigned data::GetMonth(string &month)
{
	for (int i = 0; i < 12; ++i)
	{
		if (month.compare(strMonthName[i]) == 0 || month.compare(strMonthAbbr[i]) == 0)
		{
			return i + 1;
		}
	}
	throw invalid_argument("不是合法月份名称");
	return 0;
}

enum obj_type
{
	LP,RP,ADD,SUM,VAL
};

struct obj 
{
	obj_type t;
	double v;
	obj(obj_type type, double val = 0){ t = type; v = val; }
};

inline void skipws(string &exp, size_t &p)
{
	p = exp.find_first_not_of(" ", p);
}
inline void new_val(stack <obj>&so, double v)
{
	if (so.empty() || so.top().t == LP)
	{
		so.push(obj(VAL, v));
	}
	else if (so.top().t == ADD || so.top().t == SUM)
	{
		obj_type type = so.top().t;
		so.pop();
		if (type == ADD)
		{
			v += so.top().v;
		}
		else
		{
			v = so.top().v - v;
		}
		so.pop();
		so.push(obj(VAL, v));
	}
	else
	{
		throw invalid_argument("缺少运算符");
	}
}

double Exercise9_52(string & strExp)
{
	stack <obj> so;
	size_t p = 0,q;
	double v;
	while (p < strExp.size())
	{
		skipws(strExp, p);
		if (strExp[p] == '(')
		{
			so.push(obj(LP));
			p++;
		}
		else if (strExp[p] == '+' || strExp[p] == '-')
		{
			if (so.empty() || so.top().t != VAL)
			{
				throw invalid_argument("缺少运算数");
			}
			if (strExp[p] == '+')
			{
				so.push(obj(ADD));
			}
			else
				so.push(obj(SUM));
			p++;
		}
		else if (strExp[p] == ')')
		{
			p++;
			if (so.empty())
			{
				throw invalid_argument("未匹配右括号");
			}
			else if (so.top().t == LP)
			{
				throw invalid_argument("空括号");
			}
			else if (so.top().t == VAL)
			{
				v = so.top().v;
				so.pop();
				if (so.top().t != LP)
				{
					throw invalid_argument("未匹配右括号");
				}
				so.pop();
				new_val(so, v);
			}
			else
			{
				throw invalid_argument("缺少运算数");
			}
		}
		else
		{
			v = stod(strExp.substr(p), &q);
			p += q;
			new_val(so, v);
		}
	}
	if (so.size() != 1 || so.top().t != VAL)
	{
		throw invalid_argument("非法表达式");
	}

	return so.top().v;
}
//
//enum obj_type
//{
//	LP,RP,ADD,SUB,VAL
//};
//
//struct obj
//{
//	obj(obj_type type, double val = 0){ t = type; v = val; }
//	obj_type t;
//	double v;
//};
//
//inline void skipws(string &exp, size_t &p)
//{
//	p = exp.find_first_not_of(" ", p);
//}
//
//inline void new_val(stack<obj>&so, double v)
//{
//	if (so.empty() || so.top().t == LP)
//	{
//		so.push(obj(VAL, v));
//	}
//	else if (so.top().t == ADD || so.top().t == SUB)
//	{
//		obj_type type = so.top().t;
//		so.pop();
//		if (type == ADD)
//		{
//			v += so.top().v;
//		}
//		else
//		{
//			v = so.top().v - v;
//		}
//		so.pop();
//		so.push(obj(VAL, v));
//	}
//	else
//	{
//		throw invalid_argument("缺少运算符");
//	}
//}
//
//
//int Exercise_52(string &strExpression)
//{
//	stack<obj> so;
//	size_t p = 0, q;
//	double v;
//	while (p < strExpression.size())
//	{
//		skipws(strExpression, p);
//		if (strExpression[p] == '(')
//		{
//			so.push(obj(LP));
//			p++;
//		}
//		else if (strExpression[p] == '+' || strExpression[p] == '-')
//		{
//			if (so.empty() || so.top().t != VAL)
//			{
//				throw invalid_argument("缺少运算数");
//			}
//			if (strExpression[p] == '+')
//			{
//				so.push(obj(ADD));
//			}
//			else
//			{
//				so.push(obj(SUB));
//			}
//			p++;
//		}
//		else if (strExpression[p] == ')')
//		{
//			p++;
//			if (so.empty())
//			{
//				throw invalid_argument("未匹配右括号");
//			}
//			if (so.top().t == LP)
//			{
//				throw invalid_argument("空括号");
//			}
//			if (so.top().t == VAL)
//			{
//				v = so.top().v;0
//				so.pop();
//				if (so.empty() || so.top().t != LP)
//				{
//					throw invalid_argument("未匹配右括号");
//				}
//				so.pop();
//				new_val(so, v);
//			}
//			else
//			{
//				throw invalid_argument("缺少运算数");
//			}
//		}
//		else
//		{
//			v = stod(strExpression.substr(p), &q);
//			p += q;
//			new_val(so, v);
//		}
//	}
//	if (so.size() != 1 || so.top().t != VAL)
//	{
//		throw invalid_argument("非法表达式");
//	}
//
//	return so.top().v;
//}

string strOperator = { "+-*/{}" };

//bool IsOperator(char ch)
//{
//	if (strOperator.find(ch) >= 0)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
//bool Calc(string expression, double & result)
//{
//	//判断表达式是否含有其他非法字符
//
//	//先不考虑括号
//	BinaryExpression *expr = new BinaryExpression;
//	int pos = 0;
//	while ((pos = expression.find_first_of(strOperator)) != string::npos)
//	{
//		
//	}
//}