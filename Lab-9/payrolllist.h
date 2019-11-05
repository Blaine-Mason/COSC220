#ifndef PAYROLLLIST_H
#define PAYROLLLIST_H

#include "payroll.h"


class PayRollList{
	private:
		struct ListNode {
			PayRoll p;
			ListNode* next;
		};

		ListNode* head;
	public:
		PayRollList(); //ctor
		~PayRollList(); //destructor

		// copy constructor, passes in another list by reference
		// and copy each element into the new list
		PayRollList(PayRollList&);

		//returns number of elements in the lists
		int length();

		//operator = overload
		PayRollList operator=(const PayRollList& rhs);

		bool operator<(const PayRollList p1, const PayRollList p2);

		friend std::ostream& operator<<(std::ostream&, const PayRollList&);


		// An overloaded index operator
		// Takes an integer index and (if it exissts)
		// returns a *reference to* the payroll inside it
		// () returns nullptr if the objest is not there
		PayRoll* operator[](int);

		// Remove the list item at the index given
		void remove(int);

		// Copy a PayRoll object into a specific position
		void assign(int, PayRoll);

		// Inserts the PayRoll into the list so that it is
		// in the specified position
		void insert(int, PayRoll);

		// Takes name, rate, and hours worked as
		// parameters for a new ListNode.
		// The new node may be sorted by payrate
		void insert(string, double, double);

		// Ovveride, accept a PayRoll object directly.
		// To make life easy, this should either call or
		// be called from insert(string, double, double)
		// rather than repeat the logic!
		void insert(PayRoll);

		// Prints each employee name and total pay to the terminal
		// or, optionally, to a text file(loosely simulating the user
		// pressing the "print" button in a program)
		void printPayChecks();
};
#endif
