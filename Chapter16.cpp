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

void Exercise16_32()
{
    /*
    对一个函数模板，编译器利用函数实参来推断器模板参数，这些模板参数实例化出的版本与函数调用应该是最匹配的版本
    */
}

void Exercise16_33()
{
    /*
    1.const转换：可以将一个非const指针或引用传递给const指针或引用的形参
    2.数组或函数到指针的转换：如果函数形参不是引用类型，可以对数组或函数类型的实参
    应用正常的指针转换
    */ 
}

void Exercise16_34()
{
    /*
    形参是引用数组不会转换为指针
    第一个，两个数组长度不同，所以类型不一样，非法
    第二个，两个数组长度相同，类型一样，合法
    */ 
}

void Exercise16_35()
{
    /*
    a.合法，T推断为int，char转化为int
    b.合法，T推断为double，float转化为int
    c.合法，c和'c'都是char
    d.不合法，d是fouble，f是float
    */ 
}

void Exercise16_36()
{
    /*
    a.合法，T为int *
    b.合法，T1，T2都为int *
    c.合法，T为const int*
    d.合法，T1，T2都为const int*
    e.不合法 p1和p2类型不同
    f.合同，T1为int*，T2为const int*    
    */ 
}

void Exercise16_37()
{
    /*
    可以，显示指定模板实参即可
    */
}

void Exercise16_38()
{
    /*
    在调用make_share时，有时不给出参数，表示进行值初始化。有时给出的参数与维护的动态
    对象的类型不直接相关。如make_share<string>(10,'9')创建值为'999999999'的string，
    因此编译器无法从参数推断模板实参，需要显示指定模板实参。
    */
}

void Exercise16_39()
{
    compare<const char *>("123","1234");
}

void Exercise16_40()
{
    /*
    函数合法，序列元素类型必须支持+运算符，*beg+0是右值，返回类型被推断为元素
    类型的常量引用
    */
}

void Exercise16_41()
{
    auto a = sum(1,1);
    auto b = sum(1,1.1);
    auto c = sum(1,1.1f);
    cout << a << " " << b << " " << c << " " << endl;
}

void Exercise16_42()
{
    /*
    a.T int &,val int &
    b.T const int &,val const int &
    c.T int,val int &&
    */
}

void Exercise16_43()
{
    /*
    T int &,val int &
    */
}

void Exercise16_44()
{
    /*
    a.int,int
    b.const int,cosnt int
    c.int,int

    a.int,const int &
    b.int,const int &
    c.int,const int &
    */
}

void Exercise16_45()
{
    /*
    a.T int,val int && 
    b.T int &,val int &
    */
}

void Exercise16_46()
{
    /*
    construct在新内存空间中创造对象。若第二个参数是一个左值则进行拷贝动作。
    但是std::move将一个左值转换为右值引用，construct会调用string的移动构造
    函数，避免了不必要的拷贝操作
    */
}

static void g(int && i,int &j)
{
    cout << i << " " << j << endl;
}

void Exercise16_47()
{
    int i = 0;
    flip(g,i,42);
}