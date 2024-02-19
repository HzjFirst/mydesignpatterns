#ifndef ELEMENT_H
#define ELEMENT_H
#include <vector>
#include <string>

class Visitor;

class Element
{
public:
    Element() {}

    virtual void accept(Visitor &visitor) = 0;
};

#endif // ELEMENT_H
