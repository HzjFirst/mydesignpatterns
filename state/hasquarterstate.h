#ifndef HASQUARTERSTATE_H
#define HASQUARTERSTATE_H

#include "state.h"

class HasQuarterState : public State
{
public:
    HasQuarterState(GumballMachine *);
    ~HasQuarterState();

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
};

#endif // HASQUARTERSTATE_H
