#pragma once
#include "Player.h"
#include "Map.h"
#include "Cards.h"
#include <vector>
// Default Constructor: Makes a new Hand, Orderlist and empty list of territories
Player::Player(int idd, string player_name)
{
	this->player_name = player_name;
	this->id = idd;
	phand = new hand();
	orderList = new Orderslist();
}

// Destructor: avoid dangling pointers
Player::~Player()
{
	delete phand;
	delete orderList;
	for (int i = 0; i < territories_belong.size(); i++)
	{
		delete territories_belong[i];
	}
	for (int i = 0; i < territories_to_attack.size(); i++)
	{
		delete territories_to_attack[i];
	}
	for (int i = 0; i < territories_to_defend.size(); i++)
	{
		delete territories_to_defend[i];
	}
}

int Player::getNumof_army()
{
	return army_pool;
}
void Player::setNumof_army(int addition)
{
	army_pool += addition;
}
hand* Player::getHand(){return phand;}
vector<Territory *> &Player::toDefend()
{
	return territories_to_defend;
}
vector<Territory *> &Player::toAttack()
{
	return territories_to_attack;
}
vector<Territory *> &Player::countries_owned()
{
	return territories_belong;
}

void Player::add_country_to_attack(Territory *t)
{
	territories_to_attack.push_back(t);
}
void Player::add_country_to_defend(Territory *t)
{
	territories_to_defend.push_back(t);
}
void Player::add_country_to_owned(Territory *t)
{
	territories_belong.push_back(t);
}

void Player::addarmy(int add_army) { this->army_pool += add_army; }
void Player::add_to_hand(Card* c)
{
	phand->add_card(c);
}