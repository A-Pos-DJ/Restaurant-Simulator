#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include "Clock.h"
#include "Subject.h"
#include "Observer.h"
#include "RestaurantHandler.h"
#include "CustomerHandler.h"
#include "Customer.h"
#include "Party.h"
#include "Table.h"
#include "Employee.h"
#include "Server.h"
#include "RestaurantMenuItem.h"
#include "FoodMenuItem.h"
#include "DrinkMenuItem.h"
#include "Cook.h"
#include "FileLog.h"
using namespace std;

class Server;							//forward declaration

class RestaurantSim
{
private:
	static RestaurantSim* _instance;	//singleton instance

	string restaurantName;				//name of the restaurant

	int style = 0,						//the style of the restaurant represented by an int
		startingTime,					//time of day the simulation starts measured in minutes (in military time)
		totalMinutes,					//total number of minutes the simulation runs for
		totalTables,					//total number of tables that will be in the simulation
		customerFrequency,				//determines how often customers appear (in minutes)
		tableWait = 0,					//combined wait times of all customers waiting for a table
		totalWait = 0,					//total combined wait times of all customers
		totalParties = 0;				//total number of parties generated

	bool skipSecond = false;			//boolean variable for skipping every other second in the 7 hour simulation

	double revenue = 0.00,				//money earned
		expenses = 0.00,				//money spent
		styleModifier = 0.00;			//a modifier set based on the style of the restaurant, adds or shorten various time related values

	queue <Party*> seatQueue;			//a queue of party pointers waiting to be seated
	queue <Party*> orderQueue;			//a queue of party pointers waiting to order food
	queue <FoodMenuItem*> chefQueue;	//a queue of food menu item pointers that need to be cooked

	vector <string> firstNames;			//a vector of first names
	vector <string> lastNames;			//a vector of last names
	vector <Server*> servers;			//a vector of server pointers
	vector <Employee*>  employees;		//a vector of employee pointers
	vector <FoodMenuItem> foodMenu;		//a vector of food menu items
	vector <DrinkMenuItem> drinkMenu;	//a vector of drink menu items
	vector <Table*>  tables;			//a vector of table pointers

public:

	//constructor
	RestaurantSim();

	//desconstructor
	~RestaurantSim();

	//singleton instance
	static RestaurantSim* getInstance();

	//accessors
	string getRestaurantName();
	int getStyle();
	int getStartingTime();
	int getTotalMinutes();
	int getTotalTables();
	bool getSkipSecond();
	double getRevenue();
	double getExpenses();
	int getCustomerFrequency();
	double getStyleModifier();
	int getTableWait();
	int getTotalWait();
	int getTotalParties();
	string getRandomFirstName();
	string getRandomLastName();
	DrinkMenuItem getRandomDrink();
	FoodMenuItem getRandomFood();

	vector <string>* getFirstNames();
	vector <string>* getLastNames();
	vector <FoodMenuItem>* getFoodMenu();		
	vector <DrinkMenuItem>* getDrinkMenu();	
	vector <Server*> * getServers();
	vector <Employee*> * getEmployees();
	Table* getTable(int tableNum);
	vector <Table*> * getTables();
	queue <Party*> * getSeatQueue();
	queue <Party*> * getOrderQueue();
	queue <FoodMenuItem*> * getChefQueue();

	//mutators
	void setRestaurantName(string s);
	void setStyle(int i);
	void setStartingTime(int t);
	void setTotalMinutes(int m);
	void setTotalTables(int t);
	void setSkipSecond(bool b);
	void setRevenue(double d);
	void setExpenses(double d);
	void setCustomerFrequency(int i);
	void setTableWait(int i);
	void setTotalWait(int i);
	void setTotalParties(int i);
	void setStyleModifier();
	void setFirstNames(vector <string> load);
	void setLastNames(vector <string> load);
	void setFoodMenu(vector <FoodMenuItem> load);
	void setDrinkMenu(vector <DrinkMenuItem> load);

	//other functions
	void askIntValue(string message, int &value);
	void addRevenue(double d);
	void addExpenses(double d);
	void addTableWait();					//adds 1 to the waiting times for tables
	void addTotalWait();					//adds 1 to the total wait time
	void addTotalParties();					//adds 1 to the total amount of parties
	int getTotalCooks();					//gets the total number of cooks based on charm stat
	void generateTables(int tableTotal);	//generates a specified number of tables and adds them to the tables vector
	void generateServers(int serverTotal);	//generates a specified number of servers and adds them to the server & employees vector
	void generateCooks(int cookTotal);		//generates a specified number of cooks and adds them to the employees vector
	int nextTableNum();						//gets the next table number in the series
	void addTable(Table * table);			//adds a table pointer to the vector of tables
	void assignTables();					//assigns all of the tables among all of the employees (needs to be implemented before adding cooks)
	void generateParty();					//generates a new party and adds it to the queue
	void addChefQueue(						//adds a food menu item pointer to the cook queue
		FoodMenuItem * foodOrder);
	void addChefQueuePriority(				//adds a food menu item to the front of the queue
		FoodMenuItem * foodOrder);
	double timeOfDayMod();					//returns a value based on the time of day (less than 1 for slow times, and more than 1 for peak times)

	void loadAllFiles();					//loads all files attached to the prograsm
	void wait();							//waits for realtime to pass before continuing with the sim
	void init();							//initilize the simulator. Load all files/proccesses
	void start();							//start the simulator once all settings have been established
	void end();								//end the simulator. Save all files. Print reports

};
