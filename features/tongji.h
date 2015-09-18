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

struct S_TongJi
{
	std::vector<int> data_;
	int date_;
};


class TongJi : public Decorator
{
public:
    TongJi(Component *pDecorator) : Decorator(pDecorator){}
	TongJi(): Decorator(NULL){}
    void Operation()
    {
		std::cout<<"TongJi"<<std::endl;
		
        Decorator::Operation();
		
		AddedShuangBehavior(20030101, 20200101, LoadData::Suang_, 0, 6, 34);
		MakeFile(GetFileName(20030101, 20200101, 0, 6, 34));
							 
		AddedShuangBehavior(20030101, 20200101, LoadData::Suang_, 6, 7, 17);
		MakeFile(GetFileName(20030101, 20200101, 6, 7, 17));
		
		
		
		
		red_number_count_ = 8;
		blue_number_count_ = 3;		
		
		std::vector<S_TongJi*> tong_ji_red_list;
		S_TongJi* tong_ji_red_ptr;
		std::vector<S_TongJi*> tong_ji_blue_list;
		S_TongJi* tong_ji_blue_ptr;
		
		int behavior_count = LoadData::Suang_.size();
		for(int i = 0; i < behavior_count; i++)
		{
			behavior_list_.push_back(new TongJi);
			
			tong_ji_red_ptr = new S_TongJi;
			tong_ji_red_ptr->date_ = 0;
			behavior_list_[i]->AddedShuangBehavior(20030101, 20200101, LoadData::Suang_, 0, 6, 34);
						
			for(int j = 0; j < red_number_count_ ||
				behavior_list_[i]->num_value_[j].num_ == behavior_list_[i]->num_value_[red_number_count_].num_; j++)
			{
				tong_ji_red_ptr->data_.push_back(behavior_list_[i]->num_value_[j].value_);
			}
			tong_ji_red_list.push_back(tong_ji_red_ptr);
			
			
		
			tong_ji_blue_ptr = new S_TongJi;
			tong_ji_blue_ptr->date_ = 0;
			behavior_list_[i]->AddedShuangBehavior(20030101, 20200101, LoadData::Suang_, 6, 7, 17);
			for(int j = 0; j < blue_number_count_ ||
				behavior_list_[i]->num_value_[j].num_ == behavior_list_[i]->num_value_[red_number_count_].num_; j++)
			{
				tong_ji_blue_ptr->data_.push_back(behavior_list_[i]->num_value_[j].value_);
			}
			tong_ji_blue_list.push_back(tong_ji_blue_ptr);
			
			delete *LoadData::Suang_.begin();
			LoadData::Suang_.erase( LoadData::Suang_.begin( ) );
		}
		
		TongJi tongji_red_all;
		TongJi tongji_blue_all;
		
		tongji_red_all.AddedShuangBehavior(0, 0, tong_ji_red_list, 0, 0, 34);
		tongji_red_all.MakeFile(GetFileName(0, 0, 0, 0, 34));
							 
		tongji_blue_all.AddedShuangBehavior(0, 0, tong_ji_blue_list, 0, 0, 17);
		tongji_blue_all.MakeFile(GetFileName(0, 0, 0, 0, 17));
						 
		for(int i = 0; i < tong_ji_red_list.size(); i++)
		{
			delete tong_ji_red_list[i];
		}
		
		for(int i = 0; i < tong_ji_blue_list.size(); i++)
		{
			delete tong_ji_blue_list[i];
		}
		
		std::cout<<"sdfsdf2"<<std::endl;
    }
	
	template<typename T>
    void  AddedShuangBehavior(int start_date, int end_date,
		const std::vector<T*>& src_data_list,
		int start_index, int end_index, int value_range)
    {
		std::cout<< start_date << "------"<< end_date <<std::endl;
		
		GetAllNumberProbability(start_date, end_date,
			src_data_list, start_index, end_index, value_range);
		SortForAll();
		/* MakeFile(GetFileName(start_date, end_date,
							 start_index, end_index,
							 value_range)); */
							 

		

    }

private:
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
		
		int start_index_in = start_index;
		int end_index_in = end_index;

		long size = src_data_list.size();
		for (long i = 0; i < size; i++)
		{
			if (end_index == 0)
			{
				end_index_in = src_data_list[i]->data_.size();
			}
			for(int j = start_index_in; j < end_index_in; j++)
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
	
	
	std::vector<TongJi*> 	behavior_list_;	//所有操作的集合
	
	
	std::vector<int> 		number_;			//原始数字数量统计
	std::vector<NumValue> 	num_value_;			//按照数字统计数量排序后的
	
	std::vector<S_suang*> 	shuang_;				//当前多有数字推断出的所有组合
	std::vector<int> 		all_red_number_;		//当前所有的数字 红
	int						red_number_count_;		//每次统计后的红色数字
	std::vector<int> 		all_blue_number_;		//当前所有的数字 蓝
	int						blue_number_count_;		//每次统计后的蓝色数字
};





}
#endif
