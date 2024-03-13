#include "hasquarterstate.h"
#include "gumballmachine.h"

HasQuarterState::HasQuarterState(GumballMachine *me): State(me)
{

}

HasQuarterState::~HasQuarterState()
{

}

void HasQuarterState::insertQuarter()
{
    qDebug() << "You can't inset another quarter";
}

void HasQuarterState::ejectQuarter()
{
    qDebug() << "Quarter returned";
    _machine->setState(_machine->getNoQuarterState());
}

void HasQuarterState::turnCrank()
{
    qDebug() << "You turned...";
    _machine->setState(_machine->getSoldState());
}

void HasQuarterState::dispense()
{
    qDebug() << "No gumball dispensed";
}
