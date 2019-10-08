#include "payroll.h"

/*
 *Assigns name and payRate default values
 */
PayRoll::PayRoll()
{
	name = "no name";
	payRate = 0.0;
}
/*
 *Assigns name and payRate their associated parameters
 */
PayRoll::PayRoll(string str, double rate)
{
	name = str;
	payRate = rate;
}
/*
 * Set the hours for this employee
 */
void PayRoll::setHours(double hrs)
{
	hours = hrs;
}
/*
 * Display info about the employee
 */
void PayRoll::displayInfo()
{
	cout << "Employee: " << name << endl;
	cout << "Total Pay: " << getPay() << "$" <<  endl;
}
/*
 * Calculate and return the total pay for
 * this employee
 */
double PayRoll::getPay() const
{
	return payRate * hours;	
}
/*
 * Return the name of the employee
 */
string PayRoll::getName() const
{
	return name;
}

