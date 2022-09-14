#include "stdafx.h"
#include "Chapter16.h"
#include "MyTemplate.h"
#include "Sales_data.h"
#include "X.h"

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

void Exercise16_13()
{
    /*
    ���ں���ģ���ʵ����ֻ�����ض����ͣ�ÿ��BlobPtrʵ��������ͬ����ʵ���������������һ��һ�Ĺ�ϵ����
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
    ����������ģ�����ʱ��typename��class�ǵȼ۵ġ�
    ��ģ�����Ͳ�����ʹ�����������������::���������Աʱ��Ϊ��ָ�����ʵ������ͳ�Ա����Ҫ������ǰʹ��typename�ؼ���
    */
}

void Exercise16_18()
{
    /*
    (a) Uǰ����Ҫ��typename template <typename T,typename U,typename V> void f1(T,U,V);
    (b) ����������ģ��������������� template <typaname T> T f2(int & t);
    (c) ģ�嶨��ʱ����ָ�� template <typename T> T foo(T,unsign int *);
    (d) δָ������ģ�巵������ template <typename T> void f4 (T,T);
    (e) �Ϸ�����ģ���������У����Ͳ���Ctype������֮ǰ��������ͱ���Ctype
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
    ��shared_ptr�����ü�����Ϊ0����Ҫ�ͷ���Դʱ���Ż����ɾ����������Դ�ͷš�Exercise12_27��������ʱ��textQuery�������ڽ��������ü���Ϊ0���ͷ���Դ��
    */
}

void Exercise16_25()
{
    /*
    1.extern �������ڱ��ļ�������ʵ��������
    2.ʹ��Sales_dataʵ����vector���������ļ��п���ʹ��extern������ʵ����ʹ�ô˶���
    */
}

void Exercise16_26()
{
    /*
    ���ܣ���ʾʵ����vector<NoDefault>ʱ��ʵ�������еĳ�Ա��������������������С�����Ĺ��캯����������캯����ʹ��Ԫ��
    ���͵�Ĭ�Ϲ��캯������NoDefaultû��Ĭ�Ϲ��캯����
    */
}

void Exercise_27()
{
    /*
    a.Stack��char��ʵ����
    b.stack��double��ʵ����
    c.stack��int��ʵ����
    d.û�У��Ѿ��ж�char��ʵ����
    e.û�У��Ѿ��ж�char��ʵ����
    f.stack��string��ʵ����
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
    unique_ptr�Ǳ���ʱ��ɾ������ɾ������ֱ�ӱ�����unique_ptr�����С�ͨ�����ַ�ʽ�����˼�ӵ���ɾ����������ʱ������
    ������ʱ�����Խ��Զ����ɾ��������Ϊ������ʽ
    */
}

void Exercise16_32()
{
    /*
    ��һ������ģ�壬���������ú���ʵ�����ƶ���ģ���������Щģ�����ʵ�������İ汾�뺯������Ӧ������ƥ��İ汾
    */
}

void Exercise16_33()
{
    /*
    1.constת�������Խ�һ����constָ������ô��ݸ�constָ������õ��β�
    2.���������ָ���ת������������ββ����������ͣ����Զ�����������͵�ʵ��
    Ӧ��������ָ��ת��
    */ 
}

void Exercise16_34()
{
    /*
    �β����������鲻��ת��Ϊָ��
    ��һ�����������鳤�Ȳ�ͬ���������Ͳ�һ�����Ƿ�
    �ڶ������������鳤����ͬ������һ�����Ϸ�
    */ 
}

void Exercise16_35()
{
    /*
    a.�Ϸ���T�ƶ�Ϊint��charת��Ϊint
    b.�Ϸ���T�ƶ�Ϊdouble��floatת��Ϊint
    c.�Ϸ���c��'c'����char
    d.���Ϸ���d��fouble��f��float
    */ 
}

void Exercise16_36()
{
    /*
    a.�Ϸ���TΪint *
    b.�Ϸ���T1��T2��Ϊint *
    c.�Ϸ���TΪconst int*
    d.�Ϸ���T1��T2��Ϊconst int*
    e.���Ϸ� p1��p2���Ͳ�ͬ
    f.��ͬ��T1Ϊint*��T2Ϊconst int*    
    */ 
}

void Exercise16_37()
{
    /*
    ���ԣ���ʾָ��ģ��ʵ�μ���
    */
}

