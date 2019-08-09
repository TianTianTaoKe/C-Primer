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

void Exercise15_23()
{
	/*
	DI���fun������Ϊint fcn()
	p2->fcn(42) �ᱨ��
	*/
}

void Exercise15_24()
{
	/*
	������Ҫ����������
	��������������Ϊ�ա�����������������������ж�������ݳ�Ա
	*/
}

void Exercise15_25()
{
	/*
	��ΪDisc_Quote��Ĭ�Ϲ��캯�������Quote��Ĭ�Ϲ��캯����
	���ȥ�����������޷��ϳ�Bulk_Quote��Ĭ�Ϲ��캯��
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
	�����һ������ͨ��Quote�Ķ������NetPriceʱ��ʵ�ж�̬�󶨣����õ�ʱQuote�еİ汾����ͨ��
	Quote��ָ�����NetPriceʱʵ�ж�̬�󶨣�ʵ��ָ��BulkQuote���ж���İ汾
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