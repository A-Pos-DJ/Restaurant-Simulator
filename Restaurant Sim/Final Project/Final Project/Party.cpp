#include "Party.h"

//constructors
Party::Party()
{

}

Party::Party(string _name)
{
	setName(_name);
	if (customers == NULL)
		customers = new vector <Customer*>;
	observe();												
}

//deconstructors
Party::~Party()
{
	stopObserve();
}

//factory method
Party * Party::makeParty(string _name)
{
	return new Party(_name);
}

//accessors
string Party::getName()
{
	return name;
}

int Party::getTableNum()
{
	return tableNum;
}

int Party::getWaitLvl()
{
	return waitLvl;
}

int Party::getWaitLvlTesty()
{
	return waitLvlTesty;
}

int Party::getWaitLvlMax()
{
	return waitLvlMax;
}

int Party::getEatLvl()
{
	return eatLvl;
}

int Party::getEatLvlMax()
{
	return eatLvlMax;
}

bool Party::getWaiting()
{
	return waiting;
}

bool Party::getSeatedVar()
{
	return seated;
}

bool Party::getOrderedVar()
{
	return ordered;
}

bool Party::getFoodReadyVar()
{
	return foodReady;
}

bool Party::getNeedReOrder()
{
	return needReOrder;
}

bool Party::getEating()
{
	return eating;
}

bool Party::getGoodToGoVar()
{
	return goodToGo;
}

bool Party::getLeaving()
{
	return leaving;
}


//mutators
void Party::setName(string s)
{
	name = s;
}

void Party::setTableNum(int n)
{
	tableNum = n;
}

void Party::setWaitLvl(int n)
{
	if (n < 0)										//if the input is less than 0
		waitLvl = 0;								//set the wait level to 0
	else
		waitLvl = n;								//otherwise, set the wait level to the input
}

void Party::setWaitLvlTesty()
{
	int waitLvlTotal = 0;														//create an int accumulator
	for (int idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)	//loop through all customers in the party
	{
		waitLvlTotal += getCustomers()->at(idx)->getWaitLvlTesty();				//add to the total wait lvl testy of each customer
	}

	waitLvlTesty = waitLvlTotal / static_cast<int>(getCustomers()->size());		//divide by the number of customers to get the average
}

void Party::setWaitLvlMax()
{
	int waitLvlTotal = 0;														//create an int accumulator
	for (int idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)	//loop through all customers in the party
	{
		waitLvlTotal += getCustomers()->at(idx)->getWaitLvlMax();				//add to the total wait lvl max of each customer
	}

	waitLvlMax = waitLvlTotal / static_cast<int>(getCustomers()->size());		//divide by the number of customers to get the average
}

void Party::setEatLvl(int n)
{
	if (n < 0)									//if the input is less than 0
		eatLvl = 0;								//set the wait level to 0
	else
		eatLvl = n;								//otherwise, set the wait level to the input
}

void Party::setEatLvlMax()
{
	int highest = getCustomers()->at(0)->getEatLvlMax();						//create an int to hold highest eat lvl max
	for (int idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)	//loop through all customers in the party
	{
		if (getCustomers()->at(idx)->getEatLvlMax() > highest)					//if the index eatLvlMax is greater than the current...
			highest = getCustomers()->at(idx)->getEatLvlMax();					//set the max to the new max
	}

	eatLvlMax = highest;
}

void Party::setWaiting()
{
	int idx = 0;																//create an index int to help with for loop
	bool flag = false;															//create a boolean flag to see if the condition is ever true
	for (idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)		//loop through all customers in the party
	{
		if (getCustomers()->at(idx)->getWaiting())								//if a customer in the party is waiting...
			flag = true;														//set the flag to be true
	}
	waiting = flag;																//if somebody in the party is waiting, then the flag will be true for the party
}

void Party::setSeated()
{
	int idx = 0;																//create an index int to help with for loop
	bool flag = true;															//create a boolean flag to see if the condition is ever false
	for (idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)		//loop through all customers in the party
	{
		if (!getCustomers()->at(idx)->getSeatedVar())							//if a customer in the party is NOT seated...
			flag = false;														//set the flag to be false
	}
	seated = flag;																//if somebody in the party is NOT seated, then the flag will be false for the party
}

void Party::setOrdered()
{
	int idx = 0;																//create an index int to help with for loop
	bool flag = true;															//create a boolean flag to see if the condition is ever false
	for (idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)		//loop through all customers in the party
	{
		if (!getCustomers()->at(idx)->getOrdered())								//if a customer in the party has NOT ordered...
			flag = false;														//set the flag to be false
	}
	ordered = flag;																//if somebody in the party has NOT ordered, then the flag will be false for the party
}

