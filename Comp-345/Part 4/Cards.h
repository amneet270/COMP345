//still under work
#include <iostream>
#include <vector>
#include <queue>



using namespace std;

#pragma once
class Cards;
class Deck;
class Hand;

enum TypeOfCard
{
	Bomb, Reinforcement, Blockade, Airlift, Diplomacy
};
class Cards
{
public:
	Cards();
	~Cards();
	Cards(TypeOfCard TOC);
	Cards(const Cards& c);
	friend ostream& operator <<(ostream& output, const Cards& card);
	void Play();
		
private:
	TypeOfCard* cardtype;
};

class Deck
{
public:
	Deck();
	Deck(const Deck& d);
	~Deck();
	Cards Draw(Hand& hand);
	void addtoCardDeck(TypeOfCard const toc);
	void removefromCardDeck();
	

private:
	queue<Cards*> CardDeck;

};
class Hand
{
public:
	Hand();
	Hand(const Hand& h);
	~Hand();
	void removefromHand();


private:
	vector<Cards*> hand;
};
