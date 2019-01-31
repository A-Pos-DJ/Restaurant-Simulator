#include "RestaurantSim.h"

RestaurantSim *RestaurantSim::_instance = NULL;
Clock *Clock::_instance = NULL;
RestaurantHandler *RestaurantHandler::_instance = NULL;
CustomerHandler *CustomerHandler::_instance = NULL;
FileLog *FileLog::_instance = NULL;


//constructor
RestaurantSim::RestaurantSim()
{

}

//deconstructor
RestaurantSim::~RestaurantSim()
{

}

//singleton Instance
RestaurantSim* RestaurantSim::getInstance()
{
	if (_instance == NULL)
		_instance = new RestaurantSim;
	return _instance;
}

//accessors
string RestaurantSim::getRestaurantName()
{
	return restaurantName;
}

int RestaurantSim::getStyle()
{
	return style;
}

int RestaurantSim::getStartingTime()
{
	return startingTime;
}

int RestaurantSim::getTotalMinutes()
{
	return totalMinutes;
}

int RestaurantSim::getTotalTables()
{
	return totalTables;
}

bool RestaurantSim::getSkipSecond()
{
	return skipSecond;
}

double RestaurantSim::getRevenue()
{
	return revenue;
}

double RestaurantSim::getExpenses()
{
	return expenses;
}

int RestaurantSim::getCustomerFrequency()
{
	return customerFrequency;
}

double RestaurantSim::getStyleModifier()
{
	return styleModifier;
}

int RestaurantSim::getTableWait()
{
	return tableWait;
}


int RestaurantSim::getTotalWait()
{
	return totalWait;
}

int RestaurantSim::getTotalParties()
{
	return totalParties;
}


string RestaurantSim::getRandomFirstName()
{
	int size = static_cast<int>(RestaurantSim::getInstance()->getFirstNames()->size());
	int indexVal = (((rand() % size) + 1) - 1);									//generates a number betweeen 1 through the size int of the vector and the result by 1
	return RestaurantSim::getInstance()->getFirstNames()->at(indexVal);			//returns a name at the random number indexxed
}

string RestaurantSim::getRandomLastName()
{
	int size = static_cast<int>(RestaurantSim::getInstance()->getLastNames()->size());
	int indexVal = (((rand() % size) + 1) - 1);									//generates a number betweeen 1 through the size int of the vector and the result by 1
	return RestaurantSim::getInstance()->getLastNames()->at(indexVal);			//returns a name at the random number indexxed
}

DrinkMenuItem RestaurantSim::getRandomDrink()
{
	int size = static_cast<int>(RestaurantSim::getInstance()->getDrinkMenu()->size());
	int indexVal = (((rand() % size) + 1) - 1);									//generates a number betweeen 1 through the size int of the vector and the result by 1
	return RestaurantSim::getInstance()->getDrinkMenu()->at(indexVal);			//returns a drinkitem at the random number indexxed
}

FoodMenuItem RestaurantSim::getRandomFood()
{
	int size = static_cast<int>(RestaurantSim::getInstance()->getFoodMenu()->size());
	int indexVal = (((rand() % size) + 1) - 1);									//generates a number betweeen 1 through the size int of the vector and the result by 1
	return RestaurantSim::getInstance()->getFoodMenu()->at(indexVal);			//returns a drinkitem at the random number indexxed
}

vector <string>* RestaurantSim::getFirstNames()
{
	return &firstNames;
}

vector <string>* RestaurantSim::getLastNames()
{
	return &lastNames;
}

vector <FoodMenuItem>* RestaurantSim::getFoodMenu()
{
	return &foodMenu;
}

vector <DrinkMenuItem>* RestaurantSim::getDrinkMenu()
{
	return &drinkMenu;
}

vector <Server*> * RestaurantSim::getServers()
{
	return &servers;
}


vector <Employee*> * RestaurantSim::getEmployees()
{
	return &employees;
}

Table* RestaurantSim::getTable(int tableNum)
{
	if (static_cast<int>(RestaurantSim::getInstance()->getTables()->size())			//if the number we are looking for is not within the array bounds
		< (tableNum - 1) || (tableNum - 1) < 0)
	{
		if (RestaurantSim::getInstance()->getTables()->size() == NULL)				//if there is not a table pointer in the vector
		{
			Table * t;																//make a table pointer
			RestaurantSim::getInstance()->getTables()->push_back(t);				//add the table pointer to the tables vector
			return RestaurantSim::getInstance()->getTables()->at(0);				//return the table pointer that we just made
		}
		else
		{																			//if there are table pointers in the vector
			return RestaurantSim::getInstance()->getTables()->at(static_cast		//return the last pointer in the vector
				<int>((RestaurantSim::getInstance()->getTables()->size()) - 1));		
		}
	}

	return RestaurantSim::getInstance()->getTables()->at((tableNum - 1));			//if the number we are looking for is in the array, return the one we are looking for
	
}

