#ifndef ITEM_H
#define ITEM_H
#include "element.h"

class Item : public Element
{
    std::string name;
public:
    Item();
    Item(std::string &&n);

    std::string getName();

    void accept(Visitor &visitor);
};

#endif // ITEM_H
