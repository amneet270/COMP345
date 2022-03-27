#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Order
{
private:
    string type;

public:
    vector<string> type_of_orders = {"deploy", "advance", "bomb", "Blockade", "airlift", "negotiate"};
    Order();
    Order(string type);
    ~Order();

    string gettype();
    bool validate(); // to validate an order
    void execute();
};

class DiployeOrder : public Order
{
private:
    /* data */
public:
    DiployeOrder(/* args */);
    ~DiployeOrder();
    bool validate();
    void execute();
};

class AdvanceOrder : public Order
{
private:
    /* data */
public:
    AdvanceOrder(/* args */);
    ~AdvanceOrder();
    bool validate();
    void execute();
};

class BoomOrder : public Order
{
private:
    /* data */
public:
    BoomOrder(/* args */);
    ~BoomOrder();
    bool validate();
    void execute();
};
class Blockade : public Order
{
private:
    /* data */
public:
    Blockade(/* args */);
    ~Blockade();
    bool validate();
    void execute();
};

class AirOrder : public Order
{
private:
    /* data */
public:
    AirOrder(/* args */);
    ~AirOrder();
    bool validate();
    void execute();
};

class NegoOrder : public Order
{
private:
    /* data */
public:
    NegoOrder(/* args */);
    ~NegoOrder();
    bool validate();
    void execute();
};

class Orderslist
{
private:
    vector<Order *> orderlist;

public:
    Orderslist();
    ~Orderslist();
    void addOrder(Order *Order); // to add order to the orders list
    void remove(int position);   // to remover an order from the list by receiving the index number.
    void move(int position_one, int position_tw0);
    vector<Order *> &getlist();
    void seeorders();
};