void Exercise16_38()
{
    /*
    �ڵ���make_shareʱ����ʱ��������������ʾ����ֵ��ʼ������ʱ�����Ĳ�����ά���Ķ�̬
    ��������Ͳ�ֱ����ء���make_share<string>(10,'9')����ֵΪ'999999999'��string��
    ��˱������޷��Ӳ����ƶ�ģ��ʵ�Σ���Ҫ��ʾָ��ģ��ʵ�Ρ�
    */
}

void Exercise16_39()
{
    compare<const char *>("123","1234");
}

void Exercise16_40()
{
    /*
    �����Ϸ�������Ԫ�����ͱ���֧��+�������*beg+0����ֵ���������ͱ��ƶ�ΪԪ��
    ���͵ĳ�������
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
    construct�����ڴ�ռ��д���������ڶ���������һ����ֵ����п���������
    ����std::move��һ����ֵת��Ϊ��ֵ���ã�construct�����string���ƶ�����
    �����������˲���Ҫ�Ŀ�������
    */
}

void g(int && i,int &j)
{
    cout << i << " " << j << endl;
}

void Exercise16_47()
{
    int i = 0;
    flip(g,i,42);
}

void Exercise16_49()
{
    /*
    g(42) g(T)
    g(p) g(T*)
    g(ci) g(T)
    g(p2) g(T*)
    f(42) f(T)
    f(p) f(const T*)
    f(ci) f(T)
    f(p2) f(const T*)  
    */
}

void Exercise16_50()
{
    int i = 42,*p = &i;
    const int ci = 0,*p2 = &ci;
    gg(42);
    gg(p);
    gg(ci);
    gg(p2);
    f(42);
    f(p);
    f(ci);
    f(p2);
}

void Exercise16_51()
{
    /*
    3,2,1,0
    3,2,1,0
    */
}

void Exercise16_52()
{
    int i = 0;double d = 3.14;string s = "123";
    foo(i,s,42,d);
    foo(s,42,"hi");
    foo(d,s);
    foo("hi");
}

void Exercise16_53()
{
    int i = 0;
    string s = "hi";
    print3(cout,i);
    print3(cout,i,s);
    print3(cout,i,s,4.3,'a',"adf");
}

void Exercise16_54()
{
    /*
    ���뱨��
    */
}

void Exercise16_55()
{
    /*
    �������print(cout ,i,s,42),����Ϊ
    print(cout,s,42)
    print(cout,s)--��ʱ�ǿɱ�����汾���������������У��޷����ã�����
    print(cout) -- ���뱨��
    */
}

void Exercise16_56()
{
    int a = 100;
    Sales_data book("1234",5,1,2);
    ErrorMsg(cout,"123",4,'a',&a,book,&book);
}

void Exercise16_57()
{
    /*
    �ð汾��Ҫ�����������ͬ���͡�
    */
}

void Exercise16_58()
{
    StrVec strvec;
    strvec.emplace_back("End");
    strvec.emplace_back(3,'!');
    print(strvec);

    Vec<string>svec;
    svec.emplace_back("End");
    svec.emplace_back(3,'!');
    print(svec);
}

void Exercise16_59()
{
    /*
    ����S��һ����ֵ����������չ��������������ʽ���ݸ�construct��
    std::forward<string>(s)
    forward<string>�Ľ��������string&����ˣ�construct���õ�һ����ֵ����ʵ�Σ����������˲������ݸ�string�Ŀ������캯����������Ԫ�ء�
    */
}

void Exercise16_60()
{
    /*
    make_shared�Ĺ�����������emplace_back��
    �����ܲ�������������չ��ת����new����Ϊvector�ĳ�ʼ������
    */
}

void Exercise16_61()
{
    vector<string> vs = {"Hello","World","!"};
    BlobTemp<string> b3(vs.begin(),vs.end());
    cout << b3.size() << endl;
    for (size_t i = 0; i < b3.size(); ++i)
    {
        cout << b3.at(i)<<" ";
    }

    cout << endl
         << endl;
    string as[3] = {"This", "is", "end"};
    BlobTemp<string> b4(as, as + 3);
    cout << b4.size() << endl;

    for (size_t i = 0; i < b4.size(); ++i)
    {
        cout << b4.at(i) << " ";
    }
    cout << endl
         << endl;
}