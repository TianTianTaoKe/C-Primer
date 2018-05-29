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

std::ostream& print(std::ostream& co, const Sales_data & item)
{
	co << item.bookNo << " ";
	co << item.units_sold << " ";
	co << item.sellingPrice << " ";
	co << item.salePrice << std::endl;
	return co;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}