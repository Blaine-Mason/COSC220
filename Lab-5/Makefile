main: main.o payroll.o payrollstack.o
	g++ -o main main.o payroll.o payrollstack.o -std=c++11
main.o: main.cpp payroll.h payrollstack.h
	g++ -c main.cpp -std=c++11
payroll.o: payroll.cpp payroll.h
	g++ -c payroll.cpp -std=c++11
payrollstack.o: payrollstack.cpp payrollstack.h
	g++ -c payrollstack.cpp -std=c++11
clean:
	rm -f *.o main
