#ifndef SOLDOUTSTATE_H
#define SOLDOUTSTATE_H

#include "state.h"

class SoldOutState : public State
{
public:
    SoldOutState(GumballMachine *me);
    ~SoldOutState();

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
};

#endif // SOLDOUTSTATE_H
