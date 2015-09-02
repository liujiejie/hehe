#ifndef _HEHE_LOAD_DATA_H_
#define _HEHE_LOAD_DATA_H_

#include <fstream>
#include <vector>

#include "struct.h"
#include "file_path.h"

namespace hehe
{

class LoadData
{
public:
    static long LoadSuang()
	{
		char buffer[50];
		for(int i = 0; i < SUANG_FILE_COUNT; i++)
		{
			std::string file_path = g_root_dir + g_suang_name[i];
			std::ifstream in(file_path.c_str());
			if (! in.is_open() )  
			{
				std::cout << "Error opening file" << std::endl;
				exit (1); 
			}
			
			while (! in.eof() )  
			{
			   in.getline (buffer,50);
			   std::cout << buffer << std::endl;  
			}
			
			in.close();
		}
		return 0;
	};
	static long LoadDa()
	{
	
		return 0;
	};

	static std::vector<S_suang*> Suang_;
	//vector<> Da_;
};

}


#endif
