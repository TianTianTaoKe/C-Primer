#pragma once

struct X
{
	X(){ cout << "X()" << endl; }
	X(const X&){ cout << "X(const &X)" << endl; }
	X& operator=(const X& rhs) { cout << "X& operator=(const& rhs)" << endl; return *this; }
	~X(){ cout << "~X()" << endl; }
};

class Employee
{
public:
	Employee(){ mysn = sn++; }
	Employee(const string& s) :name(s){ mysn = sn++; }
	Employee(const Employee& rhs) :name(rhs.name){ mysn = sn++; }
	const Employee& operator=(const Employee& rhs){ name = rhs.name; return *this; }
	const string& get_name(){ return name; }
	int get_mysn(){ return mysn; }
protected:
private:
	static int sn;
	string name;
	int mysn;
};
//HasPtr----------------------------------------------------------------------------------
class HasPtr
{
public:
	HasPtr(const string& s = string()):
		ps(new string(s)),i(0),use(new size_t(1)){}
	HasPtr(const HasPtr& p) :
		ps(p.ps), i(p.i), use(p.use){
		++*use;
	}
	HasPtr& operator=(const HasPtr&);
	HasPtr& operator=(HasPtr&&);
	HasPtr& operator=(const string&);
	//HasPtr& operator=(HasPtr rhs)
	//{
	//	swap(*this, rhs);
	//	return *this;
	//}
	string & operator*();
	bool operator<(const HasPtr&) const;
	~HasPtr();

	friend void swap(HasPtr& lhs, HasPtr& rhs);
protected:
private:
	string * ps;
	int i;
	size_t * use;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	cout << "交换 " << *lhs.ps << "和" << *rhs.ps << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}
//TreeNode-------------------------------------------------------------------------------
class TreeNode
{
public:
	//TreeNode() :value(""), count(1), left(nullptr), right(nullptr){}
	TreeNode(const string & s = string(), TreeNode* lchild = nullptr, TreeNode* rchild = nullptr)
		:value(s),count(1),left(lchild), right(rchild){}

	TreeNode(const TreeNode& );

	void CopyTree();
	int ReleaseTree();
	~TreeNode();
protected:
public:
	string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree
{
public:
	//BinStrTree() :root(nullptr){}
	BinStrTree(TreeNode* t = nullptr) :root(t){}
	BinStrTree(const BinStrTree&);
	~BinStrTree();

protected:
public:
	TreeNode *root;
};

class Folder;
class Message
{
	friend void swap(Message &, Message&);
public:
	explicit Message(const string& s = "") :content(s){}
	Message(const Message&);
	Message(Message &&);	
	Message& operator=(const Message&);
	Message& operator =(Message &&);
	~Message();

	void save(Folder&);
	void remove(Folder&);

	void addFldr(Folder* pf){ folders.insert(pf); };
	void remFldr(Folder* pf){ folders.erase(pf); };
protected:
private:
	string content;
	set<Folder* >folders;
	void add_to_Folders(const Message&);
	void move_Folders(Message*);
	void remove_from_Folders();
};

class Folder
{
public:
	Folder(){}
	Folder(const Folder&);
	~Folder();
	Folder& operator=(const Folder&);
	void addMsg(Message* msg){ msgs.insert(msg); };
	void remMsg(Message* msg){ msgs.erase(msg); };
protected:
private:
	set<Message* >msgs;
	void add_to_Message(const Folder&);
	void remove_from_Message();
};

class StrVec
{
public:
	typedef int size_type;
	friend bool operator==(const StrVec& lhs, const StrVec& rhs);
	friend bool operator!=(const StrVec& lhs, const StrVec& rhs);
	friend bool operator>(const StrVec& lhs, const StrVec& rhs);
	friend bool operator>=(const StrVec& lhs, const StrVec& rhs);
	friend bool operator<(const StrVec& lhs, const StrVec& rhs);
	friend bool operator<=(const StrVec& lhs, const StrVec& rhs);
	StrVec():
		element(nullptr), first_free(nullptr), cap(nullptr){}
	StrVec(initializer_list<string> li);
	StrVec(const StrVec&);
	StrVec(StrVec&&) throw();
	StrVec& operator=(const StrVec&);
	StrVec& operator=(StrVec &&)throw();
	StrVec& operator=(initializer_list<string> il);
	string& operator[](size_t n){ return element[n]; }
	const string& operator[](size_t n) const{ return element[n]; }
	~StrVec();
	void push_back(const string&);
	size_t size() const{ return first_free - element; }
	size_t capacity() const{ return cap - element; }
	string* begin() const{ return element; }
	string* end() const{ return first_free; }
	void reserve(size_t n);
	void resize(size_t n);
	void resize(size_t n, const string &);
	template<class... Args>
	void emplace_back(Args&&... args);
	string &at(int i);
	const string &at(int i) const;
protected:
private:
	string *element;
	string *first_free;
	string *cap;
	static allocator<string> alloc;

