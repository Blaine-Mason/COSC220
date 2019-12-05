all: Hanoi

Hanoi: HanoiStack.o main.o
	g++ -std=c++11 -o Hanoi HanoiStack.o main.o

HanoiStack.o: HanoiStack.cpp
	g++ -std=c++11 -c HanoiStack.cpp HanoiStack.h

main.o: main.cpp
	g++ -std=c++11 -c main.cpp
SUList.o:	SUList.h SUList.cpp
	g++ -std=c++11 -c SUList.h SUList.cpp
SUStack.o: SUStack.h SUStack.h
	g++ -std=c++11 -c SUStack.h SUStack.cpp
clean:
	rm *.o
