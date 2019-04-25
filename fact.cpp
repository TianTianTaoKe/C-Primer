#include "stdafx.h"

#include "Chapter6.h"

int fact(int a)
{
	int iFact = 1;
	for (int i = 1; i <= a;++i)
	{
		iFact *= i;
	}
	return iFact;
}