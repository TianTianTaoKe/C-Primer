#ifndef STRBLOB_H
#define STRBLOB_H

#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

using std::shared_ptr;
using std::vector;
using std::string;
using std::shared_ptr;

class StrBlobPtr;
class StrBlob
{
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	StrBlob(const StrBlob&);
	StrBlob& operator=(const StrBlob&);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//添加和删除元素
	void push_back(const string &str) { data->push_back(str); }
	void push_back(string && str) { data->push_back(std::move(str)); }
	void pop_back();
	//访问元素
	string& front();
	const string& front() const;
	string & back();
	const string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();

	StrBlobPtr begin() const;
	StrBlobPtr end() const;
protected:
private:
	shared_ptr<vector<string> > data;
	//如果data[i]不合法，抛出异常
	void check(size_type i, const string& msg) const;
};

inline
StrBlob::StrBlob(const StrBlob& s) :data(make_shared<vector<string> >(*s.data))
{

}

inline
StrBlob& StrBlob::operator=(const StrBlob& rhs)
{
	data = make_shared<vector<string> >(*rhs.data);
	return *this;
}

class StrBlobPtr
{
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz){}
	StrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz){}

	const string& deref() const;
	StrBlobPtr& incr();
	StrBlobPtr& decr();

	~StrBlobPtr()
	{
	}

private:
	shared_ptr<const vector<string> > check(size_t, const string&) const;
	weak_ptr<vector<string> > wptr;
	size_t curr;
};

inline
shared_ptr<const vector<string> >
StrBlobPtr::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
	{
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw std::out_of_range(msg);
	}

	return ret;
}

inline const string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline StrBlobPtr& StrBlobPtr::decr()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

inline StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this,data->size());
}

inline StrBlobPtr StrBlob::begin() const
{
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const
{
	return StrBlobPtr(*this, data->size());
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
	{
		return (!r || lhs.curr == rhs.curr);
	}
	else
		return false;
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}
#endif