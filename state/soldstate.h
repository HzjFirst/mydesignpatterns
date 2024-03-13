#ifndef SOLDSTATE_H
#define SOLDSTATE_H

#include "state.h"

class SoldState : public State
{
public:
    SoldState(GumballMachine *me);
    ~SoldState();

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
};

#endif // SOLDSTATE_H
