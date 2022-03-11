#pragma once
#include "Player.h"

//Default Constructor: Makes a new Hand, Orderlist and empty list of territories
Player::Player() {
	hand = new Hand();
	orderList = new OrderList();
	territories = {};
}
//Constructor: Takes a list of territories, a playerhand and orderlist
Player::Player(list<Territory>* territoriesOwned, Hand* playerHand, OrderList* orderList) {
	territories = territoriesOwned;
	hand = playerHand;
	this->orderList = orderList;
}

//Destructor: avoid dangling pointers
Player::~Player() {
	hand = NULL;
	orderList = NULL;
	territories = NULL;
}

// assignment operator to make deep copy
Player& Player::operator = (const Player& player) {
	this->hand = new Hand(*(player.hand));
	this->orderList = new OrderList(*(player.orderList));
	this->territories = new list<Territory>(*(player.territories));
	return *this;
}


// Copy constructor to make deep copy
Player::Player(const Player& player) {
	this->hand = new Hand(*(player.hand));
	this->orderList = new OrderList(*(player.orderList));
	this->territories = new list<Territory>(*(player.territories));
}




//Return a random list of territories to defend.
list<Territory>* Player::toDefend() {

	list<Territory>* territoriesToDefend = new list<Territory>;


	for (Territory territory : *territories)
	{
		int randomNumber = (rand() % 3) + 0;
		if (randomNumber) {

			territoriesToDefend->push_front(territory);
		}

	}




	return territoriesToDefend;
}

//Return a pointer to a random list of territories to attack.
list<Territory>* Player::toAttack() {

	list<Territory>* territoriesToAttack = new list<Territory>;

	int randomNumber;

	randomNumber = (rand() % 42) + 1;
	for (Territory territory : *territories)
	{
		if (territory.territoryNumber == randomNumber) {
			randomNumber = (rand() % 42) + 1;
			break;
		}
	}
	Territory territory1 = Territory(randomNumber);

	randomNumber = (rand() % 42) + 1;
	for (Territory territory : *territories)
	{
		if (territory.territoryNumber == randomNumber) {
			randomNumber = (rand() % 42) + 1;
			break;
		}
	}
	Territory territory2 = Territory(randomNumber);

	randomNumber = (rand() % 42) + 1;
	for (Territory territory : *territories)
	{
		if (territory.territoryNumber == randomNumber) {
			randomNumber = (rand() % 42) + 1;
			break;
		}
	}
	Territory territory3 = Territory(randomNumber);

	(*territoriesToAttack).push_front(territory1);
	(*territoriesToAttack).push_front(territory2);
	(*territoriesToAttack).push_front(territory3);


	return territoriesToAttack;
}

//create an Order object and adds it in the player's Orderlist
void Player::issueOrder()
{
	Order newOrder = Order();
	(*orderList).orders.push_front(newOrder);
}

//Get player's territories
list<Territory>* Player::getTerritories() {
	return territories;
}

//Get player's OrderList
OrderList* Player::getOrderList() {
	return orderList;
}

//Get player's Hand
Hand* Player::getHand() {
	return hand;
}


//Custom << operator to print
ostream& operator<<(ostream& os, list<Territory>& territories)
{
	for (Territory territory : territories)
	{
		if (territories.size() == 1) {
			os << "Territory #" << territory.territoryNumber << ", ";
		}
		else {
			os << "Territory #" << territory.territoryNumber << ", ";
		}
	}
	return os;
}




void print(list<Territory> territories) {
	cout << territories << endl;
}


//Custom << operator to print
ostream& operator<<(ostream& os, Player& player) {

	os << "Player Hand: (cards)" << endl;
	os << "Player has " << (*player.getTerritories()).size() << " terrority(ies)" << endl;
	print((*player.getTerritories()));
	//os << "Player has " << player.orderList.orders.size() << " orders in the orderList" << "\n";
	//os << "Territories to defend: " << player.toDefend() << "\n";

	return os;

}
//Printing owned territories, to attack Terr, to defend terr, and orderlist.
void printPlayer(Player player) {
	cout << player << endl;
	cout << "Territories to attack: " << endl;
	print((*player.toAttack()));
	cout << "Territories to defend: " << endl;
	print((*player.toDefend()));
	cout << "OrderList has: " << (*player.getOrderList()).orders.size() << " orders" << endl;
	cout << "IssueOrder() " << endl;
	player.issueOrder();
	cout << "OrderList has now: " << (*player.getOrderList()).orders.size() << " orders" << endl;
}
//TEST