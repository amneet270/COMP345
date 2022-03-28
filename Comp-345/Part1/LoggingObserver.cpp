#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "LoggingObserver.h"

void LogObserver::update(ILoggable* i)
{
	

	if(!out.is_open()){
	
		out.open("gameLog.txt", std::ios_base::app);

	
	}

	out << i->stringToLog();


}

void Subject::attach(Observer * o)
{

	views.push_back(o);

}

void Subject::notify(ILoggable* log)
{

	for (int i = 0; i < views.size(); i++)
		views[i]->update(log);

}

void Observer::update(ILoggable i)
{
}

ILoggable::ILoggable()
{
}

ILoggable::~ILoggable()
{
}
