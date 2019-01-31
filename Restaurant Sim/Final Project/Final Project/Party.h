#pragma once
#include <vector>
#include "Customer.h"
#include "CustomerHandler.h"
#include "RestaurantSim.h"
#include "FileLog.h"
using namespace std;

class Party : public Observer
{
private:
	string name;							//name of the party
	vector <Customer*> * customers;			//pointer to a a vector of customer pointers
	int tableNum = 0;						//the table number that the party is seated at (0 for not seated yet)

	//party stats//

	int waitLvl = 0,						//how long the party has been waiting
		waitLvlTesty,						//how long the wait is until the party starts to get upset
		waitLvlMax,							//how long the wait until the party leaves upset
		eatLvl = 0,							//how long the party has been eating
		eatLvlMax;							//how long the party needs to stay to eat

	//party states//

	bool waiting = true,					//if the party is waiting (the initial state of the party)
		seated = false,						//if the party is seated
		ordered = false,					//if the party has ordered
		foodReady = false,					//if the party has food ready
		needReOrder = false,				//if the party has food that needs to be reordered
		eating = false,						//if the party is eating their meal
		goodToGo = false,					//if the party is good to pay and leave
		leaving = false;					//if the party in the process of leaving

public:
	//constructors
	Party();
	Party(string _name);

	//deconstructors
	~Party();

	//factory method
	static Party * makeParty(string _name);

	//accessors
	string getName();
	int getTableNum();
	int getWaitLvl();
	int getWaitLvlTesty();
	int getWaitLvlMax();
	int getEatLvl();
	int getEatLvlMax();
	bool getWaiting();
	bool getSeatedVar();
	bool getOrderedVar();
	bool getFoodReadyVar();
	bool getNeedReOrder();
	bool getEating();
	bool getGoodToGoVar();
	bool getLeaving();

	//mutators
	void setName(string s);
	void setTableNum(int n);
	void setWaitLvl(int n);
	void setWaitLvlTesty();
	void setWaitLvlMax();
	void setEatLvl(int n);
	void setEatLvlMax();
	void setWaiting();
	void setSeated();
	void setOrdered();
	void setFoodReady();
	void setNeedReOrder(bool b);
	void setEating();
	void setGoodToGo();
	void setLeaving(bool b);

	//other functions
	vector <Customer*> * getCustomers();
	void addCustomer(Customer * customer);
	void addWaitLvl();
	void addEatLvl();
	double getPartyTotal();
	void leave();
	void observe();
	void stopObserve();
	void update(string text);
};

