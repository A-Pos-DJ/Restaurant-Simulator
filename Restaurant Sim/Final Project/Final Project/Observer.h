#pragma once
#include <vector>
#include <string>
#include "Subject.h"
using namespace std;

class Observer
{
public:
	virtual void update(string message) = 0;		//virtual function that all observers must have
};

