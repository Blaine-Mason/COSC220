#include "payroll.h"
#include "payrolllist.h"
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
	//testing the methods in PayRollList
	PayRollList list;
	PayRoll p = PayRoll("Blaine", 10, 30);
	//list.insert("maybeBlaine", 13, 5);
	list.insert(p);

	//Read in PayRoll from file
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
			//the node is then inserted
			list.insert(name, rate, hours);
		}
		payroll.close();
	}
	else
	{
		cout << "payroll.txt DNE or is not found." << endl;
	}
	//the list is printed
	//list.printPayChecks();

	PayRollList newList = list;

	newList.insert("TEST", 15, 30);
	cout << "New List: " << endl;
	newList.printPayChecks();
	cout << "List: " << endl;
	list.printPayChecks();
	cout << "Length of List: " << list.length() << endl;
	cout << "Length of newList: " << newList.length() << endl << endl;

	cout << "[] Overload Test: " << endl;
	if(list[4])
		list[4]->displayInfo();

	cout << "remove() Test: " << endl;
	list.remove(0);
	list.printPayChecks();
	cout << endl << endl;
	PayRoll testPRoll = PayRoll("iPhone", 19, 20);

	cout << "assign() Test: " << endl;
	list.assign(0, testPRoll);
	list.printPayChecks();

	cout << "insert(int, PayRoll) Test: " << endl << endl;

	PayRoll insertTest = PayRoll("Work", 17, 40);
	list.insert(0, insertTest);
	list.printPayChecks();
	return 0;
	}
