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

StrVec& StrVec::operator=(initializer_list<string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	element = data.first;
	first_free = cap = data.second;
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

bool operator==(const StrVec& lhs, const StrVec& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}
	for (auto itr1 = lhs.begin(), itr2 = rhs.begin(); 
			itr1 != lhs.end() && itr2 != rhs.end();++itr1,++itr2)
	{
		if (*itr1 != *itr2)
		{
			return false;
		}
	}

	return true;
}

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrVec& lhs, const StrVec& rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (;itr1 != lhs.end() && itr2 != rhs.end(); ++itr1, ++itr2)
	{
		if (*itr1 < *itr2)
			return true;
		else if (*itr1 > *itr2)
			return false;
	}

	if (itr1 == lhs.end() && itr2 != lhs.end())
	{
		return true;
	}
	return false;
}

bool operator<=(const StrVec& lhs, const StrVec& rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (; itr1 != lhs.end() && itr2 != rhs.end(); ++itr1, ++itr2)
	{
		if (*itr1 < *itr2)
			return true;
		else if (*itr1 > *itr2)
			return false;
	}

	if (itr1 == lhs.end())
	{
		return true;
	}
	return false;
}

bool operator>(const StrVec& lhs, const StrVec& rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (; itr1 != lhs.end() && itr2 != rhs.end(); ++itr1, ++itr2)
	{
		if (*itr1 > *itr2)
			return true;
		else if (*itr1 < *itr2)
			return false;
	}

	if (itr1 != lhs.end() && itr2 == lhs.end())
	{
		return true;
	}
	return false;
}

bool operator>=(const StrVec& lhs, const StrVec& rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (; itr1 != lhs.end() && itr2 != rhs.end(); ++itr1, ++itr2)
	{
		if (*itr1 > *itr2)
			return true;
		else if (*itr1 < *itr2)
			return false;
	}

	if (itr2 == lhs.end())
	{
		return true;
	}
	return false;
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

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.p, rhs.p) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.p, rhs.p) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.p, rhs.p) <= 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.p, rhs.p) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.p, rhs.p) >= 0;
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

//Date------------------------------------------------------------------
Date& Date::operator=(const string &date)
{
	istringstream is(date);
	char ch1, ch2;
	is >> year >> ch1 >> month >> ch2 >> day;
	if (!is || ch1 !='-' || ch2 != '-')
	{
		throw std::invalid_argument("Bad date");
	}
	if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		throw std::invalid_argument("Bad date");
	}
	return *this;
}

Date::operator bool()
{
	vector<vector<int> >days_per_month =
	{
		{31,28,31,30,31,30,31,31,30,31,30,31},
		{31,29,31,30,31,30,31,31,30,31,30,31}
	};
	return month >= 1 && month <= 12 && 1 <= day && day <= days_per_month[IsLeapYear() ? 1 : 0][month
		- 1];
}

bool Date::IsLeapYear()
{
	return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

ostream& operator<<(ostream& os, const Date& dt)
{
	const char sep = '\t';
	os << "year:" << dt.year << sep << "month:" << dt.month << sep << "day:" << dt.day;
	return os;
}

istream& operator>>(istream& is, Date& dt)
{
	is >> dt.year >> dt.month >> dt.day;
	if (!is)
	{
		dt = Date(0, 0, 0);
	}
	return  is;
}

bool operator== (const Date& lhs, const Date& rhs)
{
	return lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day;
}

bool operator!= (const Date& lhs, const Date& rhs)
{
	return !(lhs == rhs);
}

bool operator< (const Date& lhs, const Date& rhs)
{
	if (lhs.year < rhs.year)
		return true;
	else if (lhs.year == rhs.year)
	{
		if (lhs.month < rhs.month)
			return true;
		else if (lhs.month == rhs.month)
		{
			if (lhs.day < rhs.day)
				return true;
		}
	}
	return false;
}

bool operator<= (const Date& lhs, const Date& rhs)
{
	if (lhs.year < rhs.year)
		return true;
	else if (lhs.year == rhs.year)
	{
		if (lhs.month < rhs.month)
			return true;
		else if (lhs.month == rhs.month)
		{
			if (lhs.day <= rhs.day)
				return true;
		}
	}
	return false;
}
bool operator> (const Date& lhs, const Date& rhs)
{
	if (lhs.year > rhs.year)
		return true;
	else if (lhs.year == rhs.year)
	{
		if (lhs.month > rhs.month)
			return true;
		else if (lhs.month == rhs.month)
		{
			if (lhs.day > rhs.day)
				return true;
		}
	}
	return false;
}

bool operator>= (const Date& lhs, const Date& rhs)
{
	if (lhs.year > rhs.year)
		return true;
	else if (lhs.year == rhs.year)
	{
		if (lhs.month > rhs.month)
			return true;
		else if (lhs.month == rhs.month)
		{
			if (lhs.day >= rhs.day)
				return true;
		}
	}
	return false;
}

double PrintTotal(ostream& os, const Quote& item, size_t n)
{
	double ret = item.NetPrice(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return  ret;
}

void Basket::AddItem(const Quote& sale)
{
	item.insert(shared_ptr<Quote>(sale.clone()));
}

void Basket::AddItem(Quote&& sale)
{
	item.insert(shared_ptr<Quote>(std::move(sale).clone()));
}

double Basket::TotalReceipt(ostream& os) const
{
	double sum = 0;
	for (auto iter = item.begin();iter != item.end();iter = item.upper_bound(*iter))
	{
		sum = PrintTotal(os, **iter, item.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}

bool Basket::compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs)
{
	return lhs->isbn() < rhs->isbn();
}