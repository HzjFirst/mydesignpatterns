#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H
#include "subject.h"

class CurrentConditionsDisplay : public Observer
{
public:
    CurrentConditionsDisplay(Subject *sub);
    ~CurrentConditionsDisplay();
    void update(float t, float d, float p);
};

#endif // CURRENTCONDITIONSDISPLAY_H
