#include "Clock.h"
#include "Subject.h"
#include "Observer.h"

//constructor
Clock::Clock()
{

}

//deconstructor
Clock::~Clock()
{

}

//overloaded operators
//postfix
void Clock::operator++(int)
{
	minute++;						//add 1 minute to the clock
	rectify();						//adjust the clock to ensure 60 minutes reset to 0
}

void Clock::operator--(int)
{
	minute--;						//subtract 1 minute to the clock
	rectify();						//adjust the clock to ensure 60 minutes reset to 0
}

//accessors
Clock* Clock::getInstance()
{
	if (_instance == NULL)
		_instance = new Clock;
	return _instance;
}

int Clock::getDay()
{
	return hour;
}

int Clock::getHour()
{
	return hour;
}

int Clock::getMinute()
{
	return minute;
}

int Clock::getMinuteCounter()
{
	return minuteCounter;
}

//mutators
void Clock::setDay(int d)
{
	day = d;
}

void Clock::setHour(int h)
{
	hour = h;
}

void Clock::setMinute(int m)
{
	minute = m;
}

void Clock::setMinuteCounter(int c)
{
	minuteCounter = c;
}

//other functions
void Clock::rectify()
{
	while ((getMinute() >= 60 || getMinute() < 0) 
		|| (getHour() >= 24 || getHour() < 0) 
		|| getDay() < 0)
	{
		if (getMinute() >= 60)
		{
			setHour(getHour() + 1);
			setMinute(getMinute() - 60);
		}
		else if (getMinute() < 0)
		{
			setHour(getHour() - 1);
			setMinute(getMinute() + 60);
		}

		if (getHour() >= 24)
		{
			setDay(getDay() + 1);
			setHour(getHour() - 24);
		}
		else if (getHour() < 0)
		{
			setDay(getDay() - 1);
			setHour(getHour() + 24);
		}

		if (getDay() < 0)
		{
			setMinute(0);
			setHour(0);
			setDay(0);
		}
	}
}

void Clock::addDay()
{
	setDay(getDay() + 1);
	setMinuteCounter(getMinuteCounter() + 1440);
	rectify();
}

void Clock::addHour()
{
	setHour(getHour() + 1);
	setMinuteCounter(getMinuteCounter() + 60);
	rectify();
}

void Clock::addMinute()
{
	setMinute(getMinute() + 1);
	setMinuteCounter(getMinuteCounter() + 1);
	rectify();
}

/*
void Clock::setTimer(int m)
{
	cout << "setting timer for " << m << " minutes";

	alarm();
}

void Clock::alarm()							//action to take when timer goes to 0
{
	cout << "alarm went off at ";
	displayTime();
}
*/

void Clock::displayCounter()				//displays the number of minutes elapsed on the timer
{
	cout << getMinuteCounter() << "minutes elapsed";
}


void Clock::displayTime()
{
	if (getHour() == 0)
		cout << setfill('0') << setw(2) << 12 << ":" << setfill('0') << setw(2) << getMinute() << "am";
	else if (getHour() < 12)
		cout << setfill('0') << setw(2) << getHour() << ":" << setfill('0') << setw(2) << getMinute() << "am";
	else if (getHour() == 12)
		cout << setfill('0') << setw(2) << getHour() << ":" << setfill('0') << setw(2) << getMinute() << "pm";
	else if (getHour() > 12)
		cout << setfill('0') << setw(2) << (getHour() - 12) << ":" << setfill('0') << setw(2) << getMinute() << "pm";
}

string Clock::sendTime()														//sends the time (without days) to a string
{
	stringstream stream;														//create a string stream 
	if (getHour() == 0)
		stream << setfill('0') << setw(2) << 12 << ":" << setfill('0') << setw(2) << getMinute() << "am";
	else if (getHour() < 12)
		stream << setfill('0') << setw(2) << getHour() << ":" << setfill('0') << setw(2) << getMinute() << "am";
	else if (getHour() == 12)
		stream << setfill('0') << setw(2) << getHour() << ":" << setfill('0') << setw(2) << getMinute() << "pm";
	else if (getHour() > 12)
		stream << setfill('0') << setw(2) << (getHour() - 12) << ":" << setfill('0') << setw(2) << getMinute() << "pm";
	return stream.str();														//return all text made in the string
}


void Clock::displayMilitaryTime()
{
	cout << setfill('0') << setw(2) << getHour() << ":" << setfill('0') << setw(2) << getMinute();
}

bool Clock::waitForRealtime(int seconds)
{
	int targetTime = (static_cast<int>(time(0)) + seconds);
	while (true)
	{	
		if (static_cast<int>(time(0)) >= targetTime)
			return true;
	}
	return true;
}