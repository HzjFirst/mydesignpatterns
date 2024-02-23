#ifndef DUCK_H
#define DUCK_H
#include "quackbehavior.h"

class Duck
{
    QuackBehavior *quack;
public:
    Duck();
    ~Duck();

    bool performQuack();
    void setQuackBehavior(QuackBehavior *be);
};

void strategy_demo();

#endif // DUCK_H
