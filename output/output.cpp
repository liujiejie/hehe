#include "output.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>


namespace hehe
{

int OutPut(std::string& file_path, std::string& data)
{
 	std::ofstream outfile(file_path.c_str());
	if (!outfile)
	{
		std::cout << "Error opening file:" << file_path << std::endl;
		exit(1);
	}
	outfile << data << std::flush;
	outfile.close();
	
	return 0;
}



}