	void chk_n_alloc(){ if (size() == capacity()) reallocate(); }
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	void reallocate(size_t newcapacity);
};

inline
StrVec::StrVec(initializer_list<string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	element = newdata.first;
	first_free = cap = newdata.second;
}

inline
StrVec::StrVec(StrVec &&s) throw() :
element(s.element), first_free(s.first_free), cap(s.cap)
{
	s.element = s.first_free = s.cap = nullptr;
}

inline
StrVec& StrVec::operator=(StrVec && rhs) throw()
{
	if (this != &rhs)
	{
		free();
		element = rhs.element;
		first_free = rhs.first_free;
		cap = rhs.cap;

		rhs.element = rhs.first_free = rhs.cap = nullptr;
	}

	return *this;
}

template<class... Args>
inline
void StrVec::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++,std::forward<Args>(args)...);
}

class MyString
{
	friend ostream& operator<<(ostream&, MyString&);
	friend ostream& print(ostream&, MyString&);
	friend bool operator==(const MyString& lhs, const MyString& rhs);
	friend bool operator!=(const MyString& lhs, const MyString& rhs);
	friend bool operator<(const MyString& lhs, const MyString& rhs);
	friend bool operator<=(const MyString& lhs, const MyString& rhs);
	friend bool operator>(const MyString& lhs, const MyString& rhs);
	friend bool operator>=(const MyString& lhs, const MyString& rhs);
public:
	MyString() :sz(0), p(nullptr){}
	MyString(const char* cp):
		sz(strlen(cp)), p(a.allocate(sz))
	{ 
		uninitialized_copy(cp, cp + sz, p);
	}
	MyString(const MyString&s) :
		sz(s.sz), p(a.allocate(s.sz))
	{
		cout << "拷贝构造" << endl;
		uninitialized_copy(s.p, s.p + sz, p);
	}
	MyString(MyString &&s) throw() : sz(s.sz), p(s.p)
	{
		cout << "移动构造" << endl;
		s.p = nullptr;
		s.sz = 0;
	}

	MyString& operator=(const MyString&);

	MyString& operator=(MyString&&);

	~MyString() throw()
	{
		if (p)
		{
			a.deallocate(p, sz);
		}
	}

	MyString& operator=(const char*);
	MyString& operator=(const char);
	MyString& operator=(initializer_list<char>);
	char& operator[](size_t n){ return p[n]; }
	const char& operator[](size_t n) const{ return p[n]; }

	const char* begin() { return p; }
	const char* begin() const { return p; }
	const char* end(){ return p + sz; }
	const char* end() const { return p + sz; }

	size_t size() const { return sz; }
protected:
private:
	size_t sz;
	char* p;
	static allocator<char> a;
};

//Foo-------------------------------------------------------------------------------
//class Foo
//{
//public:
//	Foo sorted() && ;
//	Foo sorted() const &;
//protected:
//private:
//	vector <int> data;
//};

