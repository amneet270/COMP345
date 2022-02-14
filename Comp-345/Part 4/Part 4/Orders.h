#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>



//Base class
class Order {

public:
	Order();
	~Order();
	void virtual validate();
	void virtual execute();
	void setName(std::string s);
	void setValid(bool b);
	void setEffect(std::string e);
	std::string getEffect() const{ return effect; };
	std::string getName() const{ return name; };
	bool getValid() const{ return valid; };


private:

	std::string name;
	std::string effect;
	bool valid;

};



//derived classes
class DeplaoyOrder : public Order {

public:

	DeplaoyOrder();
	~DeplaoyOrder();
	void validate();
	void execute();


private:



};

class AdvanceOrder : public Order {

public:

	AdvanceOrder();
	~AdvanceOrder();
	void validate();
	void execute();


private:

};
class BombOrder : public Order {

public:

	BombOrder();
	~BombOrder();
	void validate();
	void execute();


private:

};
class BlockadeOrder : public Order {

public:

	BlockadeOrder();
	~BlockadeOrder();
	void validate();
	void execute();


private:

};
class AirliftOrder : public Order {

public:

	AirliftOrder();
	~AirliftOrder();
	void validate();
	void execute();


private:

};
class NegotiateOrder : public Order {

public:

	NegotiateOrder();
	~NegotiateOrder();
	void validate();
	void execute();


private:

};


//List of orders class
class OrderList {

public:
	OrderList();
	~OrderList();
	void remove(int x);
	void move(int x, int y);
	void add(Order* o);
	std::vector<Order*> orderQueue;


private:

	

};
