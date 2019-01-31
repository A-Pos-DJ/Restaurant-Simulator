#include "Server.h"

//constructor
Server::Server(string _name, int exp, int dil, int cha)
{
	setName(_name);
	setExperienceLvl(exp);
	setDiligentLvl(dil);
	setCharmLvl(cha);
	setSpeed();
	setPrecision();
	setAttitude();
	setMistakeChance();
	observe();
}

//deconstructor
Server::~Server()
{
	stopObserve();
}

//factory method
Server* Server::makeServer(string _name, int exp, int dil, int cha)
{
	return new Server(_name, exp, dil, cha);
}


//accessors
double Server::getSpeed()
{
	return speed;
}

double Server::getPrecision()
{
	return precision;
}

double Server::getAttitude()
{
	return attitude;
}

int Server::getMistakeChance()
{
	return mistakeChance;
}


vector <Table*> * Server::getTablesAssigned()
{
	return &tablesAssigned;
}

queue <Party*> * Server::getPartiesAssigned()
{
	return &partiesAssigned;
}

//mutators
void Server::setSpeed()
{
	speed = (((getExperienceLvl() * 1.5) + (getDiligentLvl() * 0.5)) / 10.0);		//calculation that is weighted on experience
}

void Server::setPrecision()
{
	precision = (((getExperienceLvl() * 0.5) + (getDiligentLvl() * 1.5)) / 10.0);	//calculation that is weighted on diligence
}

void Server::setAttitude()
{																					 	
	attitude = (((getCharmLvl() * 2.0) +											//calculation that is weighted on charm, but
		(getExperienceLvl() * 0.25) + (getDiligentLvl() * 0.75)) / 15.0);			//a little experience and mostly diligence play a part																							
}

void Server::setMistakeChance()
{
	mistakeChance = abs(static_cast<int>((89 + (getPrecision() * 5))) - 100);		//on average, about 90% chance to get things correct
}

//other functions
bool Server::checkForMistake()
{
	if (((rand() % 100) + 1) <= getMistakeChance())									//generates a number betweeen 1 - 100 and compares it to the chance to make a mistake
	{
		return true;
	}

	return false;
}

void Server::assignTable(Table * table)
{
	getTablesAssigned()->push_back(table);			//assign a table to the vector
}

void Server::cleanAssignedTable(int time)
{
	for (int idx = 0; idx < static_cast<int>(getTablesAssigned()->size()); idx++)	//loop through all of the assigned tables
	{
		if (!getTablesAssigned()->at(idx)->getCleanVal())							//if there is a table that is NOT clean
		{
			getTablesAssigned()->at(idx)->setClean(true);							//clean it
			stringstream stream;													//create a string stream object
			stream << endl
				<< Clock::getInstance()->sendTime()									//add a specific message
				<< "  " << getName()
				<< " cleaned off table "
				<< getTablesAssigned()->at(idx)->getTableNum();
			cout << stream.str();													//display everything in the stream
			FileLog::getInstance()->addLog(stream.str());							//add the stream to the log
			setBusyLvl(getBusyLvl() + static_cast<int>(time / getSpeed()));			//set how long the server will take for the action
			setBusyVal(true);
			return;
		}
	}
}

void Server::defileTable(int tableNum)
{
	for (int idx = 0; idx < static_cast<int>(getTablesAssigned()->size()); idx++)	//loop through all of the assigned tables
	{
		if (getTablesAssigned()->at(idx)->getTableNum() == tableNum)				//if the indexed table number matches the argument
		{
			getTablesAssigned()->at(idx)->setClean(false);							//make the table dirty
			getTablesAssigned()->at(idx)->setOccupied(false);						//make the table unoccupied
			getTablesAssigned()->at(idx)->removeParty();							//remove all traces of the previous customer
		}
	}
}