void Party::setFoodReady()
{
	int idx = 0;																//create an index int to help with for loop
	bool flag = true;															//create a boolean flag to see if the condition is ever false
	for (idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)		//loop through all customers in the party
	{
		if (!getCustomers()->at(idx)->getFoodReadyVar())						//if a customer in the party does NOT have food ready...
			flag = false;														//set the flag to be false
	}
	foodReady = flag;															//if somebody in the party does NOT have food ready, then the flag will be false for the party
}

void Party::setNeedReOrder(bool b)
{
	needReOrder = b;
}

void Party::setEating()
{
	int idx = 0;																//create an index int to help with for loop
	bool flag = true;															//create a boolean flag to see if the condition is ever false
	for (idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)		//loop through all customers in the party
	{
		if (!getCustomers()->at(idx)->getEating())								//if a customer in the party is NOT eating...
			flag = false;														//set the flag to be false
	}
	eating = flag;																//if somebody in the party is NOT eating, then the flag will be false for the party
}

void Party::setGoodToGo()
{
	int idx = 0;																//create an index int to help with for loop
	bool flag = true;															//create a boolean flag to see if the condition is ever false
	for (idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)		//loop through all customers in the party
	{
		if (!getCustomers()->at(idx)->getGoodToGo())							//if a customer in the party is NOT good to go...
			flag = false;														//set the flag to be false
	}
	goodToGo = flag;															//if somebody in the party is NOT good to go, then the flag will be false for the party
}

void Party::setLeaving(bool b)
{
	leaving = b;
}


//other functions
vector <Customer*> * Party::getCustomers()
{
	return customers;
}

void Party::addCustomer(Customer * customer)
{
	customers->push_back(customer);
	customer->observe();
	setWaitLvlTesty();
	setWaitLvlMax();
	setEatLvlMax();
}

void Party::leave()
{
	stringstream stream;														//create a string stream object
	if (getGoodToGoVar() && (getWaitLvl() < getWaitLvlTesty()))
	{
		stream << endl
			<< Clock::getInstance()->sendTime()
			<< "  The " << getName() << " party has left and enjoyed their meal!\n"
			<< "\t\t\t   Ticket Total: "<< setprecision(2) << fixed << getPartyTotal() << "$";
	}
	else if (getGoodToGoVar() && (getWaitLvl() >= getWaitLvlTesty()) && (getWaitLvl() < getWaitLvlMax()))
	{
		stream << endl
			<< Clock::getInstance()->sendTime()
			<< "  The " << getName() << " party finished eating and left\n"
			<< "\t\t\t   Ticket Total: " << setprecision(2) << fixed << getPartyTotal() << "$";
	}
	else if (getGoodToGoVar() && (getWaitLvl() >= getWaitLvlMax()))
	{
		stream << endl
			<< Clock::getInstance()->sendTime()
			<< "  The " << getName() << " party finished eating and left unhappy\n"
			<< "\t\t\t   Ticket Total: " << setprecision(2) << fixed << getPartyTotal() << "$";
	}
	else if (!getGoodToGoVar())
	{
		stream << endl
			<< Clock::getInstance()->sendTime()
			<< "  The " << getName() << " party has left angrilly\n"
			<< "\t\t\t   Ticket Total: " << setprecision(2) << fixed << 00.00 << "$";
	}

	cout << stream.str();														//display everything in the stream
	FileLog::getInstance()->addLog(stream.str());								//add the stream to the log

	for (int idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)	//loop through all customers in the party
	{
		getCustomers()->at(idx)->~Customer();									//run the customer deconstructor.
	}

	this->~Party();																//remove the party from existance
}

void Party::addWaitLvl()
{
	setWaitLvl(getWaitLvl() + 1);		//add 1 to the wait level
}

void Party::addEatLvl()
{
	setEatLvl(getEatLvl() + 1);			//add 1 to the eat level
}

double Party::getPartyTotal()
{
	double total = 0;
	for (int idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)		//loop through each customer
	{
		total += getCustomers()->at(idx)->getDrinkOrder()->getPrice();				//add drink price
		total += getCustomers()->at(idx)->getFoodOrder()->getPrice();				//add food price
	}
	return total;
}

void Party::observe()
{
	CustomerHandler::getInstance()->attach(this);
}

