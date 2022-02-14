#include "Territory.h"
#include "Hand.h"
#include "OrderList.h"
#include <list>
#include <iostream>

using namespace std;

class Player {


public:
	//Player's territories
	Player();
	Player(list<Territory> territoriesOwned, Hand playerHand, OrderList orderlist);
	

	list<Territory> toDefend( );	// returns list of territories
	list<Territory> toAttack( );	// returns list of territories
	void issueOrder();	// returns void, creates object and adds its to the list of order. // Need Part 3

	list<Territory> getTerritories();
	Hand getHand();
	OrderList getOrderList();

	

private:
	Hand hand; // Need Part4
	OrderList orderList;
	list<Territory> territories; // Need Part1
};


ostream& operator<<(ostream& os, list<Territory>& territories);
ostream& operator<<(ostream& os, Player& player);
void print(list<Territory> territories);
void printPlayer(Player player);