//Date-----------------------------------------------------------------------------
class Date
{
	friend ostream& operator<< (ostream&, const Date&);
	friend istream& operator>> (istream&, Date&);
	friend bool operator== (const Date& lhs, const Date& rhs);
	friend bool operator!= (const Date& lhs, const Date& rhs);
	friend bool operator< (const Date& lhs, const Date& rhs);
	friend bool operator<= (const Date& lhs, const Date& rhs);
	friend bool operator> (const Date& lhs, const Date& rhs);
	friend bool operator>= (const Date& lhs, const Date& rhs);
public:
	Date(){}
	Date(int y, int m, int d) :year(y), month(m), day(d){}
	Date& operator=(const string & date);
	bool IsLeapYear();

	explicit operator bool();
protected:
private:
	int year;
	int month;
	int day;
};
//IfElseThen---------------------------------------------------------------
class IfElseThen
{
public:
	IfElseThen(){}
	int operator()(int i1, int i2, int i3){ return i1 ? i2 : i3; }
};

//ReadString-----------------------------------------------------------------
class ReadString
{
public:
	ReadString(istream& is = cin) :is(is){}
	string operator()()
	{
		string line;
		if (!getline(is,line))
		{
			line = "";
		}
		return line;
	}
protected:
private:
	istream &is;
};

//IntCompare----------------------------------------------------------------
class IntCompare
{
public:
	IntCompare(int v) :val(v){}
	bool operator()(int v){ return val == v; }
protected:
private:
	int val;
};

//CheckSize
class CheckSize
{
public:
	CheckSize(int n):iChecksize(n){}

	bool operator()(const string & str) { return str.length() == iChecksize;}
private:
	int iChecksize;
};

class StrLenBetween
{
public:
	StrLenBetween(int min,int max):iMinLen(min),iMaxLen(max){}

	bool operator()(const string& str) { return str.length() >= iMinLen && str.length() <= iMaxLen; }
private:
	int iMinLen;
	int iMaxLen;
};

class StrNotShorterThan
{
public:
	StrNotShorterThan(int min):iMinLen(min){}

	bool operator()(const string& str) { return str.length() >= iMinLen; }
private:
	int iMinLen;
};

class IsShoter
{
public:
	bool operator() (const string& str1, const string & str2)
	{
		return str1.size() < str2.size();
	}
};

class PrintClass
{
public:
	void operator() (const string& str)
	{
		cout << str << " ";
	}
};

class Quote
{
public:
	Quote() = default;
	Quote(string& bookNo, double sales_price)
		:m_strBookNo(bookNo), m_dPrice(sales_price){}
	string isbn() const { return m_strBookNo; }

	Quote(const Quote& rhs)
		:m_strBookNo(rhs.m_strBookNo)
		,m_dPrice(rhs.m_dPrice)
	{
		//cout << "Quote(const Quote& rhs)" << endl;
	}

	Quote& operator=(const Quote& rhs)
	{
		m_strBookNo = rhs.m_strBookNo;
		m_dPrice = rhs.m_dPrice;
		//cout << "Quote& operator=(const Quote& rhs)" << endl;
		return *this;
	}

	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }

	virtual double NetPrice(std::size_t n) const { return n * m_dPrice; }
	virtual void Debug()
	{
		cout << "m_strBookNo:" << m_strBookNo << " m_dPrice:" << m_dPrice;
	}
	~Quote() = default;
private:
	string m_strBookNo;
protected:
	double m_dPrice = 0.0;
};

double PrintTotal(ostream& os, const Quote& item, size_t n);

class DiscQuote :public Quote
{
public:
	DiscQuote() = default;
	DiscQuote(string bookNo, double price, size_t Qty, double discount)
		:Quote(bookNo, price), m_Qty(Qty), m_discount(discount) {}

	DiscQuote(const DiscQuote& rhs)
		:Quote(rhs)
		, m_Qty(rhs.m_Qty)
		, m_discount(rhs.m_discount)
	{
		//cout << "DiscQuote(const DiscQuote& rhs)" << endl;
	}