vector <Table*> * RestaurantSim::getTables()
{
	return &tables;
}

queue <Party*> * RestaurantSim::getSeatQueue()
{
	return &seatQueue;
}

queue <Party*> * RestaurantSim::getOrderQueue()
{
	return &orderQueue;
}

queue <FoodMenuItem*> * RestaurantSim::getChefQueue()
{
	return &chefQueue;
}




//mutators
void RestaurantSim::setRestaurantName(string s)
{
	restaurantName = s;
}

void RestaurantSim::setStyle(int i)
{
	style = i;
}

void RestaurantSim::setStartingTime(int t)
{
	startingTime = t;
}

void RestaurantSim::setTotalMinutes(int m)
{
	totalMinutes = m;
}

void RestaurantSim::setTotalTables(int t)
{
	totalTables = t;
}

void RestaurantSim::setSkipSecond(bool b)
{
	skipSecond = b;
}

void RestaurantSim::setRevenue(double d)
{
	revenue = d;
}

void RestaurantSim::setExpenses(double d)
{
	expenses = d;
}

void RestaurantSim::setCustomerFrequency(int i)
{
	customerFrequency = i;
}

void RestaurantSim::setTableWait(int i)
{
	tableWait = i;
}

void RestaurantSim::setTotalWait(int i)
{
	totalWait = i;
}

void RestaurantSim::setTotalParties(int i)
{
	totalParties = i;
}


void RestaurantSim::setStyleModifier()
{
	if (getStyle() == 1)					//if it is fast food
	{
		styleModifier = 0.5;				//shorten all times
	}
	else if (getStyle() == 2)				//if it is typical
	{
		styleModifier = 1.00;				//all times will remain the same
	}
	else if (getStyle() == 3)				//if it is formal
	{
		styleModifier = 1.5;				//lengthen the times
	}
	else
		styleModifier = 0.00;				//if none of the above... set to 0
}

void RestaurantSim::setFirstNames(vector <string> load)
{
	firstNames = load;
}

void RestaurantSim::setLastNames(vector <string> load)
{
	lastNames = load;
}

void RestaurantSim::setFoodMenu(vector <FoodMenuItem> load)
{
	foodMenu = load;
}

void RestaurantSim::setDrinkMenu(vector <DrinkMenuItem> load)
{
	drinkMenu = load;
}

//other functions
void RestaurantSim::askIntValue(string message, int &value)
{
	string s = "";											//initilize a string variable
	stringstream streamI;									//initilize a string stream
	streamI << endl << message << " ";						//send a message to the stream
	cout << streamI.str();									//display the stream message
	streamI.clear();										//clear the stream
	streamI.str("");										//replace the stream with blankspace
	getline(cin, s);										//get input and send it to a string
	streamI.str(s);											//put the string into the stream
	streamI >> value;										//put stream into int variable
}

void RestaurantSim::addRevenue(double d)
{
	setRevenue(getRevenue() + d);
}

void RestaurantSim::addExpenses(double d)
{
	setExpenses(getExpenses() + d);
}

void RestaurantSim::addTableWait()
{
	setTableWait(getTableWait() + 1);
}


void RestaurantSim::addTotalWait()
{
	setTotalWait(getTotalWait() + 1);
}

void RestaurantSim::addTotalParties()
{
	setTotalParties(getTotalParties() + 1);
}

int RestaurantSim::getTotalCooks()
{
	int cookCount = 0;
	for (int idx = 0; idx < static_cast<int>(RestaurantSim::getInstance()->getEmployees()->size()); idx++)
	{
		if (RestaurantSim::getInstance()->getEmployees()->at(idx)->getCharmLvl() == 0)
			cookCount++;
	}
	return cookCount;
}

void RestaurantSim::generateTables(int tableTotal)
{
	for (int idx = 0; idx < tableTotal; idx++)												//create a loop that iterates the amount of totalTables
	{
		RestaurantSim::getInstance()->addTable(Table::makeTable(
			RestaurantSim::getInstance()->nextTableNum()));									//adds a table and sets the table number to either 1 or the highest + 1
	}
}

