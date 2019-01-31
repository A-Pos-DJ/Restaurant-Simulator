#pragma once
#include <iostream>
#include <string>
#include "RestaurantHandler.h"
#include "Clock.h"
#include "Observer.h"
using namespace std;

class Employee : public Observer
{
private:
	string name;						//name of the employee

//    **represented by a value 1 through 10**
	int experienceLvl = 0,				//represents how long the employee takes to make orders &/or if they get messed up
		diligentLvl = 0,				//represents what the employee does durring long breaks &/or if orders get messed up
		charmLvl = 0;					//represents how satisfied customers are after interaction with the employee (if applicable)

	int waitLvl = 0,					//represents time passed before preforming next activity
		busyLvl = 0;					//represents how long an employee is taking to work on a task

	bool busy = false;					//represents if the employee is currently busy with something


public:
	//constructor
	Employee();

	//deconstructor
	~Employee();

	//accessors
	string getName();
	int getExperienceLvl();
	int getDiligentLvl();
	int getCharmLvl();
	int getWaitLvl();
	int getBusyLvl();
	bool getBusyVal();

	//mutators
	void setName(string s);
	void setExperienceLvl(int i);
	void setDiligentLvl(int i);
	void setCharmLvl(int i);
	void setWaitLvl(int i);
	void setBusyLvl(int i);
	void setBusyVal(bool b);

	//other functions
	void addWaitLvl();
	void observe();
	void stopObserve();
	void virtual update(string message) ;
};