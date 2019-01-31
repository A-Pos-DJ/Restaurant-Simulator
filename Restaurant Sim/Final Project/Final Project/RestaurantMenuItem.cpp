#include "RestaurantMenuItem.h"

//constructor
RestaurantMenuItem::RestaurantMenuItem()
{

}

//deconstructor
RestaurantMenuItem::~RestaurantMenuItem()
{

}

//accessors
string RestaurantMenuItem::getName()
{
	return name;
}

double RestaurantMenuItem::getPrice()
{
	return price;
}

double RestaurantMenuItem::getExpense()
{
	return expense;
}

int RestaurantMenuItem::getPrepTime()
{
	return prepTime;
}

int RestaurantMenuItem::getCookTime()
{
	return cookTime;
}

int RestaurantMenuItem::getChefLvl()
{
	return chefLvl;
}

bool RestaurantMenuItem::getNeedChef()
{
	return needChef;
}

bool RestaurantMenuItem::getOrderCorrect()
{
	return orderCorrect;
}

bool RestaurantMenuItem::getNeedPrep()
{
	return needPrep;
}

bool RestaurantMenuItem::getNeedCook()
{
	return needCook;
}

bool RestaurantMenuItem::getCooking()
{
	return cooking;
}

bool RestaurantMenuItem::getNeedReCook()
{
	return needReCook;
}

bool RestaurantMenuItem::getCookCorrectVal()
{
	return cookCorrect;
}

bool RestaurantMenuItem::getReadyVal()
{
	return ready;
}


//mutators
void RestaurantMenuItem::setName(string s)
{
	name = s;
}

void RestaurantMenuItem::setPrice(double d)
{
	price = d;
}

void RestaurantMenuItem::setExpense(double d)
{
	expense = d;
}

void RestaurantMenuItem::setPrepTime(int i)
{
	prepTime = i;
}

void RestaurantMenuItem::setCookTime(int i)
{
	cookTime = i;
}

void RestaurantMenuItem::setChefLvl(int i)
{
	if (i <= 0)
		chefLvl = 0;
	else
		chefLvl = i;
}


void RestaurantMenuItem::setNeedChef(bool b)
{
	needChef = b;
}

void RestaurantMenuItem::setOrderCorrect(bool b)
{
	orderCorrect = b;
}

void RestaurantMenuItem::setNeedPrep(bool b)
{
	needPrep = b;
}

void RestaurantMenuItem::setNeedCook(bool b)
{
	needCook = b;
}

void RestaurantMenuItem::setCooking(bool b)
{
	cooking = b;
}

void RestaurantMenuItem::setNeedReCook(bool b)
{
	needReCook = b;
}

void RestaurantMenuItem::setCookCorrectVal(bool b)
{
	cookCorrect = b;
}

void RestaurantMenuItem::setReadyVal(bool b)
{
	ready = b;
}

//other functions
void RestaurantMenuItem::addChefLvl()
{
	setChefLvl(getChefLvl() + 1);
}
