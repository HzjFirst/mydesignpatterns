#include "visitor.h"

void GeneralReport::visit(Customer &customer)
{
    qDebug()<<customer.getName();
    ++customersNo;
}

void GeneralReport::visit(Order &order)
{
    qDebug() << order.getName();
    ++ordersNo;
}

void GeneralReport::visit(Item &item)
{
    qDebug() << item.getName();
    ++itemsNo;
}

void GeneralReport::displayResults()
{
    qDebug() <<"Number of customers: " + QString::number(customersNo);
    qDebug() <<"Number of orders: " + QString::number(ordersNo);
    qDebug() <<"Number of items: " + QString::number(itemsNo);
}

void visitor_demo()
{
    Customer customer1("customer1");
    customer1.addOrder(Order("order1","item1"));
    customer1.addOrder(Order("Order2","item2"));
    customer1.addOrder(Order("order3","itme3"));

    Order order("order_a");
    order.addItem(Item("item_a1"));
    order.addItem(Item("item_a2"));
    order.addItem(Item("item_a3"));

    Customer customer2("customer2");
    customer2.addOrder(order);

    CustomerGroup customers;
    customers.addCustomer(customer1);
    customers.addCustomer(customer2);

    GeneralReport vistor;
    customers.accept(vistor);
    vistor.displayResults();
}
