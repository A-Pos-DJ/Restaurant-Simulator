#pragma once
#include "RestaurantMenuItem.h"

class DrinkMenuItem : public RestaurantMenuItem
{
private:

public:
	//constructor
	DrinkMenuItem();
	DrinkMenuItem(string _name, double _price, double _expense);

	//deconstructor
	~DrinkMenuItem();

	//factory method
	static DrinkMenuItem * makeDrinkItem(string _name, double _price, double _expense);
};

