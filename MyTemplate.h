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