	DiscQuote& operator=(const DiscQuote& rhs)
	{
		Quote::operator=(rhs);
		m_Qty = rhs.m_Qty;
		m_discount = rhs.m_discount;
		//cout << "DiscQuote& operator=(const DiscQuote& rhs)" << endl;
		return *this;
	}
	double NetPrice(std::size_t n) const = 0;

	virtual void Debug()
	{
		Quote::Debug();
		cout << "m_Qty:" << m_Qty << " m_discount:" << m_discount;
	}



protected:
	size_t m_Qty;
	double m_discount;
};

class BulKQuote:public DiscQuote
{
public:
	using DiscQuote::DiscQuote;

	BulKQuote(const BulKQuote& rhs)
		:DiscQuote(rhs)
	{
		//cout << "BulKQuote(const BulKQuote& rhs)" << endl;
	}

	BulKQuote& operator=(const BulKQuote& rhs)
	{
		DiscQuote::operator=(rhs);
		//cout << "BulKQuote& operator=(const BulKQuote& rhs)" << endl;
		return *this;
	}

	virtual BulKQuote* clone() const & { return new BulKQuote(*this); }
	virtual BulKQuote* clone() && { return new BulKQuote(std::move(*this)); }

	double NetPrice(std::size_t n) const override
	{
		if (n >= m_Qty)
		{
			return n * (1 - m_discount) * m_dPrice;
		}
		else
		{
			return n * m_dPrice;
		}
	}
};

class LimitedQuote :public DiscQuote
{
public:
	LimitedQuote(string bookNo, double price, size_t maxQty, double discount)
		:DiscQuote(bookNo, price, maxQty, discount) {}
	double NetPrice(std::size_t n) const override
	{
		if (n >= m_Qty)
		{
			return m_Qty * (1 - m_discount) * m_dPrice + (n - m_Qty) * m_dPrice;
		}
		else
		{
			return n * (1 - m_discount) * m_dPrice;
		}
	}
};

class Base
{
public:
	void PubMem(){}
protected:
	void ProtMem(){}
private:
	void PrivMem(){}
};

class PubDerv :public Base
{
	void MemFun(Base& b)
	{
		b = *this;
	}
};

class PrivDerv :private Base
{
	void MemFun(Base& b)
	{
		b = *this;
	}
};

class ProtDerv :protected Base
{
	void MemFun(Base& b)
	{
		b = *this;
	}
};

class DerivedFromPublic :public PubDerv
{
	void MemFun(Base& b)
	{
		b = *this;
	}
};

class DerivedFromPrivate :protected PrivDerv
{
	//void MemFun(Base& b)
	//{
	//	b = *this;
	//}
};

class DerivedFromProtected :protected ProtDerv
{
	void MemFun(Base& b)
	{
		b = *this;
	}
};

//class Figure
//{
//public:
//	Figure(double, double);
//protected:
//	double xSize, ySize;
//};
//
//class Figure_2D:public Figure
//{
//public:
//	Figure_2D(double, double);
//	virtual double area() = 0;
//	virtual double pcrimeter() = 0;
//};
//
//class Figure_3D :public Figure
//{
//public:
//	Figure_3D(double, double, double);
//	virtual double cubage() = 0;
//protected:
//	double zSize;
//};
//
//class Rectangle :public Figure_2D
//{
//public:
//	Rectangle(double, double);
//	virtual double area();
//	virtual double pcrimeter();
//};
//
//class Circle :public Figure_2D
//{
//public:
//	Circle(double, double);
//	virtual double area();
//	virtual double pcrimeter();
//};
//
//class Sphere :public Figure_3D
//{
//public:
//	Sphere(double, double,double);
//	virtual double cubage();
//};	
//
//class Cone :public Figure_3D
//{
//public:
//	Cone(double, double, double);
//	virtual double cubage();
//};

class Basket
{
public:
	void AddItem(const Quote& sale);
	void AddItem(Quote&& sale);
	double TotalReceipt(ostream& os) const;
private:
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs);
	std::multiset<shared_ptr<Quote>, decltype(compare)* > item{ compare };
};