void RestaurantSim::generateServers(int serverTotal)
{
	bool finished = false;																	//create bool for finished flag
	int expLvl = 0,																			//create ints to hold stat values
		dilLvl = 0,
		chaLvl = 0;
	string s = "";

	cout << endl << "Servers have 3 values that determine effectiveness- " << endl << endl	//display description of server values
		<< "Experience - How long the server has been working at the job." << endl
		<< "Diligence - A measure of work ethic and overall attentiveness." << endl
		<< "Charisma - The server's ability to comunicate and de-escalate customers." << endl;
	for (int idx = 0; idx < serverTotal; idx++)												//create a loop that iterates the amount of serverTotal
	{
		s = "Pick a value between 1 - 10 to set Server ";
		s += to_string((idx + 1)) + "'s expeience level at: ";								//add a statement to the string
		finished = false;																	//reset clear flag
		while (!finished)																	//while loop
		{
			expLvl = -1;																	//set expLvl to -1
			try {
				RestaurantSim::getInstance()->askIntValue(s, expLvl);
				if (expLvl > 0 && expLvl <= 10)												//if the score is between 1 and 10
					finished = true;														//set the clear flag to be true
				else
					throw "invalid server exp lvl";											//throw exception
			}
			catch (...) { cout << "ERROR: invalid input. (Min 1, Max 10) Please try again."; }
		}

		s = "Pick a value between 1 - 10 to set Server ";
		s += to_string((idx + 1)) + "'s diligence level at: ";								//add a statement to the string
		finished = false;																	//reset clear flag
		while (!finished)																	//while loop
		{
			dilLvl = -1;																	//set dilLvl to -1
			try {
				RestaurantSim::getInstance()->askIntValue(s, dilLvl);
				if (dilLvl > 0 && dilLvl <= 10)												//if the score is between 1 and 10
					finished = true;														//set the clear flag to be true
				else
					throw "invalid server dil lvl";											//throw exception
			}
			catch (...) { cout << "ERROR: invalid input. (Min 1, Max 10) Please try again."; }
		}

		s = "Pick a value between 1 - 10 to set Server ";
		s += to_string((idx + 1)) + "'s charisma level at: ";								//add a statement to the string
		finished = false;																	//reset clear flag
		while (!finished)																	//while loop
		{
			chaLvl = -1;																	//set chaLvl to -1
			try {
				RestaurantSim::getInstance()->askIntValue(s, chaLvl);
				if (chaLvl > 0 && chaLvl <= 10)												//if the score is between 1 and 10
					finished = true;														//set the clear flag to be true
				else
					throw "invalid server cha lvl";											//throw exception
			}
			catch (...) { cout << "ERROR: invalid input. (Min 1, Max 10) Please try again."; }
		}

		RestaurantSim::getInstance()->getServers()->push_back(								//get the server vector
			Server::makeServer(RestaurantSim::getInstance()->getRandomFirstName(),			//generate a new server, generate a random name
				expLvl, dilLvl, chaLvl));													//add created stats to the server

		RestaurantSim::getInstance()->getEmployees()->push_back(							//adds created server to employee vector
			RestaurantSim::getInstance()->getServers()->back());
	}
}

void RestaurantSim::generateCooks(int cookTotal)
{
	bool finished = false;
	int expLvl = 0,																			//create ints to hold stat values
		dilLvl = 0;
	string s = "";

	cout << endl << "Cooks have 2 values that determine effectiveness- " << endl << endl	//display description of cook values
		<< "Experience - How long the cook has been working at the job." << endl
		<< "Diligence - A measure of work ethic and overall attentiveness." << endl;
	for (int idx = 0; idx < cookTotal; idx++)												//create a loop that iterates the amount of cookTotal
	{
		s = "Pick a value between 1 - 10 to set Cook ";
		s += to_string((idx + 1)) + "'s expeience level at: ";								//add a statement to the string
		finished = false;																	//reset clear flag
		while (!finished)																	//while loop
		{
			expLvl = -1;																	//set expLvl to -1
			try {
				RestaurantSim::getInstance()->askIntValue(s, expLvl);
				if (expLvl > 0 && expLvl <= 10)												//if the score is between 1 and 10
					finished = true;														//set the clear flag to be true
				else
					throw "invalid cook exp lvl";											//throw exception
			}
			catch (...) { cout << "ERROR: invalid input. (Min 1, Max 10) Please try again."; }
		}

		s = "Pick a value between 1 - 10 to set Cook ";
		s += to_string((idx + 1)) + "'s diligence level at: ";								//add a statement to the string
		finished = false;																	//reset clear flag
		while (!finished)																	//while loop
		{
			dilLvl = -1;																	//set dilLvl to -1
			try {
				RestaurantSim::getInstance()->askIntValue(s, dilLvl);
				if (dilLvl > 0 && dilLvl <= 10)												//if the score is between 1 and 10
					finished = true;														//set the clear flag to be true
				else
					throw "invalid cook dil lvl";											//throw exception
			}
			catch (...) { cout << "ERROR: invalid input. (Min 1, Max 10) Please try again."; }
		}

		RestaurantSim::getInstance()->getEmployees()->push_back(							//get the employee vector
			Cook::makeCook(RestaurantSim::getInstance()->getRandomFirstName(),				//generate a new cook, generate a random name
				expLvl, dilLvl));															//add created stats to the cook
	}
}

