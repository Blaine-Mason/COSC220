#ifndef PAYROLL_H
#define PAYROLL_H

#include <string>
#include <iostream>

using namespace std;

class PayRoll{
	public:
		PayRoll(); //default constructor
		PayRoll(string, double, double); //constructor with name and payrate and
							      //hours as parameters
		void setHours(double); //set the number of hours
		void setRate(double); //set the payrate
		void setName(string); //set the name
		double getPay() const; //returns pay
		double getRate() const; //returns payRate
		double getHours() const; //returns Hours
		string getName() const; //returns name
		void displayInfo(); //displays name and total pay

		PayRoll operator+(PayRoll p1, PayRoll p2);
		bool operator<(PayRoll p1, PayRoll p2);
		friend std::ostream& operator<<(std::ostream&, const PayRoll&);


	private:
		string name; //name
		double payRate; //rate of pay
		double hours; //hours worked
};

#endif
