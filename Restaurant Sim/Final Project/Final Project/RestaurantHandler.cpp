#include "RestaurantHandler.h"

//constructor
RestaurantHandler::RestaurantHandler()
{

}

//deconstructor
RestaurantHandler::~RestaurantHandler()
{

}


//accessors
RestaurantHandler* RestaurantHandler::getInstance()
{
	if (_instance == NULL)
		_instance = new RestaurantHandler;
	return _instance;
}

//mutators


//other functions