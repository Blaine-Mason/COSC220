all: temp

temp: main.o
	g++ -std=c++11 -o main main.o
main:main.cpp
	g++ -std=c++11 -c main.cpp
clean:
	rm *.o
