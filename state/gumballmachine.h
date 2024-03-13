#ifndef GUMBALLMACHINE_H
#define GUMBALLMACHINE_H
#include "state.h"

class GumballMachine
{
    int _count = 0;
    State *_soldOutState;
    State *_noQuarterState;
    State *_hasQuarterState;
    State *_soldState;
    State *_state;
public:
    GumballMachine(int count);
    ~GumballMachine();

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();

    void setState(State *st);
    void releaseBall();

    State* getSoldOutState();
    State* getNoQuarterState();
    State* getHasQuarterState();
    State* getSoldState();

    int getCount();
};

void state_demo();

#endif // GUMBALLMACHINE_H
