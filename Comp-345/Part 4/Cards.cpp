#include "Cards.h"
#include <iostream>
#include <vector>

using namespace std;
#pragma once

Cards::Cards()
{

}
Cards::~Cards()
{

}



Cards::Cards(TypeOfCard TOC)
{
	this->cardtype = new TypeOfCard(TOC);
}
//copy constructor
Cards::Cards(const Cards& c)
{
	this->cardtype = new TypeOfCard(*c.cardtype);
}
	

void Cards::Play()
{

	cout << "Plays card" << endl;

}

TypeOfCard* Cards::getType()
{
	return (this->cardtype);
}

Deck::Deck()
{

}

Deck::Deck(const Deck& d)
{
	this->CardDeck = queue<Cards*>{};
}

Deck::~Deck()
{

}
//draws card from deck and returns the picked card
Cards Deck::Draw(Hand& hand)
{
	Cards picked = *this->CardDeck.front();
	cout << "Draws card from deck" << endl;
	TypeOfCard* toc = picked.getType();
	hand.addtoHand(*toc);
	return picked;
}
//adds a card to the deck
void Deck::addtoCardDeck(TypeOfCard const toc)
{
	CardDeck.push(new Cards(toc));
	cout << "Adds card to deck" << endl;

}
//removes a card from the deck
void Deck::removefromCardDeck()
{
	CardDeck.pop();
	cout << "removes card from deck" << endl;
}


ostream& operator<<(ostream& output, const Cards& card)
{
	switch (*card.cardtype) 
	{
	case TypeOfCard::Airlift:
		return cout << "Type of card is Airlift";
		break;
	case TypeOfCard::Blockade:
		return cout << "Type of card is Blockade";
		break;
	case TypeOfCard::Bomb:
		return cout << "Type of card is Bomb";
		break;
	case TypeOfCard::Diplomacy:
		return cout << "Type of card is Diplomacy";
		break;
	case TypeOfCard::Reinforcement:
		return cout << "Type of card is Reinforcement";
		break;
	}
	return output;
}

Hand::Hand()
{
	this->hand = std::vector<Cards*>{};
}

Hand::Hand(const Hand& h)
{
	hand = h.hand;
}

Hand::~Hand()
{

}

void Hand::addtoHand(TypeOfCard const& toc)
{
	cout << "add card to hand" << endl;
}
void Hand::removefromHand()
{
	cout << "remove card from hand" << endl;
}
