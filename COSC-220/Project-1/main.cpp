#include <iostream>
#include <string>
#include "course.h"
#include "student.h"
#include "studentdb.h"

int main(){
  Student s = Student("Blaine", "09-16-00", "Computer Science");
  Student s1 = Student("Ben", "06-10-00", "BioChem");
  Student s2 = Student("Ben", "10-19-00", "BioChem");
  s.displayStudent();
  s1.displayStudent();
  Course c1 = Course("COSC220", "Computer Science", "Fall 2019", 'A');
  Course c2 = Course("COSC250", "Computer Science", "Fall 2019", 'A');
  s.addCourse(c1);
  s.addCourse(c2);
  s2.addCourse(c2);
  s.displayStudent();
  s1.displayStudent();

  StudentDB theStudents;

  theStudents.createStudent(s);

  std::cout << "HERE" << std::endl;

  theStudents.createStudent(s2);

  theStudents.displayDB();
  std::cout << "DELETE TEST" << std::endl << std::endl;
  theStudents.deleteStudent(s1);
  theStudents.displayDB();
  std::cout << "UPDATE TEST" << std::endl << std::endl;
  theStudents.updateStudent(s2);
  theStudents.displayDB();



  return 0;
}
