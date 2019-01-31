#include "Subject.h"

//constructor
Subject::Subject()
{

}
//deconstructor
Subject::~Subject()
{

}

//mutators


//other functions
void Subject::attach(Observer* o)
{
	_observers.push_back(o);
}

void Subject::detach(Observer* o)
{
	int idx;

	for (idx = 0; idx < static_cast<int>(_observers.size()); idx++)
	{
		if (_observers[idx] == o)
			break;
	}
	if (idx < static_cast<int>(_observers.size()))
		_observers.erase(_observers.begin() + idx);

}

void Subject::notify(string message)
{
	for (int idx = 0; idx < static_cast<int>(_observers.size()); idx++)
		(_observers[idx])->update(message);
}