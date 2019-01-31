#pragma once
#include <queue>
#include "Employee.h"
#include "RestaurantSim.h"
#include "RestaurantMenuItem.h"
#include "DrinkMenuItem.h"
#include "FoodMenuItem.h"

class Cook : public Employee
{
private:
	//cook stats
	double speed,
		precision;

	int mistakeChance = 0;						//chance that the cook will make a mistake

	queue <FoodMenuItem*> cookingQueue;			//a queue of food menu items that are currently cooking

public:

	//constructor
	Cook();
	Cook(string _name, int exp, int dil);

	//deconstructor
	~Cook();

	//factory method
	static Cook* makeCook(string _name, int exp, int dil);

	//accessors
	double getSpeed();
	double getPrecision();
	int getMistakeChance();
	queue <FoodMenuItem*> * getCookingQueue();

	//mutators
	void setSpeed();
	void setPrecision();
	void setMistakeChance();

	//other functions
	bool failureChance();
	void addChefLvl();

	////cook actions////
	void cookActions(string action);
	bool actionCondition(string action, FoodMenuItem* food);
	int foodAction(string action, FoodMenuItem* food);
	void update(string text);
};

