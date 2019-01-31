#pragma once
#include <vector>
#include <string>
#include "Observer.h"

using namespace std;

class Subject
{
private:
	vector<Observer*> _observers;
public:
	//constructor
	Subject();
	//deconstructor
	virtual ~Subject();
	//accessors

	//mutators

	//other functions
	virtual void attach(Observer* obs);
	virtual void detach(Observer* obs);
	virtual void notify(string message);
};