void Party::stopObserve()
{
	CustomerHandler::getInstance()->detach(this);
}

void Party::update(string message)
{
	if (message == "add minute")
	{
		if(!getSeatedVar() && getWaiting())												//if the part is not seated and is waiting
			RestaurantSim::getInstance()->addTableWait();								//add to the total time party is waiting for a table

		if (getWaiting())																//if the party is waiting...
		{
			addWaitLvl();																//add to the wait level
			RestaurantSim::getInstance()->addTotalWait();								//add to the total time party is waiting for a table
		}
		else if (!getWaiting() && getEating())
		{
			if (getEatLvl() >= getEatLvlMax())											//if the party's eat lvl is at the max
			{
				for (int idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)//loop through the customers
				{
					getCustomers()->at(idx)->setEating(false);							//customer is no longer eating
					getCustomers()->at(idx)->setGoodToGo(true);							//customer is good to go
					getCustomers()->at(idx)->setWaiting(true);							//customer is waiting for the check now
				}
				setEating();															//set the party to match the customer
				setGoodToGo();
				setWaiting();
			}
			else																		//if the party is not finished eating...
				addEatLvl();															//add to the eat level instead
		}
	}
	else if (message == "check orders")
	{
		if (getWaiting() && getOrderedVar() && !getEating() && !getFoodReadyVar())		//if the food has been ordered, but is not ready for everyone yet
		{
			for (int idx = 0; idx < static_cast<int>(getCustomers()->size()); idx++)
			{
				if (getCustomers()->at(idx)->getFoodOrder()->getReadyVal())				//if a customer's food is ready
				{
					if (getCustomers()->at(idx)->getFoodOrder()->getOrderCorrect())		//if the order was correct
					{
						getCustomers()->at(idx)->setFoodReadyVar(true);					//set the customer to have food ready
						setFoodReady();													//set the food to be ready for the party if it is ready for everyone
					}
					else if (!getCustomers()->at(idx)->getFoodOrder()->getOrderCorrect())//if the order was incorrect 
					{
						if (!getNeedReOrder())											//if the customer has not already tried to reorder
						{
							stringstream stream;										//create stringstream object
							stream << endl
								<< Clock::getInstance()->sendTime()						//add a message saying the order was incorrect
								<< "  An order of "
								<< getCustomers()->at(idx)->getFoodOrder()->getName()
								<< " had to be sent back to the kitchen...";
							cout << stream.str();										//display the message in the stream
							FileLog::getInstance()->addLog(stream.str());				//add the stream to the log
						}
						getCustomers()->at(idx)->setFoodReadyVar(false);				//set the customer to not have food ready
						setNeedReOrder(true);											//set the need to reorder flag to be true
					}
				}
			}
		}
	}
	else if (message == "check testy")
	{
		if (getWaitLvl() == getWaitLvlTesty())
		{
			stringstream stream;																//create a stringstream object
			if (!getSeatedVar())																//if the party has not been seated
			{
				stream << endl
					<< Clock::getInstance()->sendTime()
					<< "  The " << getName() << " party is getting tired of waiting for a table...";
			}
			else if (getSeatedVar() && !getOrderedVar())										//if the party has not ordered
			{
				stream << endl
					<< Clock::getInstance()->sendTime()
					<< "  The " << getName() << " party at table "
					<< getTableNum()
					<< " is upset with waiting so long to order...";
			}
			else if (getSeatedVar() && getOrderedVar() && !getEating() && !getGoodToGoVar())	//if the party is waiting for their food 
			{
				stream << endl
					<< Clock::getInstance()->sendTime()
					<< "  The " << getName() << " party at table "
					<< getTableNum()
					<< " is asking where their food order is...";
			}
			else if (getGoodToGoVar())															//if the party is waitng to payout
			{
				stream << endl
					<< Clock::getInstance()->sendTime()
					<< "  The " << getName() << " party at table "
					<< getTableNum()
					<< " is waiting impatiently to pay their check...";
			}
			cout << stream.str();																//display the stream
			FileLog::getInstance()->addLog(stream.str());										//add the stream to teh log
		}
	}
	else if (message == "party leave")
	{
		if (getLeaving())																	//if the party is already set on leaving
		{
			leave();																		//then leave
		}
		else if (getWaitLvl() >= getWaitLvlMax() && (!getEating() || !getGoodToGoVar()))	//check to see if the party wants to leave
		{
			setLeaving(true);																//set the party to be leaving in the next minute
		}
	}
}