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
	cout << "½»»» " << *lhs.ps << "ºÍ" << *rhs.ps << endl;
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