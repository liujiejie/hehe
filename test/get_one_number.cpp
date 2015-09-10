#include <stdlib.h>
#include <sys/time.h> 
#include <unistd.h>
#include <algorithm>

#include "get_one_number.h"

namespace hehe
{
int SetSrand()
{
	srand((unsigned)time(NULL)); 
	return 0;
};
static int set_srand = SetSrand();

bool AdugeEquel(const int* data, int num, int index)
{
	for(int i = 0; i < index; i++)
	{
		if (data[i] == num)
		{
			return true;
		}
	}
	return false;
}

void GetOneShuang(S_suang& data)
{
	for(int i = 0; i < 6; )
	{
		data.data_[i] = GetOneNumber(1, 32);
		if (AdugeEquel(data.data_, data.data_[i], i))
		{
			continue;
		}
		i++;
	}
	data.data_[6] = GetOneNumber(1, 16);
	std::sort(data.data_ + 0, data.data_ + 6);
}



}
