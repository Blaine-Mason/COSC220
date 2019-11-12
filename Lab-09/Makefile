main: main.o payroll.o
	g++ -std=c++11 -o main main.o payroll.o
main.o: main.cpp mystack.h payroll.cpp payroll.h
	g++ -std=c++11 -c main.cpp payroll.cpp
payroll.o: payroll.cpp payroll.h
	g++ -std=c++11 -c payroll.cpp

clean:
	rm *.o
	rm *.gch
