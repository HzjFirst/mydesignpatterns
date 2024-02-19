#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "element.h"
#include "order.h"

class Customer : public Element
{
    std::string name;
    std::vector<Order> orders;

public:
    Customer();
    Customer(std::string &n);
    Customer(std::string &&n);

    std::string getName();
    void addOrder(Order &o);
    void addOrder(Order &&o);

    void accept(Visitor &v);
};

class CustomerGroup
{
    std::vector<Customer> customers;

public:
    void accept(Visitor& visitor);

    void addCustomer(Customer &customer);
};

#endif // CUSTOMER_H
