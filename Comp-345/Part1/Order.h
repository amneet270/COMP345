#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
#include"Player.h"
using namespace std;
class Player;
class Order
{
private:
    string type;

public:
    //vector<string> type_of_orders = {"deploy", "advance", "bomb", "blockadeOrder", "airlift", "negotiate"};
    Order();
    Order(string type);
    virtual ~Order();

    string gettype();
    virtual bool validate() = 0; // to validate an order
    virtual void execute() = 0;
};

class DiployeOrder : public Order
{
private:
    /* data */
public:
    DiployeOrder(/* args */);
    ~DiployeOrder(){}
    bool validate();
    void execute();
};

class AdvanceOrder : public Order
{
private:
    /* data */
public:
    AdvanceOrder(/* args */);
    ~AdvanceOrder(){}
    bool validate();
    void execute();
};

class bombOrder : public Order
{
private:
    /* data */
public:
    bombOrder(/* args */);
    ~bombOrder(){}
    bool validate();
    void execute();
};
class blockadeOrder : public Order
{
private:
    /* data */
public:
    blockadeOrder(/* args */);
    ~blockadeOrder(){}
    bool validate();
    void execute();
};

class airliftOrder : public Order
{
private:
    /* data */
public:
    airliftOrder(/* args */);
    ~airliftOrder(){}
    bool validate();
    void execute();
};

class negociationOrder : public Order
{
private:
    /* data */
public:
    negociationOrder(/* args */);
    ~negociationOrder(){}
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
