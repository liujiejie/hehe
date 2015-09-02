#ifndef _HEHE_STRUCT_H_
#define _HEHE_STRUCT_H_

#include <iostream>
#include <iomanip>

namespace hehe
{
//0~5 红球
//6   篮球
struct S_suang
{
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
				  << red_[0] << "  " << std::setw(2)
				  << red_[1] << "  " << std::setw(2)
				  << red_[2] << "  " << std::setw(2)
				  << red_[3] << "  " << std::setw(2)
				  << red_[4] << "  " << std::setw(2)
				  << red_[5] << "  " << "\033[31;4m" << std::setw(2)
		          << blue_   << "  " << "\033[31;0m"
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
