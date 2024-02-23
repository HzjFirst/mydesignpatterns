#include "duck.h"

Duck::Duck():quack(nullptr)
{

}

Duck::~Duck()
{
    if(quack != nullptr)
    {
        delete quack;
        quack = nullptr;
    }
}

bool Duck::performQuack()
{
    return quack != nullptr ? (quack->quack(), 1) : 0;
}

void Duck::setQuackBehavior(QuackBehavior *be)
{
    if(quack != nullptr)
    {
        delete quack;
        quack = nullptr;
    }
    quack = be;
}

void strategy_demo()
{
    Duck duck;
    duck.setQuackBehavior(new Squeak());
    duck.performQuack();
    duck.setQuackBehavior(new Quack());
    duck.performQuack();
}