int RestaurantSim::nextTableNum()
{
	if (RestaurantSim::getInstance()->getTables()->empty())														//if there is nothing in the tables vector
		return 1;																								//this is the first table
	
	int totalTables = static_cast<int>(RestaurantSim::getInstance()->getTables()->size()),						//create an int and assign it the total amount of tables
		highest = RestaurantSim::getInstance()->getTables()->at(0)->getTableNum();								//set the highest table number to the first in the series

	for (int idx = 0; idx < totalTables; idx++)																	//cycle though all of the tables
	{
		if (RestaurantSim::getInstance()->getTables()->at(idx)->getTableNum() > highest)						//if the table number is higher than the current highest
			highest = RestaurantSim::getInstance()->getTables()->at(idx)->getTableNum();						//set the higest table number to that indexed table's table number
	}
	return (highest + 1);																						//return the highest table number + 1
}


void RestaurantSim::addTable(Table * table)
{
	RestaurantSim::getInstance()->getTables()->push_back(table);
}

void RestaurantSim::assignTables()
{
	int totalServers = static_cast<int>(RestaurantSim::getInstance()->getEmployees()->size()),					//create an int and assign it the total amount of servers
		totalTables = static_cast<int>(RestaurantSim::getInstance()->getTables()->size()),						//create an int and assign it the total amount of tables
		serverIdx = 0;																							//create an int to hold the index for servers

	for (int idx = 0; idx < totalTables; idx++)																	//cycle though all of the tables
	{
		if (serverIdx >= totalServers)																			//if the indexed server is out of range
			serverIdx = 0;																						//reset the server index

		RestaurantSim::getInstance()->getServers()->at(serverIdx)->assignTable(
			RestaurantSim::getInstance()->getTables()->at(idx));												//gets a server at the server index and assigns it to a table at the table index

		serverIdx++;																							//add to the server index
	}
}

void RestaurantSim::generateParty()
{
	int partySize = static_cast<int>((1.6 * RestaurantSim::getInstance()->getStyleModifier())) +				//adds 0-2 people based on the time of day
		static_cast<int>(((rand() % 2) + 1));																	//generates random number with results of 1 - 2 then adds those people

	Party * generated = Party::makeParty(getRandomLastName());													//generates a party with a random name

	for (int idx = 0; idx < partySize; idx++)
	{
		generated->addCustomer(Customer::makeCustomer(getRandomFirstName(),										//generates a new customer with a random name
			(static_cast<int>((55 + ((rand() % 20) + 1)) * RestaurantSim::getInstance()->getStyleModifier())),	//set generated customer's testy time to 56-75min * the restaurant style modifier
			(static_cast<int>((75 + ((rand() % 30) + 1)) * RestaurantSim::getInstance()->getStyleModifier())),	//set generated customer's max waiting time to 76-105min * the restaurant style modifier
			(static_cast<int>((30 + ((rand() % 25) + 1)) * RestaurantSim::getInstance()->getStyleModifier()))));//set generated customer's time that is spent eating to 31-55min * style modifier
		generated->getCustomers()->at(idx)->setDrinkOrder(getRandomDrink());									//set customer's drink order to a random menu item (based on restaurnt style)
		generated->getCustomers()->at(idx)->setFoodOrder(getRandomFood());										//set customer's food order to a random menu item (based on restaurnt style)
	}

	stringstream stream;																						//create a string stream object
	stream << endl
		<< Clock::getInstance()->sendTime()
		<< "  The " << generated->getName() << " party has arrived";											//add a message saying the customer has arrived
	cout << stream.str();																						//display the stream
	FileLog::getInstance()->addLog(stream.str());																//add the message to the log
	RestaurantSim::getInstance()->getSeatQueue()->push(generated);												//add the party to the wait queue
	RestaurantSim::getInstance()->addTotalParties();															//adds 1 to the total amount of parties made
}

void RestaurantSim::addChefQueue(FoodMenuItem * foodOrder)
{
	RestaurantSim::getInstance()->getChefQueue()->push(foodOrder);
}

