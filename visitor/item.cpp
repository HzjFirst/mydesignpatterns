#include "item.h"
#include "visitor.h"

Item::Item() {}

Item::Item(std::string &&n):name(n)
{

}

std::string Item::getName()
{
    return name;
}

void Item::accept(Visitor &visitor)
{
    visitor.visit(*this);
}
