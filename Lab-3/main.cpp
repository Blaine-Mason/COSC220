#include "payroll.h"
#include "payrolllist.h"
#include <iostream>
#include <string> //string

/*
 * Blaine Mason
 * Lab-3
 * This program uses a payroll class to display the memory use of regular
 * arrays vs arrays of pointers
 */

int main(){

	PayRollList list;
	PayRoll p = PayRoll("Blaine", 60, 30);
	list.insert("notBlaine", 10, 5);
	list.insert(p);
	list.printPayChecks();
	return 0;
}
