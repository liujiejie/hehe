#ifndef _HEHE_CONCRETE_DECORATOR_A_H_
#define _HEHE_CONCRETE_DECORATOR_A_H_

#include "decorator.h"

namespace hehe
{
class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(Component *pDecorator) : Decorator(pDecorator){}
    void Operation()
    {
        AddedBehavior();
        Decorator::Operation();
    }
    void  AddedBehavior()
    {
        std::cout<<"This is added behavior A."<<std::endl;
    }
};





}
#endif
