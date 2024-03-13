#ifndef NOQUARTERSTATE_H
#define NOQUARTERSTATE_H

#include "state.h"

class NoQuarterState : public State
{
public:
    NoQuarterState(GumballMachine *me);
    ~NoQuarterState();

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
};

#endif // NOQUARTERSTATE_H
