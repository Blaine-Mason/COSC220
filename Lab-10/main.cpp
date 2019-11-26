#include <iostream>

class Employee{
protected:
	double payRate;
	std::string name;
public:
	Employee(std::string empName, double emRate){
		name = empName; 
		payRate = emRate;
	}
	virtual double pay(){
		return payRate;
	}
	virtual void print(){
		std::cout << name << std::endl;
		std::cout << "PayRate: " << payRate << std::endl;
	}
};

class Hourly: public Employee{
public:
	double hoursWorked;
	Hourly(std::string empName, double emRate):Employee(empName, emRate){ hoursWorked = 0; }
	void addHours(double h){
		hoursWorked = h;
	}
	double pay() {
		double tPay = Employee::pay() * hoursWorked;
		hoursWorked = 0;
		return tPay;
	}
	void print() {
		Employee::print();
		std::cout << "Total Hours: " << hoursWorked << std::endl;
	}
};

class Executive: public Employee{
private:
	double bonusPay;
public:
	Executive(std::string empName, double emRate):Employee(empName, emRate){}
	void setBonusPay(double b) {
		bonusPay = b;
	}
	double pay() {
		double childP = Employee::pay();
		childP += bonusPay;
		bonusPay = 0;
		return childP;
	}
	void print() {
		Employee::print();
		std::cout << "Total Pay: " << pay() << std::endl;
	}

};


int main(){
	Employee a("Alpha", 15.50);
	Hourly h("Hourly", 17.20);
	Executive ex("CEO", 12.50);

	a.print();
	std::cout << std::endl;
	h.addHours(40);
	h.print();
	std::cout << std::endl;
	ex.setBonusPay(20);
	ex.print();
	std::cout << std::endl;

	Employee e1("Dan", 10);
	Employee e2("Chad", 14);
	Hourly h1("Brad", 34.4);
	h1.addHours(10);
	Hourly h2("Ryan", 10.45);
	h2.addHours(13);
	Executive ex1("Luke", 16.76);
	ex1.setBonusPay(50);
	Executive ex2("John", 10.45);
	ex2.setBonusPay(20);

	Employee* arr[9];
	arr[0] = &a;
	arr[1] = &h;
	arr[2] = &ex;
	arr[3] = &e1;
	arr[4] = &e2;
	arr[5] = &h1;
	arr[6] = &h2;
	arr[7] = &ex1;
	arr[8] = &ex2;

	std::cout << "Polymorphism Test: " << std::endl;
	for(int i = 0; i < 9; i++){
		arr[i]->print();
		std::cout << std::endl;
	}

	return 0;
}