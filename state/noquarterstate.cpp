#include "noquarterstate.h"
#include "gumballmachine.h"

NoQuarterState::NoQuarterState(GumballMachine *me) : State(me)
{

}

NoQuarterState::~NoQuarterState()
{

}

void NoQuarterState::insertQuarter()
{
    qDebug()<<"You insert a quarter";
    _machine->setState(_machine->getHasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
    qDebug()<<"You haven't insert a quarter";
}

void NoQuarterState::turnCrank()
{
    qDebug()<<"You turned, but there's no quarter";
}

void NoQuarterState::dispense()
{
    qDebug()<<"You need to pay first";
}
