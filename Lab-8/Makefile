all: quick

quick: quick.o
	g++ -std=c++11 -o quick quick.cpp
main.o: quick.cpp
	g++ -std=c++11 -c quick.cpp
clean:
	rm *.o
