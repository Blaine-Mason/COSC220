#include "payroll.h"
#include "payrollstack.h"
#include <iostream>
#include <fstream>
#include <string> //string

/*
 * Blaine Mason
 * Lab-4
 * This program modifies Lab-3 by adding commands to edit different elements in the
 * list
 */

using namespace std;
int main(){
	PayRollStack pRollStack;

	ifstream payroll ("payroll.txt");
	if(payroll.is_open())
	{
		int size = 0;
		double rate, hours;
		string name;
		//size is read from the first line
		payroll >> size;
		for(int i = 0; i < size; i++){
			//info is assigned
			payroll >> name;
			payroll >> hours;
			payroll >> rate;
			PayRoll p(name, rate, hours);
			//p.displayInfo();
			//the node is then inserted
			pRollStack.push(p);
		}
		payroll.close();
	}
	else
	{
		cout << "payroll.txt DNE or is not found." << endl;
	}
	for(int i = 0; i < 7; i++){
		PayRoll test;
		pRollStack.pop(test);
		//test = pRollStack.pop();
		test.displayInfo();
	}

	return 0;
	}
