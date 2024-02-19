#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include "subject.h"
#include <vector>

class Observer;

class WeatherData : public Subject
{
    std::vector<Observer*> observers;
    float temperature = 0.0;
    float humidity = 0.0;
    float pressure =0.0;
public:
    WeatherData();
    ~WeatherData();

    void setMeasurements(float tem, float hum, float pres);
    void registerObserver(Observer *o) override;
    void removeObserver(Observer* o) override;
    void notifyObserver() override;
};

void observer_demo();

#endif // WEATHERDATA_H
