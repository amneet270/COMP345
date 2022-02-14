#include <iostream>
#include "Player.h"
using namespace std;


int main() {
	//Player::Player(list<Territory> territoriesOwned, Hand playerHand, OrderList orderList) {

	list<Territory> territories1 = {Territory(1),Territory(2),Territory(3) ,Territory(4) };
	list<Territory> territories2 = { Territory(20),Territory(21),Territory(22),Territory(23),Territory(24),Territory(25) };
	list<Territory> territories3 = { Territory(27),Territory(28),Territory(29),Territory(30),Territory(31) };

	Hand hand1 = Hand();
	hand1.cards.push_front(Card());
	Hand hand2 = Hand();
	hand2.cards.push_front(Card());
	hand2.cards.push_front(Card());
	hand2.cards.push_front(Card());
	Hand hand3 = Hand();
	hand3.cards.push_front(Card());
	hand3.cards.push_front(Card());
	hand3.cards.push_front(Card());
	hand3.cards.push_front(Card());
	hand3.cards.push_front(Card());


	OrderList orderList1 = OrderList();
	OrderList orderList2 = OrderList();
	orderList2.orders.push_front(Order());
	OrderList orderList3 = OrderList();
	orderList3.orders.push_front(Order());
	orderList3.orders.push_front(Order());

	Player player1 = Player(territories1, hand1, orderList1);
	Player player2 = Player(territories2, hand2, orderList2);
	Player player3 = Player(territories3, hand3, orderList3);


	cout << "---------------------" << endl;
	cout << "Printing Player1" << endl;
	printPlayer(player1);
	cout << "---------------------" << endl;
	cout << "Printing Player2" << endl;
	printPlayer(player2);
	cout << "---------------------" << endl;
	cout << "Printing Player3" << endl;
	printPlayer(player3);

	return 0;
};


