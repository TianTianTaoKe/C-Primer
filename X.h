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
StrVec& StrVec::operator=(StrVec && rhs)
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