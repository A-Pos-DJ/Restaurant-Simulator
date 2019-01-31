#pragma once
#include "RestaurantMenuItem.h"

class FoodMenuItem : public RestaurantMenuItem
{
private:

public:
	//constructor
	FoodMenuItem();
	FoodMenuItem(string _name, double _price, double _expense, int _prepTime, int _cookTime, bool _needCook);

	//deconstructor
	~FoodMenuItem();

	//factory method
	static FoodMenuItem * makeFoodItem(string _name, double _price, double _expense, int _prepTime, int _cookTime, bool _needCook);
};
