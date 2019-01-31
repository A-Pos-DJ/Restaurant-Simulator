#include "FileLog.h"


//constructor
FileLog::FileLog()
{

}

//desconstructor
FileLog::~FileLog()
{

}

//singleton Instance
FileLog* FileLog::getInstance()
{
	if (_instance == NULL)
		_instance = new FileLog;
	return _instance;
}

//other functions
vector<string> FileLog::loadFirstNames()							//loads all of the first names into a vector and returns it	
{
	int numItems = 0;												//create int for reading number of items
	string name = "";												//create a string to hold names
	vector <string> firstNames;										//create a vector of strings to hold the names
	ifstream firstNamesFile;										//input file object for getting first names

	firstNamesFile.open("First.txt", ios::out);						//open the file for output
	firstNamesFile >> numItems;										//set the first item in the file to the number of items in the file
	for (int idx = 0; idx < numItems; idx++)						//loop based on the number of items in the file
	{
		firstNamesFile >> name;										//set the string to the current name
		firstNames.push_back(name);									//add the string to the vector
	}
	firstNamesFile.close();											//close the file
	return firstNames;												//return the reference to first names
}

vector<string> FileLog::loadLastNames()								//loads all of the last names into a vector and returns it
{
	int numItems = 0;												//create int for reading number of items
	string name = "";												//create a string to hold names
	vector <string> lastNames;										//create a vector of strings to hold the names
	ifstream lastNamesFile;											//input file object for getting last names

	lastNamesFile.open("Last.txt", ios::out);						//open the file for output
	lastNamesFile >> numItems;										//set the first item in the file to the number of items in the file
	for (int idx = 0; idx < numItems; idx++)						//loop based on the number of items in the file
	{
		lastNamesFile >> name;										//set the string to the current name
		lastNames.push_back(name);									//add the string to the vector
	}
	lastNamesFile.close();											//close the file
	return lastNames;												//return the reference to first names
}

vector <DrinkMenuItem> FileLog::loadDrinkMenu(int style)			//loads all of the drinks into the drink menu based on which style of restaurant is chosen and returns it
{
	int numItems = 0;												//create int for reading number of items
	string n = "";													//create a string for storing name
	double dp = 0.00,												//create a double for storing price
		dc = 0.00;													//create a double for storing cost
	int p = 0,														//create an int for storing prep time
		boolval = 0;												//create a value to convert to a bool
	bool c = false;													//create a bool for storing a chef bool

	vector <DrinkMenuItem> drinkMenu;								//a vector of drink menu items
	ifstream drinkItemsFile;										//input file object for getting drink items

	drinkItemsFile.open("Drink.txt", ios::out);						//open the file for output
	drinkItemsFile >> numItems;										//set the first item in the file to the number of items in the file
	for (int idxS = 0; idxS < style; idxS++)						//loop based on the type of restaurant in the file
	{
		for (int idxD = 0; idxD < numItems; idxD++)					//loop based on the number of items in the file
		{
			DrinkMenuItem drink;									//create a drinkmenu item to hold drink values

			getline(drinkItemsFile, n);								//call getline function to get current drink name
			if (n == "")											//if it got a \n instead...
				getline(drinkItemsFile, n);							//call getline function again to get current drink name
			drinkItemsFile >> dp;									//set the double to the current drink price
			drinkItemsFile >> dc;									//set the double to the current drink item cost
			drinkItemsFile >> p;									//set the int to the current prep time
			drinkItemsFile >> boolval;								//set the bool placeholder to the current chef bool
			c = boolval;											//set the bool to the placeholder

			drink.setName(n);										//set the drink item values
			drink.setPrice(dp);
			drink.setExpense(dc);
			drink.setPrepTime(p);
			drink.setNeedChef(c);

			if (style == (idxS + 1))								//if the current loop matches our style
				drinkMenu.push_back(drink);							//add the drink to the vector
		}
	}
	drinkItemsFile.close();											//close the file
	return drinkMenu;												//return the created drink menu
}

vector <FoodMenuItem> FileLog::loadFoodMenu(int style)				//loads all of the food into the food menu based on which style of restauarnt is chosen and returns it
{
	int numItems = 0;												//create int for reading number of items
	string n = "";													//create a string for storing name
	double dp = 0.00,												//create a double for storing price
		dc = 0.00;													//create a double for storing cost
	int p = 0,														//create an int for storing prep time
		ct = 0,														//create an int for storing cook time
		boolval = 0;												//create a value to convert to a bool
	bool c = false;													//create a bool for storing a chef bool

	vector <FoodMenuItem> foodMenu;									//a vector of food menu items
	ifstream foodItemsFile;											//input file object for getting food items

	foodItemsFile.open("Food.txt", ios::out);						//open the file for output
	foodItemsFile >> numItems;										//set the first item in the file to the number of items in the file
	for (int idxS = 0; idxS < style; idxS++)						//loop based on the type of restaurant in the file
	{
		for (int idxD = 0; idxD < numItems; idxD++)					//loop based on the number of items in the file
		{
			FoodMenuItem food;										//create a foodmenu item to hold food values
			
			getline(foodItemsFile, n);								//call getline function to get current food name
			if(n == "")												//if it got a \n instead...
				getline(foodItemsFile, n);							//call getline function again to get current food name
			foodItemsFile >> dp;									//set the double to the current food price
			foodItemsFile >> dc;									//set the double to the current food item cost
			foodItemsFile >> p;										//set the int to the current prep time
			foodItemsFile >> ct;									//set the int to the current cook time
			foodItemsFile >> boolval;								//set the bool placeholder to the current chef bool
			c = boolval;											//set the bool to the placeholder

			food.setName(n);										//set the food item values
			food.setPrice(dp);
			food.setExpense(dc);
			food.setPrepTime(p);
			food.setCookTime(ct);
			food.setNeedChef(c);

			if (style == (idxS + 1))								//if the current loop matches our style
				foodMenu.push_back(food);							//add the food item to the vector
		}
	}
	foodItemsFile.close();											//close the file
	return foodMenu;												//return the created drink menu
}


//log actions
vector <string>* FileLog::getLog()									//gets the log
{
	return &log;													//returns reference to the log
}

void FileLog::addLog(string message)								//adds a message to the log of strings
{
	FileLog::getInstance()->getLog()->push_back(message);			//adds a message into the log of strings
}

void FileLog::saveLog()																			//saves all messages in the log to Log.txt and clears the log for more text
{
	dataLogFile.open("Log.txt", ios::in| ios::app);											//open the file in append mode for input

	for (int idx = 0; idx < static_cast<int>(FileLog::getInstance()->getLog()->size()); idx++)	//loop through the log
	{
		dataLogFile << FileLog::getInstance()->getLog()->at(idx);								//add the indexxed string to the datalog
	}

	FileLog::getInstance()->getLog()->clear();													//clear out the log for more inputs

	dataLogFile.close();																		//close the file so that it gets saved no matter what
}