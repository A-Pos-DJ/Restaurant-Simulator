#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "RestaurantSim.h"
#include "Employee.h"
#include "Party.h"
#include "Table.h"
using namespace std;

class Table;									//forward declarations
class Party;

class Server : public Employee
{
private:
	vector <Table *> tablesAssigned;			//vector of tables that are assigned to the server
	queue <Party *> partiesAssigned;			//queue of parties who this server is assisting

	//server stats
	double speed,
		precision,
		attitude;

	int mistakeChance = 0;						//chance that the server will make a mistake

public:
	//constructor
	Server(string _name, int exp, int dil, int cha);

	//deconstructor
	~Server();

	//factory method
	static Server* makeServer(string _name, int exp, int dil, int cha);

	//accessors
	double getSpeed();
	double getPrecision();
	double getAttitude();
	int getMistakeChance();
	vector <Table*> * getTablesAssigned();
	queue <Party*> * getPartiesAssigned();

	//mutators
	void setSpeed();
	void setPrecision();
	void setAttitude();
	void setMistakeChance();

	//other functions
	bool checkForMistake();
	void assignTable(Table * table);
	void cleanAssignedTable(int time);
	void defileTable(int tableNum);
	bool checkDirtyTables();
	void assignParty(Party * party);
	void seatParty(Party * party);
	bool assignNextParty();

	//server actions//
	void serverAction(string text, int relief, int time);
	bool actionCondition(string action, Party* party);
	void customerAction(string action, Customer* customer);
	void partyAction(string action, Party* party);
	void update(string text);
};