void RestaurantSim::addChefQueuePriority(FoodMenuItem * foodOrder)
{
	queue <FoodMenuItem*>* temp = new queue <FoodMenuItem*>;												//create a temp pointer
	temp->push(foodOrder);

	for (int idx = 0; idx < static_cast<int>(RestaurantSim::getInstance()->getChefQueue()->size()); idx++)	//loop through the chef queue
	{
		temp->push(RestaurantSim::getInstance()->getChefQueue()->front());									//add front of queue to the temp queue
		RestaurantSim::getInstance()->getChefQueue()->pop();												//remove the element
	}
	
	for (int idx = 0; idx < static_cast<int>(temp->size()); idx++)											//loop through the temp queue
	{
		RestaurantSim::getInstance()->addChefQueue(temp->front());											//add front of temp queue to the chef queue
		temp->pop();																						//remove the element in the temp queue
	}
	delete temp;																							//delete temp pointer
}

	double RestaurantSim::timeOfDayMod()
	{
		double fifth = (getTotalMinutes() / 5);

		if (Clock::getInstance()->getMinuteCounter() >= (getStartingTime() + (fifth * 0)) &&				//if first part of the day
			Clock::getInstance()->getMinuteCounter() < (getStartingTime() + (fifth * 1)))
		{
			return 0.60;																					//return a smallest value
		}
		else if (Clock::getInstance()->getMinuteCounter() >= (getStartingTime() + (fifth * 1)) &&			//if second part of the way
			Clock::getInstance()->getMinuteCounter() < (getStartingTime() + (fifth * 2)))
		{
			return 1;																						//return 1
		}
		else if (Clock::getInstance()->getMinuteCounter() >= (getStartingTime() + (fifth * 2)) &&			//if third part of the day
			Clock::getInstance()->getMinuteCounter() < (getStartingTime() + (fifth * 3)))
		{
			return 1.50;																					//return largest value
		}
		else if (Clock::getInstance()->getMinuteCounter() >= (getStartingTime() + (fifth * 3)) &&			//if fourth part of the day
			Clock::getInstance()->getMinuteCounter() < (getStartingTime() + (fifth * 4)))
		{
			return 1.25;																					//return a slightly larger value
		}
		else if (Clock::getInstance()->getMinuteCounter() >= (getStartingTime() + (fifth * 4)) &&			//if fifth part of the day
			Clock::getInstance()->getMinuteCounter() < (getStartingTime() + (fifth * 5)))
		{
			return 0.75;																					//return a smaller value
		}

		else return 1;
	}


void RestaurantSim::loadAllFiles()
{
	RestaurantSim::getInstance()->setFirstNames(FileLog::getInstance()->loadFirstNames());					//sets first name vector to values in the file
	RestaurantSim::getInstance()->setLastNames(FileLog::getInstance()->loadLastNames());					//sets last name vector to the values in the file
	RestaurantSim::getInstance()->setDrinkMenu(FileLog::getInstance()->loadDrinkMenu(getStyle()));			//sets drink menu vector from the file according to the style of the restaurant
	RestaurantSim::getInstance()->setFoodMenu(FileLog::getInstance()->loadFoodMenu(getStyle()));			//sets food menu vector from the file according to the style of the restaurant
}

void RestaurantSim::wait()
{
	if (3 == (getTotalMinutes() / 60))							//if SIM is based on the 3 hour clock...
	{
		if (!getSkipSecond())
		{
			Clock::getInstance()->waitForRealtime(2);			//1.5 seconds per in game minute
			setSkipSecond(true);
		}
		else
		{
			Clock::getInstance()->waitForRealtime(1);			//1.5 seconds per in game minute
			setSkipSecond(false);
		}
	}
	else if (5 == (getTotalMinutes() / 60))						//if SIM is based on the 5 hour clock...
	{
		Clock::getInstance()->waitForRealtime(1);				//1 second per in game minute
	}
	else if (7 == (getTotalMinutes() / 60))						//if SIM is based on the 7 hour clock...
	{
		if (!getSkipSecond())
		{
			Clock::getInstance()->waitForRealtime(1);			//1 second per 1.5 in game minute
			setSkipSecond(true);
		}
		else
			setSkipSecond(false);
	}
}

