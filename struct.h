#ifndef _HEHE_STRUCT_H_
#define _HEHE_STRUCT_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

namespace hehe
{
	
		//using namespace std;
	
struct NumValue
{
	NumValue(int num, int value)
	{
		num_ = num;
		value_ = value;
	}
	int num_;
	int value_;
	
	void ToRow(std::ostringstream& data_stream)
	{
		data_stream << "<tr><td>"
		<< num_
		<< "</td><td>"
		<< value_
		<< "</td></tr>";
	}
};

inline bool sort_by_distance(const NumValue& obj1, const NumValue& obj2) 
{
    return obj1.value_ < obj2.value_ ;
}
//0~5 红球
//6   篮球
struct S_suang
{
	S_suang()
	{
		date_ = 0;
		number_ = 0;
	}
	int data_[7];
	int red_[6];
	int	blue_;
	int date_;
	int number_;
	
	void Print()
	{
		std::cout.flags(std::ios::right); //右对齐
		std::cout.width(2);
		std::cout.fill(' ');
		std::cout << "\033[31;1m"    << std::setw(2)
				  << data_[0] << "  " << std::setw(2)
				  << data_[1] << "  " << std::setw(2)
				  << data_[2] << "  " << std::setw(2)
				  << data_[3] << "  " << std::setw(2)
				  << data_[4] << "  " << std::setw(2)
				  << data_[5] << "  " << "\033[34;1m" << std::setw(2)
		          << data_[6]   << "  \t" << "\033[31;0m"
				  << date_   << "  "
				  << number_ << std::endl;
	};
	
	bool operator < (const S_suang& unit)const
	{
		if (date_ < unit.date_)
		{
			return true;
		}
		
		if (date_ > unit.date_)
		{
			return false;
		}
	}
};


}

#endif
