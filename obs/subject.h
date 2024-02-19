#ifndef SUBJECT_H
#define SUBJECT_H

class Observer;

class Subject
{
public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObserver() = 0;
};

class Observer
{
public:
    virtual ~Observer() {};
    virtual void update(float , float , float) = 0;
};

#endif // SUBJECT_H
