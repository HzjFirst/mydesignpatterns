#include "statisticsdisplay.h"
#include <QDebug>

StatisticsDisplay::StatisticsDisplay(Subject *weatherData)
{
    weatherData->registerObserver(this);
}

StatisticsDisplay::~StatisticsDisplay()
{
    qDebug()<<"statis delete";
}

void StatisticsDisplay::update(float temp, float humidity, float pressure)
{
    qDebug()<<"StatisticsDisplay.upate: "<<temp<<" "<<humidity<<" "<<pressure;
}
