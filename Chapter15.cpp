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

}