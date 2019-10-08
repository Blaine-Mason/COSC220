main: main.o payroll.o payrolllist.o
	g++ -o main main.o payroll.o payrolllist.o -std=c++11 
main.o: main.cpp payroll.h payrolllist.h
	g++ -c main.cpp -std=c++11
payroll.o: payroll.cpp payroll.h
	g++ -c payroll.cpp -std=c++11
payrolllist.o: payrolllist.cpp payrolllist.h
	g++ -c payrolllist.cpp -std=c++11
