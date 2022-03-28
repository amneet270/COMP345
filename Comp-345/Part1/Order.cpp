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
bool DiployeOrder::validate(Player * p1, vector<Territory*>& countries, Deck* deck,Territory* test)
{ 
	bool x =find(countries.begin(),countries.end(),test) !=countries.end();
	// if(x){
	// 	cout<< "true"<<endl;
	// }
	// else {
	// 	cout<< "false"<<endl;

	// }
	return x;
	
}
void DiployeOrder::execute( Player * p1, vector<Territory*>& countries, Deck* deck)
{
	int army_percontinent=p1->getNumof_army()/p1->countries_owned().size();
	int remainder_of_countries=p1->getNumof_army()/p1->countries_owned().size();

	for(int i = 0;i<p1->countries_owned().size();i++)
	{
		if(validate(p1,p1->countries_owned(),deck,p1->countries_owned()[i])&& i==0){
			p1->countries_owned()[i]->setNum_of_armies(p1->countries_owned()[i]->getNum_of_armies()+army_percontinent+remainder_of_countries);
		}
		else if (validate(p1,p1->countries_owned(),deck,p1->countries_owned()[i]))
		{
			p1->countries_owned()[i]->setNum_of_armies(p1->countries_owned()[i]->getNum_of_armies()+army_percontinent);
		}

	}

	p1->setNumof_army(0);
	
	
}

AdvanceOrder::AdvanceOrder() : Order("advance")
{
}
bool AdvanceOrder::validate(Player * p1, vector<Territory*>& countries, Deck* deck,Territory* test)
{return true;
}
void AdvanceOrder::execute(Player * p1, vector<Territory*>& countries, Deck* deck)
{
}

bombOrder::bombOrder() : Order("bomb")
{
}
bool bombOrder::validate(Player * p1, vector<Territory*>& countries, Deck* deck,Territory* test)
{return true;
}
void bombOrder::execute(Player * p1, vector<Territory*>& countries, Deck* deck)
{
}
blockadeOrder::blockadeOrder() : Order("blockade")
{
}
bool blockadeOrder::validate(Player * p1, vector<Territory*>& countries, Deck* deck,Territory* test)
{return true;
}
void blockadeOrder::execute(Player * p1, vector<Territory*>& countries, Deck* deck)
{
}

airliftOrder::airliftOrder() : Order("airlift")
{
}
bool airliftOrder:: validate(Player * p1, vector<Territory*>& countries, Deck* deck,Territory* test)
{return true;
}
void airliftOrder::execute(Player * p1, vector<Territory*>& countries, Deck* deck)
{
}

negociationOrder::negociationOrder() : Order("negociation")
{
}
bool negociationOrder::validate(Player * p1, vector<Territory*>& countries, Deck* deck,Territory* test)
{return true;
}
void negociationOrder:: execute(Player * p1, vector<Territory*>& countries, Deck* deck){
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

