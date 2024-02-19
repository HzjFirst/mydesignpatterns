#include "currentconditionsdisplay.h"
#include <QDebug>

CurrentConditionsDisplay::CurrentConditionsDisplay(Subject *sub)
{
    sub->registerObserver(this);
}

CurrentConditionsDisplay::~CurrentConditionsDisplay()
{
    qDebug()<<"CurrentConditionDisplay delete";
}

void CurrentConditionsDisplay::update(float t, float d, float p)
{
    qDebug()<<"StatisticsDisplay.upate: "<<t<<" "<<d<<" "<<p;
}
