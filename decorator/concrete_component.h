#ifndef _HEHE_CONCRETE_COMPONENT_H_
#define _HEHE_CONCRETE_COMPONENT_H_

#include "component.h"

namespace hehe
{
class ConcreteComponent : public Component
{
public:
	void Operation()
	{
		std::cout<<"start"<<std::endl;
	}
};





}
#endif
