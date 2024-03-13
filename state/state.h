#ifndef STATE_H
#define STATE_H
#include <QDebug>

class GumballMachine;

class State
{
protected:
    GumballMachine *_machine = nullptr;

public:
    State(GumballMachine *me):_machine(me) {}
    virtual ~State() {};

    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
};

#endif // STATE_H
