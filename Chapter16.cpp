#include "stdafx.h"
#include "Chapter16.h"
#include "MyTemplate.h"
#include "Sales_data.h"

void Exercise16_1()
{
	/*
	��������ʵ����һ��ģ��ʱ����ʹ��ʵ�ʵ�ģ��ʵ�δ����Ӧ��ģ�������������ģ���һ����ʵ��
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
		cout << "�ҵ���" << endl;
	}

	auto findIter2 = MyFind(vecStr.begin(), vecStr.end(), "123");
	if (findIter2 != vecStr.end())
	{
		cout << "�ҵ���" << endl;
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
	��Ϊ���еı�׼��������������==��!=�������������ֻ������������<�������
	*/
}

void Exercise16_9()
{
	/*
	��ģ�����������������ͼ��
	����ģ����һ����ʽ����������������ض����͵ĺ����汾
	*/
}

void Exercise16_10()
{
	/*
	�ṩ��ʽģ��ʵ���б����Ǳ��󶨵�ģ�������������ʹ����Щģ��ʵ����ʵ�������ض�����
	*/
}

void Exercise16_11()
{
	/*
	ֱ��ʹ��ListItem�Ǵ���ģ�Ӧ��ʹ��ListItem<elemType>,���ڵ�List<elemType>�ɼ�ΪList
	*/
}