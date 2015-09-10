#ifndef _HEHE_TONGJI_H_
#define _HEHE_TONGJI_H_

#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>

#include "../decorator/decorator.h"
#include "../output/output.h"
#include "../struct.h"

namespace hehe
{


class TongJi : public Decorator
{
public:
    TongJi(Component *pDecorator) : Decorator(pDecorator){}
    void Operation()
    {
		std::cout<<"TongJi"<<std::endl;
		
        Decorator::Operation();
		
		TongJi* array_tongji = new TongJi[100];
		AddedBehavior(20030101, 20200101, 0, 6, 32);
		AddedBehavior(20030101, 20200101, 6, 7, 16);
    }
    void  AddedBehavior(int start_date, int end_date,
		int start_index, int end_index, int value_range)
    {
		std::cout<< start_date << "------"<< end_date <<std::endl;
		
		GetAllNumberProbability(start_date, end_date,
			LoadData::Suang_, start_index, end_index, value_range);
		SortForAll();
		MakeFile(GetFileName(start_date, end_date,
							 start_index, end_index,
							 value_range));
    }
	
	void MakeFile(std::string file_path_str)
	{
		std::string data_str = "<table><tr><td>";
		data_str.append(MakeHtmlTable(number_));
		data_str.append("</td><td></td><td>");
		data_str.append(MakeHtmlTable(num_value_));
		data_str.append("</td></tr></table>");
		OutPut(file_path_str, data_str);
	}
	
	std::string GetFileName(int start_date, int end_date,
							int start_index, int end_index,
							int value_range)
	{
		std::stringstream file_name_stream;
		file_name_stream << g_root_dir << "caipiao\\res\\"
			<< start_date << "-" << end_date << "_" << start_index
			<< "-" << end_index << "_0-" << value_range
			<< ".html";
 		std::string file_name_str;
		file_name_stream >> file_name_str;
		return file_name_str;
	}
	
	template<typename T>
	void GetAllNumberProbability(int start_date, int end_date,
	const std::vector<T*>& src_data_list,
	int start_index, int end_index, int value_range)
	{
/* 		std::cout<<start_date
		<<" " << end_date
		<<" " << start_index
		<<" " << end_index
		<<" " << value_range
		<<std::endl; */
	
		number_.clear();
		for(int i = 0; i < value_range; i++)
		{
			number_.push_back(0);
		}
		
		long size = src_data_list.size();
		for (long i = 0; i < size; i++)
		{
			for(int j = start_index; j < end_index; j++)
			{
				if (src_data_list[i]->date_ >= start_date &&
				    src_data_list[i]->date_ <= end_date)
				{
					++(number_[src_data_list[i]->data_[j]]);
				}
			}
		}
	}
	
 	void SortForAll()
	{
		std::cout.fill(' ');
		num_value_.clear();
		int size = number_.size();
		for(int j = 1; j < size; j++)
		{
			num_value_.push_back(NumValue(j, number_[j]));
		}
		
		sort(num_value_.begin(), num_value_.end(), sort_by_distance);
	} 
	
	std::vector<int> number_;
	std::vector<NumValue> num_value_;
	
	std::vector<S_suang*> shuang_
};  std::vector<int> all_number_;





}
#endif
