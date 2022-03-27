#pragma once
#include <iostream>
#include <vector>
#include "Order.h"
using namespace std;

Order::Order(string type)
{
	this->type = type;
}
string Order::gettype() 
{
	return type;
}
DiployeOrder::DiployeOrder() : Order(type_of_orders[0])
{
}
bool DiployeOrder::validate()
{
}
void DiployeOrder::execute()
{
}

AdvanceOrder::AdvanceOrder() : Order(type_of_orders[1])
{
}
bool AdvanceOrder::validate()
{
}
void AdvanceOrder::execute()
{
}

BoomOrder::BoomOrder() : Order(type_of_orders[2])
{
}
bool BoomOrder::validate()
{
}
void BoomOrder::execute()
{
}
Blockade::Blockade() : Order(type_of_orders[3])
{
}
bool Blockade::validate()
{
}
void Blockade::execute()
{
}

AirOrder::AirOrder() : Order(type_of_orders[4])
{
}
bool AirOrder:: validate()
{
}
void AirOrder::execute()
{
}

NegoOrder::NegoOrder() : Order(type_of_orders[5])
{
}
bool NegoOrder::validate()
{
}
void NegoOrder:: execute(){
}

Orderslist::Orderslist(){

}
Orderslist::~Orderslist(){

}
void Orderslist::addOrder(Order *order){
	orderlist.push_back(order);
} // to add order to the orders list
void Orderslist::remove(int position){
	//orderlist[position].;
}   // to remover an order from the list by receiving the index number.
void Orderslist::move(int position_one, int position_two){
	Order *temp= orderlist[position_one];
	orderlist[position_one]=orderlist[position_two];
	orderlist[position_two]=temp;
}
vector<Order *>& Orderslist::getlist(){
	for(int i =0;i<orderlist.size();i++)
	{
		cout<<orderlist[i]->gettype()<<endl;
	}
	return orderlist;

}
void Orderslist::seeorders(){

}

