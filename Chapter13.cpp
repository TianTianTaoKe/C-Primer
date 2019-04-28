#include "stdafx.h"
#include "Chapter13.h"
#include "X.h"
#include "numbered.h"


void f1(X x){}

void f2(X& x){}

void Exercise13_13()
{
	cout << "�ֲ�����" << endl;
	X x;
	cout << endl;

	cout << "�����ò�������" << endl;
	f1(x);
	cout << endl;

	cout << "���ò�������" << endl;
	f2(x);
	cout << endl;

	cout << "��̬����" << endl;
	X* px = new X;
	cout << endl;

	cout << "��ӵ�������" << endl;
	vector<X> vx;
	vx.push_back(x);
	cout << endl;

	cout << "�ͷŶ�̬�����ڴ�" << endl;
	delete px;
	px = nullptr;
	cout << endl;

	cout << "��ӳ�ʼ���͸�ֵ" << endl;
	X y = x;
	y = x;
	cout << endl;

	cout << "�������" << endl;
}

void f3(numbered n)
{
	cout << n.mysb << endl;
}

void f4(const numbered & n)
{
	cout << n.mysb << endl;
}

void Exercise13_17()
{
	numbered a, b = a, c = b;
	f3(a); f3(b); f3(c);
	f4(a); f4(b); f4(c);
}

void f(Employee& s)
{
	cout << s.get_name() << ":" << s.get_mysn() << endl;
}

void Exercise13_18()
{
	Employee a("��"), b = a, c;
	c = b;
	f(a); f(b); f(c);
}

void Exercise13_22()
{
	HasPtr h("111!!!");
	HasPtr h2(h);
	HasPtr h3 = h;
	h2 = "222!!!";
	h3 = "333!!!";
	cout << *h << endl;
	cout << *h2 << endl;
	cout << *h3 << endl;
}