void RestaurantSim::init()
{
	srand((unsigned)time(0));									//set the seed of the random number generator

	bool finished = false;
	int value = 0;
	string init = "";

	while (!finished)																									//while loop
	{
		try {
			cout << "What is the name of your restaurant? ";
			getline(cin, init);
			RestaurantSim::getInstance()->setRestaurantName(init);														//set the restauarnt name to the value supplied
			if (init.length() <= 25)																					//as long as the name is less than 26 characters
				finished = true;																						//set clear flag true
			else
				throw "invalid name";																					//otherwise, throw exception
		}
		catch (...) { cout << "ERROR: invalid input or name is too long. (Max 25 characters) Please try again.\n";}
	}
	
	string st = "\tStyle 1: Fast Food / Cafeteria\n\tStyle 2: Typical Restaurant\n\tStyle 3: Formal / Fine Dining\n\n";
	st += "What style would you like to set your restauarnt to?";
	finished = false;																									//reset clear flag
	while (!finished)																									//while loop
	{
		try {
			value = -1;																										//set the value to -1
			RestaurantSim::getInstance()->askIntValue(st, value);	//inquiry for value
			if (value == 1 || value == 2 || value == 3)																	//if it is one of the 3 values
				finished = true;																						//set the clear flag to be true
			else
				throw "invalid style val";																				//throw exception
		}
		catch (...) { cout << "ERROR: invalid input. (Must be 1, 2, or 3) Please try again."; }
	}
	setStyle(value);																									//set the style value
	setStyleModifier();																									//set the style modifier
								//1 is fastfood				2 is typical				3 is formal//
	loadAllFiles();																										//loads all of the files attached to the program into their vectors

	
	finished = false;																									//reset clear flag
	while (!finished)																									//while loop
	{
		value = -1;																										//set the value to -1
		try {
			RestaurantSim::getInstance()->askIntValue("How many tables would you like in your restaurant?", value);		//inquiry for value
			if (value <= 100 && value >= 1)																				//if the number of tables are not greater than 100 or less than 1
				finished = true;																						//set the clear flag to be true
			else
				throw "invalid tables val";																				//throw exception
		}
		catch (...) { cout << "ERROR: invalid input. (Max 100 tables, Min 1 table) Please try again."; }
	}
	RestaurantSim::getInstance()->generateTables(value);
	RestaurantSim::getInstance()->setTotalTables(value);
	RestaurantSim::getInstance()->generateTables(value);

	finished = false;																									//reset clear flag
	while (!finished)																									//while loop
	{
		value = -1;																										//set the value to -1
		try {
			RestaurantSim::getInstance()->askIntValue("How many minutes would you like to pass before each customer arrives?", value);
			if (value < 180 && value >= 5)																				//if the customer frequqncy time is not greater than 179 or less than 5
				finished = true;																						//set the clear flag to be true
			else
				throw "invalid frequency val";																			//throw exception
		}
		catch (...) { cout << "ERROR: invalid input. (Max 179 minutes, Min 5 minutes) Please try again."; }
	}
	RestaurantSim::getInstance()->setCustomerFrequency(value);


	finished = false;																									//reset clear flag
	while (!finished)																									//while loop
	{
		value = -1;																										//set the value to -1
		try {
			RestaurantSim::getInstance()->askIntValue("Would you like a 3 hour, 5 hour, or 7 hour simulation?", value);
			if (value == 3 || value == 5 || value == 7)																	//if the simulation time is 3,5,or 7 hours
				finished = true;																						//set the clear flag to be true
			else
				throw "invalid total time val";																			//throw exception
		}
		catch (...) { cout << "ERROR: invalid input. (Must be 3, 5, or 7) Please try again."; }
	}
	//7 hours - 84 in game seconds need to pass every realtime second
	//5 hours - 60 in game seconds need to pass every realtime second
	//3 hours - 36 in game seconds need to pass every realtime second
	//300 realtime seconds = 5 realtime minutes
	RestaurantSim::getInstance()->setTotalMinutes(value * 60);


	finished = false;																									//reset clear flag
	while (!finished)																									//while loop
	{
		value = -1;																										//set the value to -1
		try {
			RestaurantSim::getInstance()->askIntValue("On what hour (am or pm) would you like your simulation to start?", value);		
			if (value > 0 && value <= 12)																				//if the starting time is not less than 1 or greater than 12
				finished = true;																						//set the clear flag to be true
			else
				throw "invalid current time val";																		//throw exception
		}
		catch (...) { cout << "ERROR: invalid input. (Min 1, Max 12) Please try again."; }
	}

	finished = false;																									//reset clear flag
	while (!finished)																									//while loop
	{
		try {
			cout << endl << "Is that AM or PM? ";
			getline(cin, init);
			if (init == "AM" || init == "am" || init == "Am")															//if the user typed in am
			{
				if (value == 12)																						//if it is 12 am
					value = 0;																							//hour starts at 0

				finished = true;																						//set clear flag true
			}
			else if (init == "PM" || init == "pm" || init == "Pm")														//if the user typed in pm
			{
				if (value == 12)																						//if it is 12 pm
					value = 12;																							//value stays the same
				else
					value += 12;																						//otherwise... add 12 to the value

				finished = true;																						//set clear flag true
				
			}
			else
				throw "invalid Am/Pm";																					//otherwise, throw exception																				//otherwise, set the clear flag to be true
		}
		catch (...) { cout << "ERROR: invalid input. (Only AM or PM) Please try again."; }
	}
	RestaurantSim::getInstance()->setStartingTime(value * 60);
	Clock::getInstance()->setMinute(getStartingTime());
	Clock::getInstance()->rectify();


	finished = false;																									//reset clear flag
	while (!finished)																									//while loop
	{
		try {
			value = -1;																									//set the value to -1
			RestaurantSim::getInstance()->askIntValue("How many servers would you like to have?", value);
			if (value > 0 && value <= static_cast<int>(RestaurantSim::getInstance()->getTables()->size()))				//if the number of servers are greater than 0 and less than the number of tables
				finished = true;																						//set the clear flag to be true
			else
				throw "invalid server count";																			//throw exception
		}
		catch (...) { cout << "ERROR: invalid input. (Min 1 server, Max table total) Please try again."; }
	}
	RestaurantSim::getInstance()->generateServers(value);
	RestaurantSim::getInstance()->assignTables();


	finished = false;																									//reset clear flag
	while (!finished)																									//while loop
	{
		value = -1;																										//set the value to -1
		try {
			RestaurantSim::getInstance()->askIntValue("How many cooks would you like to have?", value);
			if (value > 0 && value <= static_cast<int>(RestaurantSim::getInstance()->getTables()->size()))				//if the number of servers are greater than 0 and less than the number of tables
				finished = true;																						//set the clear flag to be true
			else
				throw "invalid cook count";																				//throw exception
		}
		catch (...) { cout << "ERROR: invalid input. (Min 1 cook, Max table total) Please try again."; }
	}
	RestaurantSim::getInstance()->generateCooks(value);

	stringstream settingStream;																							//stringstream for holding settings
	settingStream << endl
		<< "-------------------------------------------------------------------------------" << endl
		<< "| > > > > > > > > > S I M U L A T I O N  S E T T I N G S  < < < < < < < < < < |" << endl
		<< "-------------------------------------------------------------------------------" << endl
		<< endl
		<< "\tName: " << RestaurantSim::getInstance()->getRestaurantName() << endl
		<< "\tStyle: " << RestaurantSim::getInstance()->getStyle() << endl
		<< "\tTables: " << RestaurantSim::getInstance()->getTotalTables() << endl
		<< "\tFrequency: " << RestaurantSim::getInstance()->getCustomerFrequency() << endl
		<< "\tTotal Minutes: " << RestaurantSim::getInstance()->getTotalMinutes() << endl
		<< "\tStarting Time: " << RestaurantSim::getInstance()->getStartingTime() << endl
		<< "\tTotal Servers: " << RestaurantSim::getInstance()->getServers()->size() << endl
		<< "\tTotal Cooks: " << RestaurantSim::getInstance()->getTotalCooks() << endl
		<< endl << endl << "Staffing: " << endl;

	for (int idx = 0; idx < static_cast<int>(RestaurantSim::getInstance()->getEmployees()->size()); idx++)
	{
		settingStream << endl << "\t" << RestaurantSim::getInstance()->getEmployees()->at(idx)->getName() << endl
			<< "\t\tExperience: " << RestaurantSim::getInstance()->getEmployees()->at(idx)->getExperienceLvl() << endl
			<< "\t\tDiligence: " << RestaurantSim::getInstance()->getEmployees()->at(idx)->getDiligentLvl() << endl;
		if (RestaurantSim::getInstance()->getEmployees()->at(idx)->getCharmLvl() > 0)
			settingStream << "\t\tCharisma: " << RestaurantSim::getInstance()->getEmployees()->at(idx)->getCharmLvl() << endl;
	}

	FileLog::getInstance()->addLog(settingStream.str());																//add the string stream to the log
	FileLog::getInstance()->saveLog();																					//saves the log

	start();																											//start the simulation
}

