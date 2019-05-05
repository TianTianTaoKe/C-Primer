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
	HasPtr& operator=(const string&);
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
	Message& operator=(const Message&);
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
	StrVec():
		element(nullptr), first_free(nullptr), cap(nullptr){}
	StrVec(initializer_list<string> li);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
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

class MyString
{
	friend ostream& operator<<(ostream&, MyString&);
	friend ostream& print(ostream&, MyString&);
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

	MyString& operator=(const MyString&);

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