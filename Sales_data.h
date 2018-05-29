#pragma once
#include <string>
#include <iostream>

class Sales_data
{
public:
	Sales_data(const std::string &book) :Sales_data(book,0,0,0){}
	Sales_data(const std::string &book, const unsigned num, const double sellp, const double salep);
	Sales_data(){}
	Sales_data(std::istream &is) ;
	~Sales_data(){};
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price()const;
private:
	std::string bookNo;			//�鼮���
	unsigned units_sold = 0;	//������
	double sellingPrice = 0.0;	//ԭʼ�۸�
	double salePrice = 0.0;		//ʵ�ۼ۸�
	double discount = 0.0;		//�ۿ�

	friend std::istream & read(std::istream &, Sales_data&);
	friend std::ostream & print(std::ostream&, const Sales_data&);
	friend Sales_data add(const Sales_data&, const Sales_data&);
};

inline Sales_data& Sales_data::combine( const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	salePrice = (rhs.salePrice * rhs.units_sold + salePrice*units_sold) / (rhs.units_sold + units_sold);
	if (sellingPrice != 0)
	{
		discount = salePrice / sellingPrice;
	}
	return *this;
}

std::istream & read(std::istream &, Sales_data&);
std::ostream & print(std::ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);
