#include "payrolllist.h"


//constructor
PayRollList::PayRollList()
{
	head = nullptr;
}
//destructor
PayRollList::~PayRollList()
{
	delete head;
}
// Takes name, rate, and hours worked as
// parameters for a new ListNode.
// The new node may sorted by payrate
void PayRollList::insert(string name, double rate, double hours)
{
	ListNode* nNode = new ListNode;
	nNode->p  = PayRoll(name, rate, hours);
	nNode->next = nullptr;

	if(!head){
		head = nNode;
		return;
	}

	ListNode* crsr = head;
	
	while(crsr->next){
		crsr = crsr->next;
	}
	crsr->next = nNode;
}

// Overide, accept a PayRoll object directly.
// To make life easy, this should either call or
// be called from insert(string, double, double)
// rather than repeat the logic!
void PayRollList::insert(PayRoll nPayRoll)
{
	insert(nPayRoll.getName(), nPayRoll.getRate(), nPayRoll.getHours());
}
// Prints each employee name and total pay to the terminal
// or, optionally, to a text file(loosely simulating the user 
// pressing the "print" button in a program)
void PayRollList::printPayChecks()
{
	ListNode* crsr = head;
	while(crsr){
		crsr->p.displayInfo();
		crsr = crsr->next;
	}
}

