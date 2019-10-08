all: StudentDB

StudentDB: main.o course.o student.o studentdb.o
	g++ -std=c++11 -o StudentDB main.o course.o student.o studentdb.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

course.o: course.cpp
	g++ -std=c++11 -c course.cpp course.h

student.o: student.cpp
	g++ -std=c++11 -c student.cpp student.h

studentdb.o: studentdb.cpp
	g++ -std=c++11 -c studentdb.cpp studentdb.h

clean:
	rm *.o
