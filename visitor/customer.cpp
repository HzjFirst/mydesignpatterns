#include "customer.h"
#include "visitor.h"

Customer::Customer() {}

Customer::Customer(std::string &n):name(n)
{

}

Customer::Customer(std::string &&n):name(n)
{

}

std::string Customer::getName()
{
    return name;
}

void Customer::addOrder(Order &o)
{
    orders.push_back(o);
}

void Customer::addOrder(Order &&o)
{
    orders.push_back(o);
}

void Customer::accept(Visitor &v)
{
    v.visit(*this);
    for (auto &order : orders)
    {
        order.accept(v);
    }
}

void CustomerGroup::accept(Visitor &visitor)
{
    for (Customer& cs: customers)
    {
        cs.accept(visitor);
    }
}

void CustomerGroup::addCustomer(Customer &customer)
{
    customers.push_back(customer);
}
