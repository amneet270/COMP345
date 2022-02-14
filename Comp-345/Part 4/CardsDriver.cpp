#include "Cards.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	Deck deck1;
	deck1.addtoCardDeck(Bomb);
	deck1.addtoCardDeck(Reinforcement);
	deck1.addtoCardDeck(Diplomacy);
	deck1.addtoCardDeck(Airlift);
	deck1.addtoCardDeck(Blockade);

	Hand hand1;

	deck1.Draw(hand1);
	
	//deck1.removefromCardDeck();

	

}
