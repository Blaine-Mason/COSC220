all: lab

lab: sorting.o
	g++ -std=c++11 -o lab sorting.o
sorting.o: sorting.cpp
	g++ -std=c++11 -c sorting.cpp
clean:
	rm *.o
