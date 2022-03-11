#pragma once

#include "Territory.h"
#include "Hand.h"
#include "OrderList.h"
#include <list>
#include <iostream>

using namespace std;

class Player {


public:
	//Player's territories
	Player(); // Constructor
	~Player(); // Destructor
	Player(const Player& player);  // Copy constructor
	Player& operator = (const Player& player);
	Player(list<Territory>* territoriesOwned, Hand* playerHand, OrderList* orderlist);


	list<Territory>* toDefend();	// returns a pointer of list of territories
	list<Territory>* toAttack();	// returns a pointer of list of territories
	void issueOrder();	// creates object and adds its to the list of order. 

	list<Territory>* getTerritories();
	Hand* getHand();
	OrderList* getOrderList();



private:
	Hand* hand; // Need Part4
	OrderList* orderList;
	list<Territory>* territories; // Need Part1
};


//Player& Player::operator = (const Player& player);

ostream& operator<<(ostream& os, list<Territory>& territories);
ostream& operator<<(ostream& os, Player& player);



void print(list<Territory> territories);
void printPlayer(Player player);

//TEST