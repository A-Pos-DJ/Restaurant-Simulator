#pragma once
#include "Subject.h"

class CustomerHandler : public Subject
{
private:
	static CustomerHandler* _instance;			//singleton instance

public:

	//constructor
	CustomerHandler();

	//desconstructor
	~CustomerHandler();

	//accessors
	static CustomerHandler* getInstance();

};
