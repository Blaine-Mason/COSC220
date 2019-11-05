all: quick

quick: quick.o
	g++ -std=c++11 -o quick quick.o
quick.o: quick.cpp
	g++ -std=c++11 -c quick.cpp
clean:
	rm *.o
