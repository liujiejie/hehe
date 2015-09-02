#ifndef _HEHE_DECORATOR_H_
#define _HEHE_DECORATOR_H_

#include "component.h"


namespace hehe
{
class Decorator : public Component
{
public:
    Decorator(Component* pComponent) : m_pComponentObj(pComponent) {}
    void Operation()
    {
        if (m_pComponentObj != NULL)
        {
            m_pComponentObj->Operation();
        }
    }
protected:
    Component* m_pComponentObj;
};





}
#endif
