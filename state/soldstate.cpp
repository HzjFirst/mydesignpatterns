#include "soldstate.h"
#include "gumballmachine.h"

SoldState::SoldState(GumballMachine *me) : State(me)
{

}

SoldState::~SoldState()
{

}

void SoldState::insertQuarter()
{
    qDebug()<<"Please wait, we're already giving you a gumball";
}

void SoldState::ejectQuarter()
{
    qDebug()<<"Sorry, you already turned the crank";
}

void SoldState::turnCrank()
{
    qDebug()<<"Turning twice doesn't get you another gumball!";
}

void SoldState::dispense()
{
    _machine->releaseBall();
    if(_machine->getCount() > 0)
    {
        _machine->setState(_machine->getNoQuarterState());
    }
    else
    {
        qDebug()<<"Oops, out of gumballs";
        _machine->setState(_machine->getSoldOutState());
    }
}
