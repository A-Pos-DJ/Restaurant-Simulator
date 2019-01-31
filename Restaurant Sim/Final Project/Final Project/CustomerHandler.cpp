#include "CustomerHandler.h"

//constructor
CustomerHandler::CustomerHandler()
{

}

//deconstructor
CustomerHandler::~CustomerHandler()
{

}


//accessors
CustomerHandler* CustomerHandler::getInstance()
{
	if (_instance == NULL)
		_instance = new CustomerHandler;
	return _instance;
}

//mutators


//other functions