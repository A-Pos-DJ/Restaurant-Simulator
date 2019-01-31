#include "DrinkMenuItem.h"

//constructor
DrinkMenuItem::DrinkMenuItem()
{

}

DrinkMenuItem::DrinkMenuItem(string _name, double _price, double _expense)
{
	setName(_name);
	setPrice(_price);
	setExpense(_expense);
	setPrepTime(1);
	setNeedCook(false);
}

//deconstructor
DrinkMenuItem::~DrinkMenuItem()
{

}

//factory method
DrinkMenuItem * DrinkMenuItem::makeDrinkItem(string _name, double _price, double _expense)
{
	return new DrinkMenuItem(_name, _price, _expense);
}