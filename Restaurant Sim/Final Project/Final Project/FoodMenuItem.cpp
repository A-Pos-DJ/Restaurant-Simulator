#include "FoodMenuItem.h"

//constructor
FoodMenuItem::FoodMenuItem()
{

}

FoodMenuItem::FoodMenuItem(string _name, double _price, double _expense, int _prepTime, int _cookTime, bool _needChef)
{
	setName(_name);
	setPrice(_price);
	setExpense(_expense);
	setPrepTime(_prepTime);
	setCookTime(_cookTime);
	setNeedChef(_needChef);
}

//deconstructor
FoodMenuItem::~FoodMenuItem()
{

}

//factory method
FoodMenuItem * FoodMenuItem::makeFoodItem(string _name, double _price, double _expense, int _prepTime, int _cookTime, bool _needCook)
{
	return new FoodMenuItem( _name, _price, _expense, _prepTime, _cookTime, _needCook);
}
