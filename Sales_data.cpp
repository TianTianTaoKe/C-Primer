#include "stdafx.h"

#include "Sales_data.h"

Sales_data::Sales_data(const std::string &book, const unsigned num, const double sellp, const double salep)
{
	bookNo = book;
	units_sold = num;
	sellingPrice = sellp;
	salePrice = salep;
	if (sellingPrice != 0)
	{
		discount = salePrice / sellingPrice;
	}
}

Sales_data::Sales_data(std::istream &is) :Sales_data("", 0, 0, 0)
{
	read(is, *this);
}



std::istream& read(std::istream& ci, Sales_data& item)
{
	ci >> item.bookNo;
	ci >> item.units_sold;
	ci >> item.sellingPrice;
	ci >> item.salePrice;
	return ci;
}

std::istream& operator>>(std::istream& in, Sales_data& s)
{
	double price;
	in >> s.bookNo >> s.units_sold >> price;
	if (in)
	{
		s.revenue = s.units_sold * price;
	}
	else
		s = Sales_data();

	return in;
}

std::ostream& print(std::ostream& co, const Sales_data & item)
{
	co << item.bookNo << " ";
	co << item.units_sold << " ";
	co << item.sellingPrice << " ";
	co << item.salePrice << std::endl;
	return co;
}

ostream& operator<<(ostream& os, const Sales_data & item)
{
	os << item.isbn() << " ";
	os << item.units_sold << " ";
	os << item.revenue << " ";
	os << item.avg_price() << std::endl;
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

double Sales_data::avg_price()const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::operator=(const string& isbn)
{
	bookNo = isbn;
	return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	//units_sold += rhs.units_sold;
	//revenue += rhs.revenue;
	*this = (*this) + rhs;
	return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.units_sold += rhs.units_sold;
	sum.revenue += rhs.revenue;
	//sum += rhs;
	return sum;
}
Sales_data& Sales_data::operator-=(const Sales_data& rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}

Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sub = lhs;
	sub -= rhs;
	return sub;
}