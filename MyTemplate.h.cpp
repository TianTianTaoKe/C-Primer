#include "stdafx.h"
#include "MyTemplate.h"

template <typename T>
BlobTemp<T>::BlobTemp(T* p, std::size_t n)
	:data(std::make_shared<std::vector<T> >(p, p + n)) 
{
}

template <typename T>
BlobTemp<T>::BlobTemp()
	: data(std::make_shared<std::vector<T> >())
{

}

template <typename T>
template <typename It>
BlobTemp<T>::BlobTemp(It b, It e)
	:data(std::make_shared<std::vector<T>>(b, e))
{

}

template<typename T>
BlobTemp<T>::BlobTemp(std::initializer_list<T> il) :
	data(std::make_shared<std::vector<T> >(il))
{

}

template<typename T>
void BlobTemp<T>::check(size_type i, const std::string& msg) const
{
	if (i >= data->size())
	{
		throw std::out_of_range(msg);
	}
}

