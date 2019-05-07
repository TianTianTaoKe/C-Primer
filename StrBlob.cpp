#include "stdafx.h"

#include "StrBlob.h"

StrBlob::StrBlob() :data(make_shared<vector<string> >()){}

StrBlob::StrBlob(initializer_list<string> il) :
data(make_shared<vector<string> >(il)){}

void StrBlob::check(size_type i, const string& msg) const
{
	if (i>= data->size())
	{
		throw std::out_of_range(msg);
	}
}

string & StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string & StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string & StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data < *rhs.data;
}

bool operator<=(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data <= *rhs.data;
}

bool operator>(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data > *rhs.data;
}

bool operator>=(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data >= *rhs.data;
}

const string & StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	auto l = lhs.wptr.lock();
	auto r = rhs.wptr.lock();
	if (l == r)
	{
		return (!r || lhs.curr == rhs.curr);
	}
	else
		return false;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	auto l = lhs.wptr.lock();
	auto r = rhs.wptr.lock();
	if (l == r)
	{
		if (!r)
		{
			return false;
		}
		return lhs.curr < lhs.curr;
	}
	else
		return false;
}

bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	auto l = lhs.wptr.lock();
	auto r = rhs.wptr.lock();
	if (l == r)
	{
		return (!r || lhs.curr <= rhs.curr);
	}
	else
		return false;
}

bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	auto l = lhs.wptr.lock();
	auto r = rhs.wptr.lock();
	if (l == r)
	{
		if (!r)
		{
			return false;
		}
		return lhs.curr > lhs.curr;
	}
	else
		return false;
}

bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	auto l = lhs.wptr.lock();
	auto r = rhs.wptr.lock();
	if (l == r)
	{
		return (!r || lhs.curr >= rhs.curr);
	}
	else
		return false;
}

StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "increment past begin of StrBlobPtr");	
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;
	++(*this);
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--(*this);
	return ret;
}

StrBlobPtr StrBlobPtr::operator+(int n)
{
	StrBlobPtr ret = *this;
	ret.curr += n;
	return ret;
}

StrBlobPtr StrBlobPtr::operator-(int n)
{
	StrBlobPtr ret = *this;
	ret.curr -= n;
	return ret;
}

string& StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

string* StrBlobPtr::operator->() const
{
	return &(this->operator*());
}