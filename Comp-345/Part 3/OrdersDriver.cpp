#pragma once
#include "Orders.h"
#include <iostream>
#include <iterator>


void main() {

	//Create objects
	NegotiateOrder* n =  new NegotiateOrder();
	AirliftOrder* a = new AirliftOrder();
	BombOrder* bo = new BombOrder();
	BlockadeOrder* bl = new BlockadeOrder();
	DeplaoyOrder* d = new DeplaoyOrder();
	AdvanceOrder* ad = new AdvanceOrder();

	OrderList list;


	//add them to vector
	list.add(n);
	list.add(a);
	list.add(bo);
	list.add(bl);
	list.add(d);
	list.add(ad);

	//iterator
	std::vector<Order*>::iterator it;


	//Demostrate iterating through vector
	for (it = list.orderQueue.begin(); it != list.orderQueue.end(); ++it) {

		(*it)->validate();
		(*it)->execute();

	}

	std::cout << std::endl;


	//Demonstrate moving an order, (order index -> new index)
	list.move(1, 3);

	for (it = list.orderQueue.begin(); it != list.orderQueue.end(); ++it) {

		(*it)->validate();
		(*it)->execute();

	}

	std::cout << std::endl;

	//Demonstrate removing an order
	list.remove(0);

	for (it = list.orderQueue.begin(); it != list.orderQueue.end(); ++it) {

		(*it)->validate();
		(*it)->execute();

	}

	int x;

	std::cin >> x;

}