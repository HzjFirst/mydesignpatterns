#include "order.h"
#include "visitor.h"

Order::Order() {}

Order::Order(std::string &&n):name(n)
{

}

Order::Order(std::string &&n1, std::string &&n2):name(n1),items{Item(std::move(n2))}
{

}

std::string Order::getName()
{
    return name;
}

void Order::addItem(Item &i)
{
    items.push_back(i);
}

void Order::addItem(Item &&i)
{
    items.push_back(i);
}

void Order::accept(Visitor &visitor)
{
    visitor.visit(*this);

    for(auto &item : items)
    {
        item.accept(visitor);
    }
}
