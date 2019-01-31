#include "Cook.h"

//constructor
Cook::Cook()
{

}

Cook::Cook(string _name, int exp, int dil)
{
	setName(_name);
	setExperienceLvl(exp);
	setDiligentLvl(dil);
	setSpeed();
	setPrecision();
	setMistakeChance();
	observe();
}

//deconstructor
Cook::~Cook()
{

}

//factory method
Cook* Cook::makeCook(string _name, int exp, int dil)
{
	return new Cook(_name, exp, dil);
}

//accessors
double Cook::getSpeed()
{
	return speed;
}

double Cook::getPrecision()
{
	return precision;
}

int Cook::getMistakeChance()
{
	return mistakeChance;
}

queue <FoodMenuItem*> * Cook::getCookingQueue()
{
	return &cookingQueue;
}

//mutators
void Cook::setSpeed()
{
	speed = (((getExperienceLvl() * 1.5) + (getDiligentLvl() * 0.5)) / 10.0);		//calculation that is weighted on experience
}

void Cook::setPrecision()
{
	precision = (((getExperienceLvl() * 0.5) + (getDiligentLvl() * 1.5)) / 10.0);	//calculation that is weighted on diligence
}

void Cook::setMistakeChance()
{
	mistakeChance = abs(static_cast<int>((89 + (getPrecision() * 5))) - 100);		//on average, about 80% chance to get things correct
}

//other functions
bool Cook::failureChance()
{
	if (((rand() % 100) + 1) <= getMistakeChance())									//generates a number betweeen 1 - 100 and compares it to the chance to make a mistake
	{
		return false;
	}

	return true;
}

void Cook::addChefLvl()
{
	int queueSize = static_cast<int>(getCookingQueue()->size());		//intger to ensure the exit condition of the loop does not change while we modify it
	queue <FoodMenuItem*>* temp = new queue <FoodMenuItem*>;			//create a temp pointer
	for (int idx = 0; idx < queueSize; idx++)							//use the integer value to loop to avoid problems
	{
		getCookingQueue()->front()->addChefLvl();						//add chef level
		temp->push(getCookingQueue()->front());							//add current front of queue to the temp queue
		getCookingQueue()->pop();										//remove the front of the cooking queue to move on to the next one	
	}
	queueSize = static_cast<int>(temp->size());							//set the queue size to match the temp queue
	for (int idx = 0; idx < queueSize; idx++)							//loop through the temp queue
	{
		if (!temp->front()->getReadyVal())								//if the current food item is NOT ready...
			getCookingQueue()->push(temp->front());						//add front of temp queue to the cooking queue

		temp->pop();													//remove the element in the temp queue
	}
	delete temp;														//delete temp pointer
}

