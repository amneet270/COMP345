#include "Orders.h"

//all derived classes follow the same scheme
//constructor
NegotiateOrder::NegotiateOrder()
{

	this->setName("Negotiate");
	this->setValid(true);
	this->setEffect(this->getName());
}

//destructor
NegotiateOrder::~NegotiateOrder()
{

	

}


//validate an order, dummy class for now
void NegotiateOrder::validate()
{
	if (this->getValid())
		std::cout << "This " << this->getName() << " order is valid." << std::endl;
	else {

		std::cout << "Not a valid order." << std::endl;

	}

}


//execute order, dummy class for now
void NegotiateOrder::execute()
{

	std::cout << "Executing order " << this->getEffect() << std::endl;

}

AirliftOrder::AirliftOrder()
{

	this->setName("Airlift");
	this->setValid(true);
	this->setEffect(this->getName());
}

AirliftOrder::~AirliftOrder()
{
}

void AirliftOrder::validate()
{

	if (this->getValid())
		std::cout << "This " << this->getName() << " order is valid." << std::endl;
	else {

		std::cout << "Not a valid order." << std::endl;

	}
}

void AirliftOrder::execute()
{

	std::cout << "Executing order " << this->getEffect() << std::endl;

}

BlockadeOrder::BlockadeOrder()
{

	this->setName("Blockade");
	this->setValid(true);
	this->setEffect(this->getName());
}

BlockadeOrder::~BlockadeOrder()
{



}

void BlockadeOrder::validate()
{

	if (this->getValid())
		std::cout << "This " << this->getName() << " order is valid." << std::endl;
	else {

		std::cout << "Not a valid order." << std::endl;

	}
}

void BlockadeOrder::execute()
{

	std::cout << "Executing order " << this->getEffect() << std::endl;

}

BombOrder::BombOrder()
{

	this->setName("Bomb");
	this->setValid(true);
	this->setEffect(this->getName());
}

BombOrder::~BombOrder()
{
}

void BombOrder::validate()
{

	if (this->getValid())
		std::cout << "This " << this->getEffect() << " order is valid." << std::endl;	
	
	
	else {

		std::cout << "Not a valid order." << std::endl;

	}
}

void BombOrder::execute()
{

	std::cout << "Executing order " << this->getEffect() << std::endl;

}

AdvanceOrder::AdvanceOrder()
{

	this->setName("Advance");
	this->setValid(true);
	this->setEffect(this->getName());
}

AdvanceOrder::~AdvanceOrder()
{
}

void AdvanceOrder::validate()
{

	if (this->getValid())
		std::cout << "This " << this->getName() << " order is valid." << std::endl;
	else {

		std::cout << "Not a valid order." << std::endl;

	}
}

void AdvanceOrder::execute()
{

	std::cout << "Executing order " << this->getEffect() << std::endl;

}

DeplaoyOrder::DeplaoyOrder()
{

	this->setName("Deploy");
	this->setValid(true);
	this->setEffect(this->getName());
}

DeplaoyOrder::~DeplaoyOrder()
{
}

void DeplaoyOrder::validate()
{

	if (this->getValid())
		std::cout << "This " << this->getName() << " order is valid." << std::endl;
	else {

		std::cout << "Not a valid order." << std::endl;

	}
}

void DeplaoyOrder::execute()
{

	std::cout << "Executing order " << this->getEffect() << std::endl;

}


//base class, not much implementation besides getters and setters
Order::Order()
{
}

Order::~Order()
{
}

void Order::validate()
{
}

void Order::execute()
{
}

void Order::setName(std::string s)
{

	this->name = s;

}

void Order::setValid(bool b)
{

	this->valid = b;

}

void Order::setEffect(std::string e)
{

	this->effect = e;

}


//Orderlist class
OrderList::OrderList()
{


}

OrderList::~OrderList()
{
}

//remove an order at index x
void OrderList::remove(int x)
{

	this->orderQueue.erase(orderQueue.begin() + x);

}


//move an order from index x to index y
void OrderList::move(int x, int y)
{
	Order* temp;
	temp = (this->orderQueue[x]);
	this->orderQueue.erase(orderQueue.begin() + x);
	this->orderQueue.insert(orderQueue.begin() + y, temp);


}


//add an order to the back of the list
void OrderList::add(Order* o)
{

	this->orderQueue.push_back(o);

}
