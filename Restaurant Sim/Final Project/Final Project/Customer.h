#pragma once
#include <string>
#include <iostream>
#include "CustomerHandler.h"
#include "Clock.h"
#include "RestaurantMenuItem.h"
#include "FoodMenuItem.h"
#include "DrinkMenuItem.h"
using namespace std;

class Customer : public Observer
{
private:
	string name;					//customer's name

	//customer stats//

	int waitLvlTesty,				//the amount of time the customer is willing to wait before complaining
		waitLvlMax,					//the amount of time the customer is willing to wait before leaving
		eatLvlMax;					//the amount of time the customer needs to eat before they are done

	//customer states//

	bool waiting = true,			//if the customer is waiting (the inital state of the customer)
		seated = false,				//if the customer is seated
		ordered = false,			//if the customer has ordered
		foodReady = false,			//if the customer has food ready
		eating = false,				//if the customer is eating their meal
		goodToGo = false;			//if the customer is good to pay and leave

	//customer orders//

	DrinkMenuItem drinkOrder;		//the drink item the customer is going to order
	FoodMenuItem foodOrder;			//the food item the customer is going to order

public:
	//constructor
	Customer();
	Customer(string _name, int _waitTesty, int _waitMax, int _eatMax);

	//factory method
	static Customer* makeCustomer(string _name, int _waitTesty, int _waitMax, int _eatMax);
	
	//deconstructor
	~Customer();

	//accessors
	string getName();
	int getWaitLvlTesty();
	int getWaitLvlMax();
	int getEatLvlMax();
	bool getWaiting();
	bool getSeatedVar();
	bool getOrdered();
	bool getFoodReadyVar();
	bool getEating();
	bool getGoodToGo();
	DrinkMenuItem * getDrinkOrder();
	FoodMenuItem * getFoodOrder();

	//mutators
	void setName(string s);
	void setWaitLvlTesty(int n);
	void setWaitLvlMax(int n);
	void setEatLvlMax(int n);
	void setWaiting(bool b);
	void setSeated(bool b);
	void setOrdered(bool b);
	void setFoodReadyVar(bool b);
	void setEating(bool b);
	void setGoodToGo(bool b);
	void setDrinkOrder(DrinkMenuItem d);
	void setFoodOrder(FoodMenuItem f);

	//other functions
	void observe();
	void stopObserve();
	void update(string message);
};