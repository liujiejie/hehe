#ifndef _HEHE_LOAD_DATA_H_
#define _HEHE_LOAD_DATA_H_

#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

#include "struct.h"
#include "file_path.h"

namespace hehe
{

inline bool sort_by_distance2(const S_suang* obj1, const S_suang* obj2) 
{
    return obj1->number_ < obj2->number_ ;
}

class LoadData
{
public:
    static long LoadSuang()
	{
		Suang_.clear();
/* 		long size = Suang_.size();
		if (size != 0)
		{
			return size;
		} */
		S_suang* suang_unit = NULL;
		char buffer[50];
		for(int i = 0; i < SUANG_FILE_COUNT; i++)
		{
			std::string file_path = g_root_dir + g_suang_name[i];
			std::ifstream in(file_path.c_str());
			if (! in.is_open() )  
			{
				std::cout << "Error opening file:" << file_path << std::endl;
				exit (1); 
			}
			
			while (! in.eof() )  
			{
			   in.getline (buffer,50);
			   if (strlen(buffer) < 10)
			   {
					continue;
			   }
			   suang_unit = new S_suang;
			   suang_unit->number_ = atoi(&buffer[0]);
			   suang_unit->data_[0] = atoi(&buffer[11]);
			   suang_unit->data_[1] = atoi(&buffer[14]);
			   suang_unit->data_[2] = atoi(&buffer[17]);
			   suang_unit->data_[3] = atoi(&buffer[20]);
			   suang_unit->data_[4] = atoi(&buffer[23]);
			   suang_unit->data_[5] = atoi(&buffer[26]);
			   suang_unit->data_[6] = atoi(&buffer[29]);
			   suang_unit->date_    = atoi(&buffer[35]) * 10000 +
									  atoi(&buffer[40]) * 100 +
									  atoi(&buffer[43]);
				Suang_.push_back(suang_unit);
			   //suang_unit->Print();
			}
			
			in.close();
		}
		
		sort(Suang_.begin(), Suang_.end(), sort_by_distance2);
		return Suang_.size();
	};
	static long LoadDa()
	{
	
		return 0;
	};

	static std::vector<S_suang*> Suang_;
};

}


#endif
