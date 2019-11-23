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
	double pay() const;
	void print() const;
};

class Hourly: public Employee{
public:
	double hoursWorked;
	Hourly(std::string empName, double emRate):Employee(empName, emRate){ hoursWorked = 0; }
	void addHours(double h){
		hoursWorked = h;
	}
	double pay(){
		double tPay = payRate * hoursWorked;
		hoursWorked = 0;
		return tPay;
	}
	void print(){

		std::cout << "Total Hours: " << hoursWorked << std::endl;
	}
};

class Executive: public Employee{
private:
	double bonusPay;
public:
	Executive(std::string empName, double emRate):Employee(empName, emRate){}
	void setBonusPay(double b){
		bonusPay = b;
	}
	double pay(){
		double childP = pay();
		childP += bonusPay;
		bonusPay = 0;
		return childP;
	}
	void print(){
		std::cout << "Total Pay" << pay() << std::endl;
	}

};


int main(){

	Hourly Blaine("Blaine", 10);
	Blaine.addHours(10.5);
	double pay = Blaine.pay();
	std::cout << "Pay: " << pay << std::endl;
	Blaine.print();


	return 0;
}