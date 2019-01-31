#pragma once
#include <vector>
#include "Customer.h"
#include "Party.h"
using namespace std;

class Customer;							//forward declarations
class Party;

class Table
{
private:
	Party * seatedParty = NULL;
	vector <Customer*> * seatedCustomers;

	//party stats//

	int tableNum,
		seats = 4;						//plan on eventually changing the number of seats from 4 to greater numbers

	//table states//

	bool occupied = false,
		clean = true;

public:
	//constructors
	Table(int _tableNum);

	//deconstructors
	~Table();

	//factory method
	static Table* makeTable(int _tableNum);

	//accessors
	int getTableNum();
	bool getCleanVal();
	bool getOccupiedVal();
	Party * getSeatedParty();

	//mutators
	void setTableNum(int n);
	void setClean(bool b);
	void setOccupied(bool b);

	//other functions
	void addParty(Party * _party);
	void removeParty();
	vector <Customer*> * getSeatedCustomers();
	void addSeatedCustomer(Customer * customer);
};

