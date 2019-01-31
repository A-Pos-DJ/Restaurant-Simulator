#include "Customer.h"


//constructor
Customer::Customer()
{

}

Customer::Customer(string _name, int _waitTesty, int _waitMax, int _eatMax)
{
	setName(_name);
	setWaitLvlTesty(_waitTesty);
	setWaitLvlMax(_waitMax);
	setEatLvlMax(_eatMax);
	setWaiting(true);
}

//factory method
Customer* Customer::makeCustomer(string _name, int _waitTesty, int _waitMax, int _eatMax)
{
	return new Customer(_name, _waitTesty, _waitMax, _eatMax);
}

//deconstructor
Customer::~Customer()
{
	drinkOrder.~DrinkMenuItem();					//deconstruct food and drink orders when leaving
	foodOrder.~FoodMenuItem();
	stopObserve();
}

//accessors
string Customer::getName()
{
	return name;
}

int Customer::getWaitLvlTesty()
{
	return waitLvlTesty;
}

int Customer::getWaitLvlMax()
{
	return waitLvlMax;
}

int Customer::getEatLvlMax()
{
	return eatLvlMax;
}

bool Customer::getWaiting()
{
	return waiting;
}

bool Customer::getSeatedVar()
{
	return seated;
}

bool Customer::getOrdered()
{
	return ordered;
}

bool Customer::getFoodReadyVar()
{
	return foodReady;
}

bool Customer::getEating()
{
	return eating;
}

bool Customer::getGoodToGo()
{
	return goodToGo;
}

DrinkMenuItem * Customer::getDrinkOrder()
{
	return &drinkOrder;
}

FoodMenuItem * Customer::getFoodOrder()
{
	return &foodOrder;
}

//mutators
void Customer::setName(string s)
{
	name = s;
}

void Customer::setWaitLvlTesty(int n)
{
	waitLvlTesty = n;
}

void Customer::setWaitLvlMax(int n)
{
	waitLvlMax = n;
}

void Customer::setEatLvlMax(int n)
{
	eatLvlMax = n;
}

void Customer::setWaiting(bool b)
{
	waiting = b;
}

void Customer::setSeated(bool b)
{
	seated = b;
}

void Customer::setOrdered(bool b)
{
	ordered = b;
}

void Customer::setFoodReadyVar(bool b)
{
	foodReady = b;
}

void Customer::setEating(bool b)
{
	eating = b;
}

void Customer::setGoodToGo(bool b)
{
	goodToGo = b;
}

void Customer::setDrinkOrder(DrinkMenuItem d)
{
	drinkOrder = d;
}

void Customer::setFoodOrder(FoodMenuItem f)
{
	foodOrder = f;
}

//other functions
void Customer::observe()
{
	CustomerHandler::getInstance()->attach(this);
}

void Customer::stopObserve()
{
	CustomerHandler::getInstance()->detach(this);
}

void Customer::update(string message)
{

}