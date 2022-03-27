#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Cards.h"

Card::Card()
{
}
void Card::play() {}
Card::Card(string type)
{
    this->card_type = type;
}
string Card::getCardType()
{
    return card_type;
}
Deck::Deck(int num_of_cards)
{

    srand(time(0));
    int random_num;
    for (int i = 0; i < num_of_cards; i++)
    {
        random_num = rand() % 5;
        deck_of_cards.push_back(new Card(c_type_card[random_num]));
    }
}
Card *Deck::draw()
{
    srand(time(0));
    int random_index = rand() % deck_of_cards.size();
    Card *x = deck_of_cards[random_index];
    deck_of_cards.erase(deck_of_cards.begin() + random_index);
    return x;
}

hand::hand()
{
}

void hand::add_card(Card *c)
{

    in_hand_cards.push_back(c);
}
void hand::remove_from_hand(int _index) {}
Card *hand::getcard(int _index) { return in_hand_cards[_index]; }