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
PayRoll::PayRoll(string str, double rate, double hrs)
{
	name = str;
	payRate = rate;
	hours = hrs;
}
/*
 * Set the hours for this employee
 */
void PayRoll::setHours(double hrs)
{
	hours = hrs;
}
/*
 * Set the payRate for this employee
 */
void PayRoll::setRate(double r8)
{
	payRate = r8;
}
/*
 * Set the name for this employee
 */
void PayRoll::setName(string n)
{
	name = n;
}
/*
 * Display info about the employee
 */
void PayRoll::displayInfo()
{
	cout << "=============================" << endl;
	cout << "Employee: " << name << endl;
	cout << "PayRate: " << getRate() << endl;
	cout << "Total Pay: " << getPay() << "$" <<  endl;
	cout << "=============================" << endl;
	cout << endl;
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
 * Gets the payRate of the employee
 */
double PayRoll::getRate() const
{
	return payRate;
}
/*
 * Gets the hours worked of the employee
 */
double PayRoll::getHours() const
{
	return hours;
}
/*
 * Gets the Name of the employee
 */
string PayRoll::getName() const
{
	return name;
}