bool Server::checkDirtyTables()
{
	for (int idx = 0; idx < static_cast<int>(getTablesAssigned()->size()); idx++)	//loop through all of the assigned tables
	{
		if (!getTablesAssigned()->at(idx)->getCleanVal())							//if there is a table that is NOT clean
			return true;															//return true
	}
	return false;																	//otherwise, return false
}

void Server::assignParty(Party * party)
{
	getPartiesAssigned()->push(party);				//put a party in the queue
}

void Server::seatParty(Party * party)
{
	for (int idx = 0; idx < static_cast<int>(getTablesAssigned()->size()); idx++)
	{
		if (getTablesAssigned()->at(idx)->getCleanVal() &&							//if the table is clean and unoccupied
			!getTablesAssigned()->at(idx)->getOccupiedVal())
		{
			getTablesAssigned()->at(idx)->addParty(party);							//assign the party to it
			getTablesAssigned()->at(idx)->setOccupied(true);						//set the table to be occupied
			party->setTableNum(getTablesAssigned()->at(idx)->getTableNum());		//assign the table number to the party
			return;																	//return after assigning a single table
		}
	}
}

bool Server::assignNextParty()
{
	if (RestaurantSim::getInstance()->getSeatQueue()->empty())							//if there is nothing in the wait queue
		return false;																	//return false
	else
	{
		for (int idx = 0; idx < static_cast<int>(getTablesAssigned()->size()); idx++)	//loop through all of the assigned tables
		{
			if (getTablesAssigned()->at(idx)->getCleanVal() &&							//if an assigned table is clean and unoccupied
				!getTablesAssigned()->at(idx)->getOccupiedVal())
			{
				assignParty(RestaurantSim::getInstance()->getSeatQueue()->front());		//assign the party to the party queue
				RestaurantSim::getInstance()->getSeatQueue()->pop();					//remove this party from the waiting queue
				return true;
			}
		}
	}
	return false;																		//if unable to find a viable table for the party, return false
}

void Server::serverAction(string action, int relief, int time)
{
	if (!getBusyVal())																					//if the server is not busy
	{
		int queueSize = static_cast<int>(getPartiesAssigned()->size());									//intger to ensure the exit condition of the loop does not change while we modify it
		bool actionTaken = false;																		//boolean or prevent more than 1 action from happening at a time

		queue <Party*>* temp = new queue <Party*>;														//create a temp pointer
		for (int idx = 0; idx < queueSize; idx++)														//use the integer value to loop to avoid problems
		{
			if (actionCondition(action, getPartiesAssigned()->front()))									//if the condition is true according to the action taken
			{
				if (!actionTaken)																		//if no action has been taken yet
				{
					for (int idxP = 0; idxP < static_cast<int>(											//loop through the party in which the conditions are true
						getPartiesAssigned()->front()->getCustomers()->size()); idxP++)
					{
						customerAction(action, getPartiesAssigned()->front()->getCustomers()->at(idxP));//set the action for the indivdual customer
						setBusyVal(true);																//set the server to be busy
						setBusyLvl(getBusyLvl() + static_cast<int>(
							(time * RestaurantSim::getInstance()->getStyleModifier()) / getSpeed()));	//set how long the server will take for all of the combined actions
					}
					partyAction(action, getPartiesAssigned()->front());									//set the action for the party
					
					if (getPartiesAssigned()->front()->getName() != "")									//do not display message if the assigned party is null
					{
						stringstream stream;															//create a string stream object
						stream << endl
							<< Clock::getInstance()->sendTime()											//display a specific message
							<< "  The " << getPartiesAssigned()->front()->getName();

						if (action == "seat")
							stream << " party was seated by ";
						else if (action == "order")
							stream << " party had their orders taken by ";
						else if (action == "reorder")
							stream << " party had their orders fixed by ";
						else if (action == "serve")
							stream << " party was served their food by ";
						else if (action == "cash")
							stream << " party was cashed out by ";

						stream << getName()
							<< " at table "
							<< getPartiesAssigned()->front()->getTableNum();
						cout << stream.str();													//display everything in the stream
						FileLog::getInstance()->addLog(stream.str());							//add everything from the stream to the log

					}
					getPartiesAssigned()->front()->setWaitLvl(
						getPartiesAssigned()->front()->getWaitLvl()	- static_cast<int>(			//reduce the customer's wait level by the relief amount & attidude
						(relief * RestaurantSim::getInstance()->getStyleModifier())
							* getAttitude()));
					actionTaken = true;															//an action has been taken
				}
			}
			temp->push(getPartiesAssigned()->front());											//add current front of queue to the temp queue
			getPartiesAssigned()->pop();														//remove the front of the assign party queue to move on to the next one	
		}
		queueSize = static_cast<int>(temp->size());												//set the queue size to match the temp queue
		for (int idx = 0; idx < queueSize; idx++)												//loop through the temp queue
		{
			if (!temp->front()->getLeaving() || temp->front()->getName() != "")					//if the current party is NOT leaving or NULL...
				getPartiesAssigned()->push(temp->front());										//add front of temp queue to the party queue
			else																					//otherwise...
				defileTable(temp->front()->getTableNum());										//make the table messy and unassign it from the current party
			temp->pop();																		//remove the element in the temp queue
		}
		delete temp;																			//delete temp pointer
	}
}

