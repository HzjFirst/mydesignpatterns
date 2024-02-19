#ifndef ORDER_H
#define ORDER_H
#include "element.h"
#include "item.h"

class Order : public Element
{
    std::string name;
    std::vector<Item> items;
public:
    Order();
    Order(std::string &&n);
    Order(std::string &&n1, std::string &&n2);

    std::string getName();
    void addItem(Item &i);
    void addItem(Item &&i);

    void accept(Visitor &visitor);
};

#endif // ORDER_H
