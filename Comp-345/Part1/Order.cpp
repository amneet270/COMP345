#pragma once
#include <iostream>
#include <vector>
#include "Order.h"
using namespace std;
Order::~Order(){}
Order::Order(string type)
{
	this->type = type;
}
string Order::gettype() 
{
	return type;
}
DiployeOrder::DiployeOrder() : Order("diploy")
{
}
bool DiployeOrder::validate()
{ 
	// bool x =find(countries.begin(),countries.end(),test) !=countries.end();
	// cout <<"-------------------";
	// cout << x<< endl;
	return true;
	
}
void DiployeOrder::execute( )
{
	// int army_percontinent=p1->getNumof_army()/p1->countries_owned().size();
	// int remainder_of_countries=p1->getNumof_army()/p1->countries_owned().size();

	// for(int i = 0;i<p1->countries_owned().size();i++)
	// {
	// 	// if(validate(p1,countries)&& i==0){
	// 	// 	p1->countries_owned()[i]->setNum_of_armies(p1->countries_owned()[i]->getNum_of_armies()+army_percontinent+remainder_of_countries);
	// 	// }
	// 	// else if (validate(p1,countries))
	// 	// {
	// 	// 	p1->countries_owned()[i]->setNum_of_armies(p1->countries_owned()[i]->getNum_of_armies()+army_percontinent);
	// 	// }

	// }

	// p1->setNumof_army(0);
	
	
}

AdvanceOrder::AdvanceOrder() : Order("advance")
{
}
bool AdvanceOrder::validate()
{return true;
}
void AdvanceOrder::execute()
{
}

bombOrder::bombOrder() : Order("bomb")
{
}
bool bombOrder::validate()
{return true;
}
void bombOrder::execute()
{
}
blockadeOrder::blockadeOrder() : Order("blockade")
{
}
bool blockadeOrder::validate()
{return true;
}
void blockadeOrder::execute()
{
}

airliftOrder::airliftOrder() : Order("airlift")
{
}
bool airliftOrder:: validate()
{return true;
}
void airliftOrder::execute()
{
}

negociationOrder::negociationOrder() : Order("negociation")
{
}
bool negociationOrder::validate()
{return true;
}
void negociationOrder:: execute(){
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

	return orderlist;

}
void Orderslist::seeorders(){

}

