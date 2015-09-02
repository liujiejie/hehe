#include <iostream>

#include "load_data.h"
#include "decorator/concrete_component.h"
#include "decorator/concrete_decorator_a.h"
#include "decorator/concrete_decorator_b.h"

using namespace hehe;

int main(int argc, char **argv)
{
	LoadData::LoadSuang();
	
    Component *pComponentObj = new ConcreteComponent();
    Decorator *pDecoratorAOjb = new ConcreteDecoratorA(pComponentObj);
    pDecoratorAOjb->Operation();
    std::cout<<"============================================="<<std::endl;
    Decorator *pDecoratorBOjb = new ConcreteDecoratorB(pComponentObj);
    pDecoratorBOjb->Operation();
    std::cout<<"============================================="<<std::endl;
    Decorator *pDecoratorBAOjb = new ConcreteDecoratorB(pDecoratorAOjb);
    pDecoratorBAOjb->Operation();
    std::cout<<"============================================="<<std::endl;
	
	
	
	

	return 0;
} 
