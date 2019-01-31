#pragma once
#include <fstream>
#include <iostream>
#include "RestaurantSim.h"
using namespace std;

class FileLog
{
private:
	static FileLog* _instance;				//singleton instance

	ofstream dataLogFile;					//output file object for storing log data

	vector <string> log;					//a vector of strings to hold the values of the log

public:
	//constructor
	FileLog();

	//desconstructor
	~FileLog();

	//singleton instance
	static FileLog* getInstance();

	//other functions
	vector <string> loadFirstNames();							//loads all of the first names into a vector and returns it	
	vector <string> loadLastNames();							//loads all of the last names into a vector and returns it
	vector <DrinkMenuItem> loadDrinkMenu(int style);			//loads all of the drinks into the drink menu based on which style of restaurant is chosen and returns it
	vector <FoodMenuItem> loadFoodMenu(int style);				//loads all of the food into the food menu based on which style of restauarnt is chosen and returns it

	//log actions
	vector <string>* getLog();									//gets the log
	void addLog(string message);								//adds a message to the log of strings
	void saveLog();												//saves all messages in the log to Log.txt and clears the log for more text

};