void Cook::cookActions(string action)
{
	if (!getBusyVal())
	{
		int time = 0;
		int queueSize = static_cast<int>(getCookingQueue()->size());									//intger to ensure the exit condition of the loop does not change while we modify it
		bool actionTaken = false;																		//boolean or prevent more than 1 action from happening at a time

		queue <FoodMenuItem*>* temp = new queue <FoodMenuItem*>;										//create a temp pointer
		for (int idx = 0; idx < queueSize; idx++)														//use the integer value to loop to avoid problems
		{
			if (actionCondition(action, getCookingQueue()->front()))									//if the condition is true according to the action taken
			{
				if (!actionTaken)																		//if no action has been taken yet
				{
					time = foodAction(action, getCookingQueue()->front());								//set the action for the food item and the time it takes to complete it

					if (getCookingQueue()->front()->getName() != "" &&									//if the item is not null and...
						 (action != "finish" || getCookingQueue()->front()->getCookCorrectVal()))		//if the action is anything but finish, or the food item did not have a mistake
					{
						cout << endl;
						Clock::getInstance()->displayTime();											//display a specific message
						cout << "  " << getName();
						if (action == "prep")
							cout << " is prepping the kitchen for a ";
						else if (action == "cook")
							cout << " has started to cook a ";
						else if (action == "recook")
							cout << " is getting ready to remake a ";
						else if (action == "finish")
							cout << " finished up with cooking a ";
						cout << getCookingQueue()->front()->getName();
					}
					actionTaken = true;															//an action has been taken
					setBusyLvl(getBusyLvl() + static_cast<int>(
						(time * RestaurantSim::getInstance()->getStyleModifier()) / getSpeed()));//set the cook to be busy for a specific amount of time
					setBusyVal(true);															//set the cook to be busy
				}
			}
			temp->push(getCookingQueue()->front());												//add current front of queue to the temp queue
			getCookingQueue()->pop();															//remove the front of the cooking queue to move on to the next one	
		}
		queueSize = static_cast<int>(temp->size());												//set the queue size to match the temp queue
		for (int idx = 0; idx < queueSize; idx++)												//loop through the temp queue
		{
			if ((!temp->front()->getReadyVal() || !temp->front()->getOrderCorrect()) ||
				temp->front()->getName() != "")													//if the current food item is NOT ready, the order was NOT made correctly or order is NULL...
				getCookingQueue()->push(temp->front());											//add front of temp queue to the cooking queue

			temp->pop();																		//remove the element in the temp queue
		}
		delete temp;																			//delete temp pointer
	}
}

bool Cook::actionCondition(string action, FoodMenuItem* food)
{
	if (action == "prep")
	{
		if(food->getNeedChef() &&				//if the food needs a chef to make it
			food->getNeedPrep() &&				//if the food needs to be prepped
			!food->getNeedCook() &&				//if the food needs to be cooked
			!food->getCooking() &&				//if the food is currently cooking
			!food->getNeedReCook() &&			//if the food needs to be re-cooked
			!food->getReadyVal() &&				//if the food is ready
			(food->getChefLvl() >=				//if the chef level is greater than the prep time needed
			food->getPrepTime()))
		{
			return true;
		}
	}
	else if (action == "cook")
	{
		if (food->getNeedChef() &&				//if the food needs a chef to make it
			!food->getNeedPrep() &&				//if the food needs to be prepped
			food->getNeedCook() &&				//if the food needs to be cooked
			!food->getCooking() &&				//if the food is currently cooking
			!food->getNeedReCook() &&			//if the food needs to be re-cooked
			!food->getReadyVal())				//if the food is ready
		{
			return true;
		}
	}
	else if (action == "recook")
	{
		if (food->getNeedChef() &&				//if the food needs a chef to make it
			!food->getNeedPrep() &&				//if the food needs to be prepped
			!food->getNeedCook() &&				//if the food needs to be cooked
			!food->getCooking() &&				//if the food is currently cooking
			food->getNeedReCook() &&			//if the food needs to be re-cooked
			!food->getReadyVal())				//if the food is ready
		{
			return true;
		}
	}
	else if (action == "finish")
	{
		if (food->getNeedChef() &&				//if the food needs a chef to make it
			!food->getNeedPrep() &&				//if the food needs to be prepped
			!food->getNeedCook() &&				//if the food needs to be cooked
			food->getCooking() &&				//if the food is currently cooking
			!food->getNeedReCook() &&			//if the food needs to be re-cooked
			!food->getReadyVal() &&				//if the food is ready
			(food->getChefLvl() >=				//if the chef level is greater than the time needed to cook
			food->getCookTime()))
		{
			return true;
		}
	}

	return false;								//if the conditions do not match, return false
}

