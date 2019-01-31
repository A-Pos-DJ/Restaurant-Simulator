#pragma once
#include "Subject.h"

class RestaurantHandler : public Subject
{
private:
	static RestaurantHandler* _instance;	//singleton instance

public:

	//constructor
	RestaurantHandler();

	//desconstructor
	~RestaurantHandler();

	//accessors
	static RestaurantHandler* getInstance();

};
