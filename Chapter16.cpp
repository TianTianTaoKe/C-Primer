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