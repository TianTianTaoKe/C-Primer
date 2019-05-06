#include "stdafx.h"

#include "X.h"

int Employee::sn = 0;

HasPtr::~HasPtr()
{
	if (--*use == 0)
	{
		delete use;
		delete ps;
	}
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++*rhs.use;
	if (--*use == 0)
	{
		delete use;
		delete ps;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

HasPtr& HasPtr::operator=(HasPtr && rhs)
{
	if (this != &rhs)
	{
		if (--*use == 0)
		{
			delete use;
			delete ps;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		rhs.ps = nullptr;
		rhs.i = 0;
	}
	return *this;
}

HasPtr& HasPtr::operator=(const string& rhs)
{
	*ps = rhs;
	return  *this;
}

bool HasPtr::operator<(const HasPtr& rhs)const
{
	return *ps < *rhs.ps;
}

string& HasPtr::operator*()
{
	return *ps;
}

void TreeNode::CopyTree()
{
	if (left)
	{	
		left->CopyTree();
	}
	if (right)
	{
		right->CopyTree();
	}
	count++;
}

TreeNode::TreeNode(const TreeNode &tn)
:value(tn.value), count(tn.count), left(tn.left), right(tn.right)
{
	if (left)
	{
		left->CopyTree();
	}
	if (right)
	{
		right->CopyTree();
	}
}

int TreeNode::ReleaseTree()
{
	if (left)
	{
		if (!left->ReleaseTree())
		{
			delete left;
		}
	}
	if (right)
	{
		if (!right->ReleaseTree())
		{
			delete right;
		}
	}
	count--;
	return count;
}

TreeNode::~TreeNode()
{
	if (count)
	{
		ReleaseTree();
	}
}

BinStrTree::BinStrTree(const BinStrTree& bst) :root(bst.root)
{
	root->CopyTree();
}

BinStrTree::~BinStrTree()
{
	if (!root->ReleaseTree())
	{
		delete root;
	}
}

void Message::add_to_Folders(const Message& m)
{
	for (auto f:m.folders)
	{
		f->addMsg(this);
	}
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
	{
		f->remMsg(this);
	}
}

Message::Message(const Message& m) :content(m.content), folders(m.folders)
{
	add_to_Folders(m);
}

Message::Message(Message &&m) : content(std::move(m.content))
{
	move_Folders(&m);
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_Folders();
	content = rhs.content;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message& Message::operator=(Message&& rhs)
{
	if (this != &rhs)
	{
		remove_from_Folders();
		content = std::move(rhs.content);
		move_Folders(&rhs);
	}
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder& f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::move_Folders(Message* m)
{
	folders = std::move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

void swap(Message &lhs, Message&rhs)
{
	using std::swap;
	for (auto f:lhs.folders)
	{
		f->remMsg(&lhs);
	}
	for (auto f : rhs.folders)
	{
		f->remMsg(&rhs);
	}

	swap(lhs.folders, rhs.folders);
	swap(lhs.content, rhs.content);

	for (auto f : lhs.folders)
	{
		f->addMsg(&lhs);
	}
	for (auto f : rhs.folders)
	{
		f->addMsg(&rhs);
	}
}

void Folder::add_to_Message(const Folder& f)
{
	for (auto m : f.msgs)
	{
		m->addFldr(this);
	}
}

void Folder::remove_from_Message()
{
	for (auto m : msgs)
	{
		m->remFldr(this);
	}
}

Folder::Folder(const Folder&f) :msgs(f.msgs)
{
	add_to_Message(f);
}

Folder::~Folder()
{
	remove_from_Message();
}

Folder& Folder::operator=(const Folder& rhs)
{
	remove_from_Message();
	msgs = rhs.msgs;
	add_to_Message(rhs);
	return *this;
}

//StrVec------------------------------------------------------
allocator<string> StrVec::alloc;
void StrVec::push_back(const string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b,const string *e)
{
	auto date = alloc.allocate(e - b);
	return{ date, uninitialized_copy(b, e, date) };
}

void StrVec::free()
{
	if (element)
	{
		//for (auto p = first_free; p != element;)
		//{
		//	alloc.destroy(--p);
		//}
		for_each(element, first_free, [](string &s){alloc.destroy(&s); });
	}
	alloc.deallocate(element, cap - element);
}

StrVec::StrVec(const StrVec& s)
{
	auto data = alloc_n_copy(s.begin(), s.end());
	element = data.first;
	first_free = cap = data.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec& s)
{
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	element = data.first;
	first_free = cap =data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;

	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto elem = element;

	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	element = newdata;
	first_free = dest;
	cap = element + newcapacity;
}

void StrVec::reallocate(size_t newcapacity)
{
	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto elem = element;

	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	element = newdata;
	first_free = dest;
	cap = element + newcapacity;
}

void StrVec::reserve(size_t n)
{
	if (n>capacity())
	{
		reallocate(n);
	}
}

void StrVec::resize(size_t n)
{
	if (n>size())
	{
		while (size() < n)
		{
			push_back("");
		}
	}
	else if (n < size())
	{
		while (size() > n)
		{
			alloc.destroy(--first_free);
		}
	}
}

void StrVec::resize(size_t n,const string& s)
{
	if (n > size())
	{
		while (size() < n)
		{
			push_back(s);
		}
	}
}

//MyString------------------------------------------------------
allocator<char> MyString::a;

MyString & MyString::operator=(const MyString &rhs)
{
	cout << "拷贝赋值" << endl;
	char* newp = a.allocate(rhs.sz);
	uninitialized_copy(rhs.p, rhs.p + rhs.sz, newp);
	if (p)
	{
		a.deallocate(p, sz);
	}
	p = newp;
	sz = rhs.sz;

	return *this;
}

MyString & MyString::operator=(MyString && rhs)
{
	if (this != &rhs)
	{
		if (p)
		{
			a.deallocate(p, sz);
		}
		p = rhs.p;
		sz = rhs.sz;
		rhs.p = nullptr;
		rhs.sz = 0;
	}
	return *this;
}

MyString & MyString::operator=(const char *cp)
{
	if (p)
	{
		a.deallocate(p, sz);
	}
	p = a.allocate(sz = strlen(cp));
	uninitialized_copy(cp, cp + sz, p);

	return *this;
}

MyString & MyString::operator=(const char c)
{
	if (p)
	{
		a.deallocate(p, sz);
	}

	p = a.allocate(sz = 1);

	*p = c;

	return *this;
}

MyString & MyString::operator=(initializer_list<char> il)
{
	if (p)
	{
		a.deallocate(p, sz);
	}

	p = a.allocate(sz = il.size());

	uninitialized_copy(il.begin(), il.end(), p);

	return *this;
}

ostream & print(ostream& os, MyString& s)
{
	auto p = s.begin();
	for (auto p = s.begin(); p != s.end();++p)
	{
		os << *p;
	}

	return os;
}

ostream & operator<<(ostream& os,MyString& s)
{
	return print(os, s);
}

//Foo------------------------------------------------------------------
//Foo Foo::sorted() &&
//{
//	cout << "右值引用" << endl;
//	sort(data.begin(), data.end());
//	return *this;
//}
//
//Foo Foo::sorted() const &
//{
//	cout << "左值引用" << endl;
//	return Foo(*this).sorted();
//}