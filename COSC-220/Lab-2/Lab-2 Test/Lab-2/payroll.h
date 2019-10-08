#ifndef PAYROLL_H
#define PAYROLL_H

#include <string>
#include <iostream>

using namespace std;

class PayRoll{
	public:
		PayRoll(); //default constructor
		PayRoll(string str, double rate); //constructor with name and payrate as parameters
		void setHours(double hrs); //set the number of hours
		double getPay() const; //returns pay
		string getName() const; //returns name
		void displayInfo(); //displays name and total pay
	private:
		string name; //name
		double payRate; //rate of pay
		double hours; //hours worked
};

#endif
