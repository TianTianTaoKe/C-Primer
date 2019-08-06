#include "stdafx.h"

#include "X.h"
#include "Chapter15.h"

void Exercise15_1()
{
	/*
	虚成员是类中virtual修饰的成员，基类希望派生类重定义该成员。除了构造函数外，任何非static成员函数
	都可以是虚成员
	*/
}

void Exercise15_2()
{
	/*
	protected表示受保护的，可以被该类的成员，友元和派生类访问，不可以被该类的普通用户访问
	private只能被基类的成员和友元访问，派生类不能访问
	*/
}

void Exercise15_4()
{
	/*
	a:错误 类不能继承自己
	b:正确
	c:错误，声明时不能包含派生列表
	*/
}

void Exercise15_6()
{
	Quote quote(string("qqqq"), 100);
	BulKQuote bulkQuote(string("wwww"), 100, 10, 0.1);
	PrintTotal(cout, quote, 20);
	PrintTotal(cout, bulkQuote, 20);
}

void Exercise15_8()
{
	/*
	静态类型：是变量声明时的类型或表达式生成的类型，编译时已知
	动态类型：变量或表达式表示的内存中的对象的类型，运行时才可知
	*/
}

void Exercise15_9()
{
	BulKQuote bulkQuote("",10,1,0.1);
	Quote* pQuote = &bulkQuote;
	Quote& rQuote = bulkQuote;
	PrintTotal(cout, bulkQuote, 1);
}

void Exercise15_10()
{
	/*
	再要求使用基类型对象的地方，可以使用派生类型的对象来代替
	*/
}

void Exercise15_12()
{
	/*
	有必要
	override 指明派生类中的虚函数
	final 不允许后续的派生类来覆盖这个函数	
	*/
}

void Exercise15_13()
{
	/*
	derived中print函数中的调用的print函数没有使用作用域运算符，会导致无限递归
	*/
}

void Exercise15_14()
{
	/*
	a. 基类的print
	b. 派生类的print
	c. 基类的name
	d. 基类的name
	e. 基类的print
	f. 派生类的print
	*/
}

void Exercise15_17()
{
	//DiscQuote discQuote;
}

void Exercise15_18()
{
	/*
	只有d1和dd1才能够赋值，因为只有当派生类公有地继承基类时，用户代码才能使用派生类向
	基类的转换
	*/
}

void Exercise15_19()
{
	/*
	Derivde_from_Private这个类的函数不合法
	1.派生类的成员函数和友元永远能使用派生类向基类的转换
	2.如果派生类继承基类的方式是公有的或者受保护的，则派生类的派生类可以使用派生类向基类的
	转换，否则不行
	*/
}

void Exercise15_20()
{
	PubDerv d1;
	PrivDerv d2;
	ProtDerv d3;
	DerivedFromPublic dd1;
	DerivedFromPrivate dd2;
	DerivedFromProtected dd3;
	Base base;
	Base* p;
	p = &d1;
	//p = &d2;
	//p = &d3;
	p = &dd1;
	//p = &dd2;
	//p = &dd3;
}