all: run

run: main.o
	g++ -std=c++11 -o run main.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
clean:
	rm *.o