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