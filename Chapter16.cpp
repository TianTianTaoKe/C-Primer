#include "stdafx.h"
#include "Chapter16.h"
#include "MyTemplate.h"
#include "Sales_data.h"

void Exercise16_1()
{
	/*
	当编译器实例化一个模板时，它使用实际的模板实参代替对应的模板参数来创建出模板的一个新实例
	*/
}

void Exercise16_2()
{
	cout << Compare(1, 0) << endl;
	cout << Compare("123", "234") << endl;
}

void Exercise16_3()
{
	//Compare(Sales_data(), Sales_data());
}

void Exercise16_4()
{
	vector<int> vecInt = { 1,2,3,4,5 };
	vector<string> vecStr = { "123","456" };

	auto findIter1 = MyFind(vecInt.begin(), vecInt.end(), 3);
	if (findIter1 != vecInt.end())
	{
		cout << "找到了" << endl;
	}

	auto findIter2 = MyFind(vecStr.begin(), vecStr.end(), "123");
	if (findIter2 != vecStr.end())
	{
		cout << "找到了" << endl;
	}
}

void Exercise16_5()
{
	int a[6] = { 1,2,3,4,5,6 };
	string	vs[3] = { "123","234","345" };
	MyPrint(a);
	MyPrint(vs);
}

void Exercise16_8()
{
	/*
	因为所有的标准库容器都定义了==和!=运算符，但其中只有少数定义了<运算符。
	*/
}

void Exercise16_9()
{
	/*
	类模板是用来生成类的蓝图的
	函数模板是一个公式，可用来生成针对特定类型的函数版本
	*/
}

void Exercise16_10()
{
	/*
	提供显式模板实参列表，它们被绑定到模板参数。编译器使用这些模板实参来实例化出特定的类
	*/
}

void Exercise16_11()
{
	/*
	直接使用ListItem是错误的，应该使用ListItem<elemType>,类内的List<elemType>可简化为List
	*/
}

void Exercise16_13()
{
	/*
	由于函数模板的实例化只处理特定类型，每个BlobPtr实例与用相同类型实例化的运算符建立一对一的关系即可
	*/
}

void Exercise16_14()
{
	Screen<3, 5> myScreen;
	myScreen.display(cout);
	myScreen.move(4, 0).set('#').display(cout);
	
	Screen<5, 5> nextScreen('X');
	nextScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	nextScreen.display(cout);
	cout << endl;

	const Screen<3, 5> blank;
	myScreen.set('#').display(cout);
	cout << endl;
	blank.display(cout);
	cout << endl;

	myScreen.clear('Z').display(cout);
	cout << endl;
	myScreen.move(4, 0);
	myScreen.set('#');
	myScreen.display(cout);
	cout << endl;
	myScreen.clear('Z').display(cout);
	cout << endl;

	Screen<3, 5> temp = myScreen.move(4, 0);
	temp.set('#');
	myScreen.display(cout);
	cout << endl;
}

void Exercise16_15()
{
	Screen<3, 5> myScreen;
	cin >> myScreen;
	cout << myScreen;
}

void Exercise16_16()
{
	Vec<string> strVec1{"1","2","3","4"};
	Vec<string> strVec2{"1","2","3","5"};
	cout << *strVec1.begin() << endl;
	cout << *strVec2.begin() << endl;

	cout << (strVec1 == strVec2) << endl;
	cout << (strVec1 < strVec2) << endl;
	cout << (strVec1 > strVec2) << endl;
}

void Exercise16_17()
{
	/*
	当用来声明模板参数时，typename和class是等价的。
	在模板类型参数上使用作用域运算符访问::来访问其成员时，为了指明访问的是类型成员，需要在名字前使用typename关键字
	*/
}

void Exercise16_18()
{
	/*
	(a) U前面需要加typename template <typename T,typename U,typename V> void f1(T,U,V);
	(b) 在作用域中模板参数名不能重用 template <typaname T> T f2(int & t);
	(c) 模板定义时才能指定 template <typename T> T foo(T,unsign int *);
	(d) 未指定函数模板返回类型 template <typename T> void f4 (T,T);
	(e) 合法，在模板作用域中，类型参数Ctype屏蔽了之前定义的类型别名Ctype
	*/
}

void Exercise16_19()
{
	vector <int> vi = {1,2,3,4,5};
	print(vi);
}

void Exercise16_20()
{
	vector <int> vi = {1,2,3,4,5};
	print2(vi);
}

void Exercise16_23()
{
	/*
	当shared_ptr的引用计数变为0，需要释放资源时，才会调用删除器进行资源释放。Exercise12_27函数结束时，textQuery生命周期结束，引用计数为0，释放资源。
	*/
}

void Exercise16_25()
{
	/*
	1.extern 表明不在本文件中生成实例化代码
	2.使用Sales_data实例化vector，在其他文件中可以使用extern声明此实例，使用此定义
	*/
}

void Exercise16_26()
{
	/*
	不能，显示实例化vector<NoDefault>时会实例化所有的成员函数，包括接受容器大小参数的构造函数。这个构造函数会使用元素
	类型的默认构造函数，而NoDefault没有默认构造函数。
	*/
}

void Exercise_27()
{
	/*
	a.Stack对char的实例化
	b.stack对double的实例化
	c.stack对int的实例化
	d.没有，已经有对char的实例化
	e.没有，已经有对char的实例化
	f.stack对string的实例化
	*/
}

void Exercise16_30()
{
	BlobTemp<string> b1;
	cout << b1.size() << endl;
	{
		BlobTemp<string> b2 = {"a","an","the"};
		b1 = b2;
		b2.push_back("about");
		cout << b1.size() << ";" << b2.size() << endl;
	}
	cout << b1.size() << endl;
	for (int i = 0;i<b1.size();++i){
		cout << b1.at(i) << endl;
	}
	cout << endl << endl;

	UP<int> u1(new int(42));
	cout << *u1 << endl;
	UP<int> u2(u1.release());
	cout << *u2 << endl;
}

void Exercise16_31()
{
	/*
	unique_ptr是编译时绑定删除器。删除器可直接保存在unique_ptr对象中。通过这种方式避免了间接调用删除器的运行时开销，
	而编译时还可以将自定义的删除器编译为内联形式
	*/
}