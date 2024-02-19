#ifndef STATISTICSDISPLAY_H
#define STATISTICSDISPLAY_H
#include "subject.h"

class StatisticsDisplay : public Observer
{
public:
    StatisticsDisplay(Subject *weatherData);
    ~StatisticsDisplay();
    void update(float temp, float humidity, float pressure);
};

#endif // STATISTICSDISPLAY_H
