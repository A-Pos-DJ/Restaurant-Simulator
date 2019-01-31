#include "Table.h"

//constructors
Table::Table(int _tableNum)
{
	if (seatedCustomers == NULL)
		seatedCustomers = new vector <Customer*>;
	if (seatedParty == NULL)
		seatedParty = new Party();
	setTableNum(_tableNum);
}

//deconstructors
Table::~Table()
{

}

//factory method
Table* Table::makeTable(int _tableNum)
{
	return new Table(_tableNum);
}

//accessors
int Table::getTableNum()
{
	return tableNum;
}

bool Table::getCleanVal()
{
	return clean;
}

bool Table::getOccupiedVal()
{
	return occupied;
}

Party * Table::getSeatedParty()
{
	return seatedParty;
}


//mutators
void Table::setTableNum(int n)
{
	tableNum = n;
}

void Table::setClean(bool b)
{
	clean = b;
}

void Table::setOccupied(bool b)
{
	occupied = b;
}

//other functions
void Table::addParty(Party * _party)
{
	seatedParty = _party;											//set the seated party to the party pointer
	for (int idx = 0; idx <											//loop through each customer in the seated party
		static_cast<int>(seatedParty->getCustomers()->size()); idx++)	
	{
		addSeatedCustomer(seatedParty->getCustomers()->at(idx));	//add each customer pointer to the seated party vector
	}
}

void Table::removeParty()
{
	seatedParty = NULL;												//set the seated party to the party pointer
	seatedCustomers->clear();										//clear everything from the seated customer vector
}

vector <Customer*> * Table::getSeatedCustomers()
{
	return seatedCustomers;											//get the seated customers vector
}

void Table::addSeatedCustomer(Customer * customer)
{
	seatedCustomers->push_back(customer);							//add the customer pointer to the vector of seatedcustomers
}