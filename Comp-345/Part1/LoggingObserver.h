#pragma once
#include <iostream>
#include <vector>
#include <string>

class ILoggable {

public:
	ILoggable();
	~ILoggable();
	 std::string virtual stringToLog() = 0;

private:


};

class Observer {

public:
	void virtual update(ILoggable i);

private:


};

class LogObserver : public Observer {

public:
	void update(ILoggable i);

private:
	std::ofstream out;
	Subject* subj;


};


class Subject {

public:
	void attach(Observer *o);
	void notify(ILoggable *i);

private:

	std::vector<Observer * > views;

};