#pragma once

#pragma once
#include <string>
using namespace std;

class RestaurantMenuItem
{

private:
	string name;
	double price,								//the menu price
		expense;								//how much the restaruant spends on the item
	int chefLvl = 0,							//a value to reference when cooking this item
		prepTime,
		cookTime;

	bool needChef = false,						//if the item needs a chef to prepare it
		orderCorrect = false,					//if the item was ordered correctly
		needPrep = true,						//if the item needs to be prepped
		needCook = false,						//if the item needs to be cooked
		cooking = false,						//if the item is cooking
		needReCook = false,						//if the item needs to be cooked again
		cookCorrect = false,					//if the item was prepared properly
		ready = false;							//if the item is ready

public:
	//constructor
	RestaurantMenuItem();

	//deconstructor
	~RestaurantMenuItem();

	//accessors
	string getName();
	double getPrice();
	double getExpense();
	int getPrepTime();
	int getCookTime();
	int getChefLvl();
	bool getNeedChef();
	bool getOrderCorrect();
	bool getNeedPrep();
	bool getNeedCook();
	bool getCooking();
	bool getNeedReCook();
	bool getCookCorrectVal();
	bool getReadyVal();

	//mutators
	void setName(string s);
	void setPrice(double d);
	void setExpense(double d);
	void setPrepTime(int i);
	void setCookTime(int i);
	void setChefLvl(int i);
	void setNeedChef(bool b);
	void setOrderCorrect(bool b);
	void setNeedPrep(bool b);
	void setNeedCook(bool b);
	void setCooking(bool b);
	void setNeedReCook(bool b);
	void setCookCorrectVal(bool b);
	void setReadyVal(bool b);

	//other functions
	void addChefLvl();
};
