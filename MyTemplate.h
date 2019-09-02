#pragma once
#include  "stdafx.h"
template<typename T>
int Compare(const T& v1, const T& v2)
{
	if (v1 < v2)
	{
		return -1;
	}
	if (v2 < v1)
	{
		return 1;
	}
	return 0;
}

template<typename Iter,typename T>
Iter MyFind(Iter begin, Iter end, T value)
{
	for (Iter iter = begin;iter != end;iter++)
	{
		if (*iter == value)
		{
			return iter;
		}
	}
	return end;
}

template<typename T, size_t N>
const T* MyBegin(const T(&a)[N])
{
	return &a[0];
}

template<typename T, size_t N>
const T* MyEnd(const T(&a)[N])
{
	return &a[0] + N;
}

template<typename T, size_t N>
constexpr int ArrSize(const T(&a)[N])
{
	return N;
}

template<typename T,size_t N>
void MyPrint(const T(&a)[N])
{
	//for (auto iter = MyBegin(a);iter != MyEnd(a);++iter)
	//{
	//	cout << *iter << endl;
	//}
	for (int i = 0;i<ArrSize(a);++i)
	{
		cout << a[i] << endl;
	}
}

template <typename> class BlobPtrTemp;
template <typename T>class BlobTemp
{
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	BlobTemp();

	BlobTemp(initializer_list<T> il);
	template <typename It> BlobTemp(It b, It e);
	BlobTemp(T*, std::size_t);

	BlobPtrTemp<T> begin(){ return BlobPtrTemp<T>(*this); }
	BlobPtrTemp<T> end()
	{
		auto ret = BlobPtrTemp<T>(*this, data->size());
		return  ret;
	}

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T& t) { data->push_back(t); }
	void push_back(T&& t) { data->push_back(std::move(t)); }
	void pop_back();

	T& front();
	T& back();
	T& at(size_type);
	const T& back() const;
	const T& front() const;
	const T& at(size_type) const;
	T& operator[](size_type i);
	const T& operator[](size_type i) const;

	void swap(BlobTemp& b) { data.swap(b.data); }

private:
	std::shared_ptr<std::vector<T> > data;

	void check(size_type i, const std::string& msg) const;
};