bool Server::actionCondition(string action, Party* party)
{
	if (action == "seat")
	{
		if (party->getWaiting() &&				//if the party is waiting (the initial state of the party)
			!party->getSeatedVar() &&			//if the party is seated
			!party->getOrderedVar() &&			//if the party has ordered
			!party->getFoodReadyVar() &&		//if the party has food ready
			!party->getNeedReOrder() &&			//if the party has food that needs to be reordered
			!party->getEating() &&				//if the party is eating their meal
			!party->getGoodToGoVar()&&			//if the party is good to pay and leave
			!party->getLeaving())				//if the party is leaving
		{
			return true;
		}
	}
	else if (action == "order")
	{
		if (party->getWaiting() &&				//goes though all of the possible conditions to ensure the program runs properly
			party->getSeatedVar() &&
			!party->getOrderedVar() &&
			!party->getFoodReadyVar() &&
			!party->getNeedReOrder() &&
			!party->getEating() &&
			!party->getGoodToGoVar() &&
			!party->getLeaving())
		{
			return true;
		}
	}
	else if (action == "reorder")
	{
		if (party->getWaiting() &&				//goes though all of the possible conditions to ensure the program runs properly
			party->getSeatedVar() &&
			party->getOrderedVar() &&
			!party->getFoodReadyVar() &&
			party->getNeedReOrder() &&
			!party->getEating() &&
			!party->getGoodToGoVar() &&
			!party->getLeaving())
		{
			return true;
		}
	}
	else if (action == "serve")
	{
		if (party->getWaiting() &&				//goes though all of the possible conditions to ensure the program runs properly
			party->getSeatedVar() &&
			party->getOrderedVar() &&
			party->getFoodReadyVar() &&
			!party->getNeedReOrder() &&
			!party->getEating() &&
			!party->getGoodToGoVar() &&
			!party->getLeaving())
		{
			return true;
		}
	}
	else if (action == "cash")
	{
		if (party->getWaiting() &&				//goes though all of the possible conditions to ensure the program runs properly
			party->getSeatedVar() &&
			party->getOrderedVar() &&
			party->getFoodReadyVar() &&
			!party->getNeedReOrder() &&
			!party->getEating() &&
			party->getGoodToGoVar() &&
			!party->getLeaving())
		{
			return true;
		}
	}

	return false;								//if the conditions do not match, return false
}

