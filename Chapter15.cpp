#include "stdafx.h"

#include "X.h"
#include "Chapter15.h"

void Exercise15_1()
{
	/*
	���Ա������virtual���εĳ�Ա������ϣ���������ض���ó�Ա�����˹��캯���⣬�κη�static��Ա����
	�����������Ա
	*/
}

void Exercise15_2()
{
	/*
	protected��ʾ�ܱ����ģ����Ա�����ĳ�Ա����Ԫ����������ʣ������Ա��������ͨ�û�����
	privateֻ�ܱ�����ĳ�Ա����Ԫ���ʣ������಻�ܷ���
	*/
}

void Exercise15_4()
{
	/*
	a:���� �಻�ܼ̳��Լ�
	b:��ȷ
	c:��������ʱ���ܰ��������б�
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
	��̬���ͣ��Ǳ�������ʱ�����ͻ���ʽ���ɵ����ͣ�����ʱ��֪
	��̬���ͣ���������ʽ��ʾ���ڴ��еĶ�������ͣ�����ʱ�ſ�֪
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
	��Ҫ��ʹ�û����Ͷ���ĵط�������ʹ���������͵Ķ���������
	*/
}

void Exercise15_12()
{
	/*
	�б�Ҫ
	override ָ���������е��麯��
	final ������������������������������	
	*/
}

void Exercise15_13()
{
	/*
	derived��print�����еĵ��õ�print����û��ʹ����������������ᵼ�����޵ݹ�
	*/
}

void Exercise15_14()
{
	/*
	a. �����print
	b. �������print
	c. �����name
	d. �����name
	e. �����print
	f. �������print
	*/
}

void Exercise15_17()
{
	//DiscQuote discQuote;
}

void Exercise15_18()
{
	/*
	ֻ��d1��dd1���ܹ���ֵ����Ϊֻ�е������๫�еؼ̳л���ʱ���û��������ʹ����������
	�����ת��
	*/
}

void Exercise15_19()
{
	/*
	Derivde_from_Private�����ĺ������Ϸ�
	1.������ĳ�Ա��������Ԫ��Զ��ʹ��������������ת��
	2.���������̳л���ķ�ʽ�ǹ��еĻ����ܱ����ģ�������������������ʹ��������������
	ת����������
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