int Cook::foodAction(string action, FoodMenuItem* food)
{
	if (action == "prep")
	{
		food->setNeedPrep(false);														//the item is good on prep work
		food->setNeedCook(true);														//it needs to be cooked
	}
	else if (action == "cook")
	{
		food->setNeedCook(false);														//the item no longer needs to be cooked
		food->setCooking(true);															//because the item is currently cooking
		food->setChefLvl(0);															//reset the chef level of the item cooking
		return 2;																		//set the amount of time it takes to get something cooking
	}
	else if (action == "recook")
	{
		food->setNeedPrep(true); 														//food needs to be prepped
		food->setNeedCook(false); 														//food needs to be cooked
		food->setCooking(false); 														//food is not currently cooking
		food->setNeedReCook(false);														//food no longer will need to be re-cooked
		food->setReadyVal(false);														//if the food is NOT ready
		food->setChefLvl(0);															//reset the chef level
		RestaurantSim::getInstance()->addExpenses(food->getExpense());					//add another food item to expenses
		return 2;																		//set the amount of time it takes to get something else cooking
	}
	else if (action == "finish")
	{

		if (food->getOrderCorrect())												//if the order is correct
			food->setCookCorrectVal(failureChance());								//there is still a chance for the cook to mess it up
		else if (!food->getOrderCorrect())											//if the order was not correct
			food->setCookCorrectVal(true);											//there is no way the chef can mess up more

		if (!food->getCookCorrectVal())												//if the cook does mess it up....
		{
			cout << endl;
			Clock::getInstance()->displayTime();
			if(food->getName() != "")
				cout << "  " << getName() << " made a mistake while cooking "		//name the chef and display that he/she made a mistake
				<< food->getName() << "...";										//name of the item that was messed up

			food->setNeedPrep(false); 											
			food->setNeedCook(false); 											
			food->setCooking(false); 											
			food->setNeedReCook(true);												//food will need to be re-cooked
			food->setReadyVal(false);												
			return 2;																//set the amount of time it takes to get this mistake prepped
		}
		else
		{
			food->setReadyVal(true);												//set the food to be ready
			return 2;																//set the amount of time it takes to set out a plate
		}
	}
	return 0;																		//if none of these apply, return 0
}

void Cook::update(string message)
{
	if (message == "add minute")
	{
		if (!getBusyVal())						//if the cook is not busy with anything
			addWaitLvl();						//add to their wait level
		else if (getBusyVal())					//if the cook is busy
		{
			setWaitLvl(0);						//set the wait level of the cook to 0
			if (getBusyLvl() > 0)				//if the busy lvl is greater than 0
			{
				setBusyLvl(getBusyLvl() - 1);	//take away 1
			}
			else if (getBusyLvl() <= 0)			//if the busy level is less than or equal to 0
			{
				setBusyLvl(0);					//set the busy level to 0
				setBusyVal(false);				//the cook is no longer busy with anything
			}
		}
		addChefLvl();
	}
	else if (message == "add orders")
	{
		if (!RestaurantSim::getInstance()->getChefQueue()->empty() && !getBusyVal())	//if there is something in the chef queue and the chef is not busy
		{
			getCookingQueue()->push(RestaurantSim::getInstance()->getChefQueue()->front());	//set the food item to the queue
			RestaurantSim::getInstance()->getChefQueue()->pop();						//remove this item from the chef queue

			getCookingQueue()->back()->setNeedChef(true);								//if the fodd needs to be prepared by a chef
			getCookingQueue()->back()->setNeedPrep(true);								//if the food needs to be prepped
			getCookingQueue()->back()->setNeedCook(false);								//if the food needs to be cooked
			getCookingQueue()->back()->setCooking(false);								//if the food is currently cooking
			getCookingQueue()->back()->setNeedReCook(false);							//if the food needs to be re-cooked
			getCookingQueue()->back()->setReadyVal(false);								//if the food is ready

			setBusyLvl(getBusyLvl() + static_cast<int>(getCookingQueue()->back()->
				getPrepTime() / getSpeed()));											//set the cook to be busy for the amount of time it takes to prep this item
			setBusyVal(true);															//set the cook to be busy
		}
	}
	else if (message == "prep orders")
	{
		cookActions("prep");													
	}
	else if (message == "cook orders")
	{
		cookActions("cook");
	}
	else if (message == "re-cook orders")
	{
		cookActions("recook");
	}
	else if (message == "finish orders")
	{
		cookActions("finish");
	}

}
