#include <iostream>

#include "load_data.h"
#include "decorator/concrete_component.h"
#include "decorator/concrete_decorator_b.h"
#include "test/get_one_number.h"
#include "features/tongji.h"

using namespace hehe;

int main(int argc, char **argv)
{
	LoadData::LoadSuang();
	
    Component* pComponentObj = new ConcreteComponent();
	Decorator* pTongJi = new TongJi(pComponentObj);
	
	

	
	
	
	
	pTongJi->Operation();
	
	for(int i = 0; i < 10; i++)
	{
		S_suang data;
		GetOneShuang(data);
		data.Print();
	}
	
	
	
	return 0;
	
	
    //Decorator *pDecoratorAOjb = new ConcreteDecoratorA(pComponentObj);
    /* pDecoratorAOjb->Operation();
    std::cout<<"============================================="<<std::endl;
    Decorator *pDecoratorBOjb = new ConcreteDecoratorB(pComponentObj);
    pDecoratorBOjb->Operation();
    std::cout<<"============================================="<<std::endl; */
    //Decorator *pDecoratorBAOjb = new ConcreteDecoratorB(pDecoratorAOjb);
    //pDecoratorBAOjb->Operation();
    //std::cout<<"============================================="<<std::endl;
	
	
	/* for(int i = 0; i < 10; i++)
	{
		std::cout<<GetOneNumber(1, 32)<<std::endl;
	} */
	

	
} 