void RestaurantSim::start()
{
	stringstream temp;																	//create a temporary string stream
	temp << endl << endl
		<< "-------------------------------------------------------------------------------" << endl
		<< "| > > > > > > > > > >  S I M U L A T I O N   S T A R T  < < < < < < < < < < < |" << endl
		<< "-------------------------------------------------------------------------------" << endl << endl;
	cout << temp.str();																	//display everything in the stream
	FileLog::getInstance()->addLog(temp.str());											//add the string stream to the log

	while (Clock::getInstance()->getMinuteCounter() < (getTotalMinutes() + 1))			//while the simulation is active all event actions will occur in this loop			
	{
		////////////////// System Actions /////////////////////////
		if ((Clock::getInstance()->getMinuteCounter() %									//generate a customer based on frequency and the time of day
			static_cast<int>(getCustomerFrequency() / timeOfDayMod())) == 0)
		{
			generateParty();															//generate a new party and add it to the queue
		}

		////////////////// Server Actions /////////////////////////
		RestaurantHandler::getInstance()->notify("seat parties");						//all available servers will check to see if there are any party that is waiting to be seated
		RestaurantHandler::getInstance()->notify("take orders");						//all available servers will check the order queue to see if there are any custoemrs waiting to order
		RestaurantHandler::getInstance()->notify("take re-orders");						//all available servers will check to see if their assigned customers need to re-order and set them back up in the queue
		RestaurantHandler::getInstance()->notify("serve food");							//all available servers will check to see if their assigned customers have food that is ready to serve
		RestaurantHandler::getInstance()->notify("cash out");							//all available servers will check to see if any of their assigned customers need to cash out
		RestaurantHandler::getInstance()->notify("clean tables");						//all available servers will check the tables to see if they are clean

		//////////////////// Cook Actions ///////////////////////
		RestaurantHandler::getInstance()->notify("add orders");							//all available cooks will add orders to be prepped
		RestaurantHandler::getInstance()->notify("prep orders");						//all available cooks will prep any items in the food order queue
		RestaurantHandler::getInstance()->notify("cook orders");						//all available cooks will check to see if there are any orders that need to be cooked
		RestaurantHandler::getInstance()->notify("re-cook orders");						//all available cooks will check to see if there are any orders that need to be re-cooked
		RestaurantHandler::getInstance()->notify("finish orders");						//all available cooks will check to see if there are any orders that need to be finished up

		////////////////// Customer Actions ////////////////////
		CustomerHandler::getInstance()->notify("check orders");							//party will check to see if their food is ready and ask/check if all orders are correct
		CustomerHandler::getInstance()->notify("check testy");							//party will take action to show they are upset
		CustomerHandler::getInstance()->notify("party leave");							//party will leave if they waited way too long

		///////////////////// Reactions ///////////////////////
		RestaurantHandler::getInstance()->notify("add minute");							//send an add minute message to all employees and act accordingly
		CustomerHandler::getInstance()->notify("add minute");							//send an add minute message to all customers and act accordingly

		////////////////// System Actions /////////////////////
		if ((Clock::getInstance()->getMinuteCounter() % 15) == 0)						//display the time every 15 minutes
		{
			stringstream stream;														//create a string stream
			stream << endl << endl
				<< "-------------------------------------------------------------------------------" << endl
				<< "| > > > > > > > > > > > > > > > > > " << Clock::getInstance()->sendTime() << " < < < < < < < < < < < < < < < < < |" << endl
				<< "-------------------------------------------------------------------------------" << endl
				<< "\t\t\t  Current Total: " << setprecision(2) << fixed << RestaurantSim::getInstance()->getRevenue() << "$" << endl;
			cout << stream.str();														//display everything in the stream
			FileLog::getInstance()->addLog(stream.str());								//add the string stream to the log
		}

		if ((Clock::getInstance()->getMinuteCounter() % 60) == 0)						//check the time every hour
		{
			FileLog::getInstance()->saveLog();											//saves the log every hour
		}

		Clock::getInstance()->addMinute();												//add a minute after all actions have occured
		RestaurantSim::getInstance()->wait();											//wait for real time to pass before continuing
	}

	end();
}


