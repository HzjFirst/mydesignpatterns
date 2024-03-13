#include "gumballmachine.h"
#include "hasquarterstate.h"
#include "noquarterstate.h"
#include "soldoutstate.h"
#include "soldstate.h"

GumballMachine::GumballMachine(int count): _count(count),_soldOutState(new SoldOutState(this)),
    _noQuarterState(new NoQuarterState(this)),_hasQuarterState(new HasQuarterState(this)),
    _soldState(new SoldState(this)),_state(nullptr)
{
    if(_count > 0)
    {
        _state = _noQuarterState;
    }
    else
    {
        _state = _soldState;
    }
}

GumballMachine::~GumballMachine()
{
    if(_soldOutState)
        delete _soldOutState;

    if(_noQuarterState)
        delete _noQuarterState;

    if(_hasQuarterState)
        delete _hasQuarterState;

    if(_soldState)
        delete _soldState;

    _soldOutState = nullptr;
    _noQuarterState = nullptr;
    _hasQuarterState = nullptr;
    _soldState = nullptr;
    _state = nullptr;
}

void GumballMachine::insertQuarter()
{
    _state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
    _state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
    _state->turnCrank();
    _state->dispense();
}

void GumballMachine::setState(State *st)
{
    _state = st;
}

void GumballMachine::releaseBall()
{
    qDebug()<<"A gumball comes rolling out the slot....";
    _count = _count != 0 ? (_count - 1) : _count;
}

State *GumballMachine::getSoldOutState()
{
    return _soldOutState;
}

State *GumballMachine::getNoQuarterState()
{
    return _noQuarterState;
}

State *GumballMachine::getHasQuarterState()
{
    return _hasQuarterState;
}

State *GumballMachine::getSoldState()
{
    return _soldState;
}

int GumballMachine::getCount()
{
    return _count;
}


void state_demo()
{
    GumballMachine gumballMachine(5);

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();

    gumballMachine.insertQuarter();
    gumballMachine.ejectQuarter();
    gumballMachine.turnCrank();

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.ejectQuarter();

    gumballMachine.insertQuarter();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
}