void Server::customerAction(string action, Customer* customer)
{
	if (action == "seat")
	{
		customer->setSeated(true);							//set the customer to seated
	}
	else if (action == "order")
	{
		customer->getFoodOrder()->setOrderCorrect(			//set the food order to be correct or not
			!checkForMistake());

		RestaurantSim::getInstance()->addChefQueue(
			customer->getFoodOrder());						//add the food order to the chef queue

		customer->setOrdered(true);							//set the customer to ordered


		RestaurantSim::getInstance()->addExpenses(			//add drink expense to the restaurant
			customer->getDrinkOrder()->getExpense());
		RestaurantSim::getInstance()->addExpenses(			//add food expense to the restaurant
			customer->getFoodOrder()->getExpense());


	}
	else if (action == "reorder")
	{
		if (!customer->getFoodOrder()->getOrderCorrect() &&	//if a food item from the customer is ready, but incorrect
			customer->getFoodOrder()->getReadyVal())
		{
			customer->getFoodOrder()->setNeedPrep(false);	//the food needs to be prepped
			customer->getFoodOrder()->setNeedCook(false);	//the food needs to be cooked
			customer->getFoodOrder()->setCooking(false);	//the food is not currently cooking
			customer->getFoodOrder()->setNeedReCook(true);	//the food needs to be re-cooked
			customer->getFoodOrder()->setReadyVal(false);	//the food is no longer ready

			customer->getFoodOrder()->setOrderCorrect(		//set the order to possibly have another mistake
				!checkForMistake());
		}
	}
	else if (action == "serve")
	{
		customer->setEating(true);							//set the customer to be eating
		customer->setWaiting(false);						//set the customer to no longer be waiting
	}
	else if (action == "cash")
	{
		RestaurantSim::getInstance()->addRevenue(			//add drink revenue to the restaurant
			customer->getDrinkOrder()->getPrice());
		RestaurantSim::getInstance()->addRevenue(			//add food revenue to the restaurant
			customer->getFoodOrder()->getPrice());
	}
}

void Server::partyAction(string action, Party* party)
{
	if (action == "seat")
	{
		seatParty(party);									//set the party pointer to a clean unused tables
		party->setSeated();									//set the party to be seated
	}
	else if (action == "order")
	{
		party->setOrdered();								//set the party to ordered
	}
	else if (action == "reorder")
	{
		party->setNeedReOrder(false);						//set the need to re-order for this party to false
	}
	else if (action == "serve")
	{
		party->setEating();									//set the party to be eating	
		party->setWaiting();								//set the party to no longer be waiting
	}
	else if (action == "cash")
	{
		party->setLeaving(true);							//set the party to leave
	}
}

void Server::update(string message)
{
	if (message == "add minute")
	{
		if (!getBusyVal())						//if the server is not busy with anything
		addWaitLvl();							//add to their wait level
		else if (getBusyVal())					//if the server is busy
		{
			setWaitLvl(0);						//set the wait level of the server to 0
			if (getBusyLvl() > 0)				//if the busy lvl is greater than 0
			{
				setBusyLvl(getBusyLvl() - 1);	//take away 1
			}
			else if (getBusyLvl() <= 0)			//if the busy level is less than or equal to 0
			{
				setBusyLvl(0);					//set the busy level to 0
				setBusyVal(false);				//the server is no longer busy with anything
			}
		}
	}
	else if (message == "clean tables")
	{
		if (!getBusyVal() && checkDirtyTables())
		{
			cleanAssignedTable(4);
		}
	}
	else if (message == "seat parties")
	{
		if (!getBusyVal())								//checks to see if server is busy
			if(assignNextParty())						//check to see if a party can be assigned to the server's clean table and assigns it.
				serverAction("seat", 30, 1);			//runs server action "seat"
	}
	else if (message == "take orders")
	{
		serverAction("order", 10, 1);					//runs server action "order"
	}
	else if (message == "take re-orders")
	{
		serverAction("reorder", 10, 1);					//runs the server action "reorder"
	}
	else if (message == "serve food")
	{
		serverAction("serve", 15, 1);					//runs the server action "serve"
	}
	else if (message == "cash out")
	{
		serverAction("cash", 10, 2);					//runs the server action "cash"
	}
}


