#include "stdafx.h"

#include "X.h"
#include "TextQuery.h"
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

void Exercise15_23()
{
	/*
	DI类的fun函数改为int fcn()
	p2->fcn(42) 会报错
	*/
}

void Exercise15_24()
{
	/*
	基类需要虚析构函数
	虚析构函数可以为空。虚析构函数必须清除本类中定义的数据成员
	*/
}

void Exercise15_25()
{
	/*
	因为Disc_Quote的默认构造函数会调用Quote的默认构造函数。
	如果去掉，编译器无法合成Bulk_Quote的默认构造函数
	*/
}

void Exercise15_26()
{
	BulKQuote bulkQuote("1111", 10.0, 10, 0.1);
	BulKQuote bulkQuote2(bulkQuote);
	BulKQuote bulkQuote3("2222", 10.0, 10, 0.1);
	bulkQuote3 = bulkQuote;
}

void Exercise15_28()
{
	vector <Quote> vecQuote;
	for (int i = 0;i<5;++i)
	{
		vecQuote.push_back(BulKQuote("1111", 10, 10, 0.1));
	}

	int sum = 0;
	for (vector<Quote>::iterator  iter = vecQuote.begin();iter != vecQuote.end();++iter)
	{
		sum += iter->NetPrice(15);
	}

	cout << sum << endl;
}

void Exercise15_29()
{
	vector <shared_ptr<Quote> > vecQuote;
	for (int i = 0; i < 5; ++i)
	{
		vecQuote.push_back(make_shared<BulKQuote>("1111", 10, 10, 0.1));
	}

	int sum = 0;
	for (vector<shared_ptr<Quote>>::iterator iter = vecQuote.begin(); iter != vecQuote.end(); ++iter)
	{
		sum += (*iter)->NetPrice(15);
	}

	cout << sum << endl;
	/*
	结果不一样，当通过Quote的对象调用NetPrice时不实行动态绑定，调用的时Quote中的版本，而通过
	Quote的指针调用NetPrice时实行动态绑定，实际指向BulkQuote类中定义的版本
	*/
}

void Exercise15_30()
{
	Basket basket;
	for (int i = 0; i < 75; ++i)
	{
		basket.AddItem(BulKQuote("1111", 10, 10, 0.1));
	}
	basket.TotalReceipt(cout);
}

void Exercise15_31()
{
	/*
	a.共创建了12个对象6个QueryBase对象和对应的句柄，分别是3个WordQuery对象，一个NotQuery对象，一个
	AndQuery对象，一个OrQuery对象
	b.与a相同
	c.创建了14个对象，7个QueryBase对象和对应的句柄，4个WordQuery对象，2个AndQuery对象，一个OrQuery
	对象
	*/
}

void Exercise15_32()
{
	/*
	Query类未定义自己的拷贝/移动控制成员，当进行这些操作时，执行默认语义。而其唯一的数据成员是
	Query_Base的shared_ptr，因此当拷贝、移动、赋值或销毁一个Query对象时，会调用shared_ptr的对应
	控制成员。而shared_ptr的控制成员调用Query_Base的控制成员时，由于指向的可能是Query_Base的派生
	类对象，因此可能在类层次中进行相应的拷贝/移动操作，调用Query_Base的派生类的相应控制成员。
	*/
}

void Exercise15_33()
{
	/*
	Query_Base是一个虚基类不允许直接声明其对象。当期派生类对象进行这些操作时，会调用Query_Base的相应
	控制成员。而QueryBase没有定义自己的拷贝/移动控制成员，实际上它没有任何数据成员，无须定义这些操作，
	因此进行这些操作时执行默认语义，什么也不会发生。
	*/
}

void Exercise15_34()
{
	/*	
	a.
	WordQuery(const string& s)
	Query(const string& s)
	WordQuery(const string& s)
	Query(const string& s)
	WordQuery(const string& s)
	Query(const string& s)
	BinaryQuery(const Query& l, const Query& r, std::string s)
	AndQuery(const Query& left, const Query& right)
	Query(shared_ptr<QueryBase> query)
	BinaryQuery(const Query& l, const Query& r, std::string s)
	OrQuery(const Query& left, const Query& right)
	Query(shared_ptr<QueryBase> query)
	b.
	Query BinaryQuery Query WordQuery Query BinaryQuery Query WordQuery Query WordQuery
	c.
	Query OrQuery AndQuery WordQuery
	*/
}

void Exercise15_35()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q;
}