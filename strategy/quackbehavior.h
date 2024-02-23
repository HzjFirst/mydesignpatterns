#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H
#include <QDebug>

class QuackBehavior
{
public:
    QuackBehavior() {}

    virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
    Quack() {}

    void quack() { qDebug() << "quack!"; }
};

class Squeak : public QuackBehavior
{
public:
    Squeak() {}

    void quack() { qDebug() << "squeak!"; }
};


#endif // QUACKBEHAVIOR_H