void RestaurantSim::end()
{
	stringstream stream;

	stream << endl << endl
		<< "-------------------------------------------------------------------------------" << endl
		<< "| > > > > > > > > > > > >  S I M U L A T I O N   E N D  < < < < < < < < < < < |" << endl
		<< "-------------------------------------------------------------------------------" << endl
		<< endl;


	stream << endl << "\t\tResults:" << endl << endl
		<< "Name: " << RestaurantSim::getInstance()->getRestaurantName() << endl
		<< "Style: ";
	if (RestaurantSim::getInstance()->getStyle() == 1)
		stream << "Fast Food / Cafeteria";
	else if (RestaurantSim::getInstance()->getStyle() == 2)
		stream << "Typical Restaurant";
	else if (RestaurantSim::getInstance()->getStyle() == 3)
		stream << "Formal / Fine Dining";
	stream << endl << "Number of tables: " << RestaurantSim::getInstance()->getTables()->size() << endl
		<< "Number of servers: " << RestaurantSim::getInstance()->getServers()->size() << endl
		<< "Number of cooks: " << RestaurantSim::getInstance()->getTotalCooks() << endl
		<< endl << "Total number of parties: " << RestaurantSim::getInstance()->getTotalParties() << endl
		<< "Total time parties spent waiting for a table: " << RestaurantSim::getInstance()->getTableWait() << " minutes" << endl
		<< "Total time parties spent waiting for any service: " << RestaurantSim::getInstance()->getTotalWait() << " minutes" << endl
		<< "Average turn around time: " << (RestaurantSim::getInstance()->getTotalWait() / RestaurantSim::getInstance()->getTotalParties()) << " minutes" << endl
		<< endl << "Money Earned: " << setprecision(2) << fixed << RestaurantSim::getInstance()->getRevenue() << "$" << endl
		<< "Money Spent: " << setprecision(2) << fixed << RestaurantSim::getInstance()->getExpenses() << "$" << endl
		<< "Total Profit: " << setprecision(2) << fixed << (RestaurantSim::getInstance()->getRevenue() - RestaurantSim::getInstance()->getExpenses()) << "$" << endl
		<< endl << endl << "Staffing: " << endl;

	for (int idx = 0; idx < static_cast<int>(RestaurantSim::getInstance()->getEmployees()->size()); idx++)
	{
		stream << endl << "\t" << RestaurantSim::getInstance()->getEmployees()->at(idx)->getName() << endl
			<< "\t\tExperience: " << RestaurantSim::getInstance()->getEmployees()->at(idx)->getExperienceLvl() << endl
			<< "\t\tDiligence: " << RestaurantSim::getInstance()->getEmployees()->at(idx)->getDiligentLvl() << endl;
		if (RestaurantSim::getInstance()->getEmployees()->at(idx)->getCharmLvl() > 0)
			stream << "\t\tCharisma: " << RestaurantSim::getInstance()->getEmployees()->at(idx)->getCharmLvl() << endl;		
	}

	cout << stream.str();																							//output the stream
	FileLog::getInstance()->addLog(stream.str());																	//add the string stream to the log
	FileLog::getInstance()->saveLog();																				//saves the log

	cout << endl << endl << endl << "Thank you for using DJ's Restaurant Simulator!!!" << endl						//thank you message
		<< "End Program" << endl;
	system("pause");
}