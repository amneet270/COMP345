#pragma once
#include <iostream>
#include<vector>
using namespace std;



class Card{
public:
    // Constructor that initializes the card as the specified card type
    Card(string tpye);
    // Constructor that initializes the card to a random card type
    Card( );
    // Copy Constructor
    void play();
    string getCardType();
private:

    string card_type;

};

class Deck
{
private:
    vector<Card*> deck_of_cards;
public:
    Deck(int);
    ~Deck();
        string c_type_card[5]={  "airlift","bomb", "blockade" , "diplomacy", "reinforcement"};
    Card* draw();// draw random card 
    void return_card(Card*);
 };

 class hand
 {
 private:
     vector<Card*> in_hand_cards;
     int num_of_cards;
 public:
    //hand(/* args */);
    hand();
    void add_card(Card* c);
    void remove_from_hand(int);
    vector<Card*>& getcard();

 };
 

 

