#ifndef _HEHE_CONCRETE_DECORATOR_B_H_
#define _HEHE_CONCRETE_DECORATOR_B_H_

#include "decorator.h"

namespace hehe
{
class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(Component *pDecorator) : Decorator(pDecorator){}
    void Operation()
    {
        AddedBehavior();
        Decorator::Operation();
    }
    void  AddedBehavior()
    {
        std::cout<<"This is added behavior B."<<std::endl;
    }
};





}
#endif
