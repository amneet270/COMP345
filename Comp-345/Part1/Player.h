#pragma once

#include "Map.h"
#include "Cards.h"
#include "Order.h"
#include <list>
#include <iostream>


using namespace std;

class Territory;
class Orderslist;
class Order;
class Player {


public:
	//Player's territories
	Player(int,string); // Constructor
	~Player(); // Destructor
	Player(const Player& player);  // Copy constructor
	// Player& operator = (const Player& player);
	//Player(vector<Territory*>& territoriesOwned, Hand* playerHand, OrderList* orderlist);
	friend std::ostream &operator<<(std::ostream &output, Player& player); //stream insertion operator


	vector<Territory*>&  toDefend();	// returns a pointer of list of territories
	vector<Territory*>&  toAttack();	// returns a pointer of list of territories
	vector<Territory*>&  countries_owned();	// returns a pointer of list of territories
	void add_country_to_attack(Territory* t);
	void add_country_to_defend(Territory* t);
	void add_country_to_owned(Territory* t);
	int getId(){return id;}

	void issueOrder(Order* order);	// creates object and adds its to the list of order. 

	hand* getHand();
	void add_to_hand(Card* c);
	Orderslist* getOrderList();

	int getNumof_army();
	void setNumof_army(int);
	void addarmy(int);


private:
	//static int incrementor;
	int id;
	hand* phand; // Need Part4
	Orderslist* orderList;
	int army_pool;
	vector<Territory*> territories_belong; // Need Part1
	vector<Territory*> territories_to_attack;
	vector<Territory*> territories_to_defend;
	string player_name;
};


//Player& Player::operator = (const Player& player);

// ostream& operator<<(ostream& os, list<Territory>& territories);
// ostream& operator<<(ostream& os, Player& player);



// void print(list<Territory> territories);
// void printPlayer(Player player);

//TEST