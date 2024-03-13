#include "soldoutstate.h"

SoldOutState::SoldOutState(GumballMachine *me) : State(me)
{

}

SoldOutState::~SoldOutState()
{

}

void SoldOutState::insertQuarter()
{
    qDebug()<<"You can't insert a quarter, the machine is sold out";
}

void SoldOutState::ejectQuarter()
{
    qDebug()<<"You can't eject, you haven't inserted a quarter yet";
}

void SoldOutState::turnCrank()
{
    qDebug()<<"You turned, but there are no gumballs";
}

void SoldOutState::dispense()
{
    qDebug()<<"No gumball dispensed";
}
