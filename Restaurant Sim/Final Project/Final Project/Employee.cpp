#include "Employee.h"

//constructor
Employee::Employee()
{

}

//deconstructor
Employee::~Employee()
{

}

//accessors
string Employee::getName()
{
	return name;
}

int Employee::getExperienceLvl()
{
	return experienceLvl;
}

int Employee::getDiligentLvl()
{
	return diligentLvl;
}

int Employee::getCharmLvl()
{
	return charmLvl;
}

int Employee::getWaitLvl()
{
	return waitLvl;
}

int Employee::getBusyLvl()
{
	return busyLvl;
}

bool Employee::getBusyVal()
{
	return busy;
}

//mutators
void Employee::setName(string s)
{
	name = s;
}

void Employee::setExperienceLvl(int i)
{
	experienceLvl = i;
}

void Employee::setDiligentLvl(int i)
{
	diligentLvl = i;
}

void Employee::setCharmLvl(int i)
{
	charmLvl = i;
}

void Employee::setWaitLvl(int i)
{
	waitLvl = i;
}

void Employee::setBusyLvl(int i)
{
	busyLvl = i;
}

void Employee::setBusyVal(bool b)
{
	busy = b;
}


//other functions
void Employee::addWaitLvl()
{
	setWaitLvl(getWaitLvl() + 1);
}

void Employee::observe()
{
	RestaurantHandler::getInstance()->attach(this);
}

void Employee::stopObserve()
{
	RestaurantHandler::getInstance()->detach(this);
}

void Employee::update(string message)
{

}


