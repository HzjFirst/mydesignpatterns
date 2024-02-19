#include "weatherdata.h"
#include "statisticsdisplay.h"
#include "currentconditionsdisplay.h"
#include <QDebug>

WeatherData::WeatherData()
{

}

WeatherData::~WeatherData()
{
    for(auto &iter : observers)
    {
        if(iter)
            delete iter;
    }
    observers.clear();
}

void WeatherData::setMeasurements(float tem, float hum, float pres)
{
    temperature = tem;
    humidity = hum;
    pressure = pres;
    notifyObserver();
}

void WeatherData::registerObserver(Observer* o)
{
    observers.push_back(o);
}

void WeatherData::removeObserver(Observer *o)
{
    auto iter = std::find(observers.begin(),observers.end(),o);
    if(iter != observers.end())
    {
        delete *iter;
        observers.erase(iter);
    }
}

void WeatherData::notifyObserver()
{
    for(auto & o : observers)
    {
        o->update(temperature,humidity,pressure);
    }
}

void observer_demo()
{
    WeatherData data;
    StatisticsDisplay *sd = new StatisticsDisplay(&data);
    CurrentConditionsDisplay *cd = new CurrentConditionsDisplay(&data);
    data.setMeasurements(0.0,0.0,0.0);
    data.setMeasurements(1.0,1.0,1.0);
    data.removeObserver(sd);
    qDebug()<<"houzhijie";
    data.removeObserver(cd);
    qDebug()<<"houzhijie1";
}
