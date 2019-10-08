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
