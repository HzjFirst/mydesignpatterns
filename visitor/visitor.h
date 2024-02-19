#ifndef VISITOR_H
#define VISITOR_H
#include "item.h"
#include "order.h"
#include "customer.h"

#include <QDebug>

class Visitor {
public:
    virtual void visit(Customer &customer) = 0;
    virtual void visit(Order &order) = 0;
    virtual void visit(Item &item) = 0;
};

class GeneralReport : public Visitor
{
    int customersNo = 0;
    int ordersNo = 0;
    int itemsNo = 0;

public:
    void visit(Customer &customer);

    void visit(Order &order);

    void visit(Item &item);

    void displayResults();
};

void visitor_demo();

#endif // VISITOR_H
