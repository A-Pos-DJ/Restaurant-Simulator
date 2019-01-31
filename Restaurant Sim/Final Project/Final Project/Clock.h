#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime> 
#include <sstream>
using namespace std;

class Clock
{
private:
	static Clock* _instance;					//singleton instance
	int day = 0,								//days
		hour = 0,								//hours
		minute = 0,								//minutes
		minuteCounter = 0;						//a timer that holds the total number of minutes passed

public:
	//constructor
	Clock();

	//desconstructor
	~Clock();

	//overloaded operators
	//postfix
	void operator++(int);
	void operator--(int);

	//accessors
	static Clock* getInstance();
	int getDay();
	int getHour();
	int getMinute();
	int getMinuteCounter();

	//mutators
	void setDay(int d);
	void setHour(int h);
	void setMinute(int m);
	void setMinuteCounter(int c);

	//other functions
	void rectify();						//ensure the clock does not go past 60 minutes / 24 hours
	void addDay();						//adds a day
	void addHour();						//adds an hour
	void addMinute();					//adds a minute
//	void setTimer(int m);				//sets a timer based on minutes
//	void alarm();						//action to take when timer goes to 0
	void displayCounter();				//displays the number of minutes elapsed on the timer
	void displayTime();					//displays the time (without days)
	string sendTime();					//sends the time (without days) to a string
	void displayMilitaryTime();			//displays the time in military time (without days)
	bool waitForRealtime(int seconds);	//waits for amount of seconds to pass based on argument
};