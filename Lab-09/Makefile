all: temp

temp: main.o
	g++ -std=c++11 -o main main.o
main.o: main.cpp mystack.h
	g++ -std=c++11 -c main.cpp mystack.h
clean:
	rm *.o
