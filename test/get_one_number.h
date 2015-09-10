#ifndef _HEHE_GET_ONE_NUMBER_H_
#define _HEHE_GET_ONE_NUMBER_H_

#include <vector>
#include <string>

#include "../struct.h"

namespace hehe
{
inline int GetOneNumber(int min, int max)
{
	return min + rand() % max;
};

void GetOneShuang(S_suang& data);

}

#endif
