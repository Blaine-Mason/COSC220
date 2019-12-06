GCC=g++
FLAGS=-std=c++11 -Wall

all: main

main: travelstate.o idlestate.o main.o combatstate.o player.o monster.o 
	$(GCC) $(FLAGS) -o main travelstate.o idlestate.o main.o combatstate.o player.o monster.o

main.o: main.cpp
	$(GCC) $(FLAGS) -c main.cpp -o main.o

travelstate.o: travelstate.cpp gamestate.h travelstate.h
	$(GCC) $(FLAGS) -c travelstate.cpp -o travelstate.o

idlestate.o: idlestate.cpp gamestate.h idlestate.h
	$(GCC) $(FLAGS) -c idlestate.cpp -o idlestate.o

combatstate.o: combatstate.cpp gamestate.h combatstate.h
	$(GCC) $(FLAGS) -c combatstate.cpp -o combatstate.o

player.o: player.cpp livingentity.h player.h
	$(GCC) $(FLAGS) -c player.cpp -o player.o

monster.o: monster.cpp livingentity.h monster.h
	$(GCC) $(FLAGS) -c monster.cpp -o monster.o

clean:
	rm *.o main
