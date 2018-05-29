#pragma once

#include <list>
#include <deque>
#include <vector>
#include <string>
#include <deque>
#include <iostream>
#include <forward_list>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stack>


using std::list;
using std::deque;
using std::vector;
using std::string;
using std::deque;
using std::cin;
using std::cout;
using std::endl;
using std::forward_list;
using std::ifstream;
using std::istringstream;
using std::invalid_argument;
using std::stack;
typedef vector<int> vecint;
typedef vector<string> vecstr;



//9.4
bool Exercise9_4(vecint::const_iterator begin, vecint::const_iterator end, int val);

//9.5
vecint::iterator  Exercise9_5(vecint::iterator begin, vecint::iterator end, int val);

//9.14
void Exercise9_14();

//9.15
bool Exercise9_15(vecint &a, vecint&b);

//9.16
bool Exercise9_16(list<int>& iLIst, vecint& iVec);

//9.18
void Exercise9_18();

//9.19
void Exercise9_19();

void Exercise9_20();

void Exercise9_22();

void Exercise9_26();

void Exercise9_27();

void Exercise9_28(forward_list<string> &strFlist,string &findStr,string &addStr);


void Exercise9_38();

void Exercise9_42();

void Exercise9_43(string &s, string oldVal, string  newVal);

void Exercise9_44(string &s, string oldVal, string  newVal);

void Exercise9_45(string &s, string prefix, string suffix);

void Exercise9_46(string &s, string prefix, string suffix);

void Exercise9_47();

void Exercise9_49(ifstream &in);

int Exercise9_50(vecstr & strVec);

//9.51

class data
{
private:
	unsigned year;
	unsigned month;
	unsigned day;
	unsigned GetMonth(string &month);
public:
	data() = default;
	~data() = default;
	data(string ds);
	int GetYear(string &yeat);
};


//9.52

//double GetCalcResult(double left, double right, char chOperator);
//class Expression
//{
//public:
//	Expression(){};
//	~Expression(){};
//	int exprType;
//	virtual double ReturnResult() = 0;
//};
//
//class NoOperatorExp : public Expression
//{
//public:
//	NoOperatorExp(double value) :operand(value),exprType(1){};
//	~NoOperatorExp(){};
//	double ReturnResult(){ return operand; }
//private:
//	double operand;
//};
//
//class BinaryExpression : public Expression
//{
//public:
//	BinaryExpression():exprType(1){};
//	~BinaryExpression(){};
//private:
//	Expression* leftExp;
//	Expression* rightExp;
//	char chOperator;
//	double ReturnResult(){ return GetCalcResult(leftExp->ReturnResult(), rightExp->ReturnResult(), chOperator); }
//	
//};
//
//bool IsOperator(char ch);
//
//int Calc(string expression);