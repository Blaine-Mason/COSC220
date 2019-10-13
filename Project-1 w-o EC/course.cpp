#include "course.h"

/*
* Default Constructor
*/
//Creates an empty Course
Course::Course(){
  name = "NoName";
  dept = "NoDept";
  sem = "NoSemester";
  grade = 'F';
}
/*
* Constructor with parameters to se the name, dept, sem, and grade
*/
Course::Course(std::string n, std::string d, std::string s, char g){
  name = n;
  dept = d;
  sem = s;
  grade = g;
}
/*
* Copy constructor for course to handle a std:: error
*/
Course::Course(const Course& rhs){
  name = rhs.name;
  dept = rhs.dept;
  sem = rhs.sem;
  grade = rhs.grade;
}
/*
* Returns the name of the Course
*/
std::string Course::getName() const {
  return name;
}
/*
* Returns the dept of the Course
*/
std::string Course::getDept() const {
  return dept;
}
/*
* Returns the sem of the Course
*/
std::string Course::getSem() const {
  return sem;
}
/*
* Returns the grade of the Course
*/
char Course::getGrade() const {
  return grade;
}
/*
* Displays the information about the course
*/
void Course::DisplayCourseInfo(){
  std::cout << "===================================" << std::endl;
  std::cout << "Course Name: " << this->getName();
  std::cout << " Department: " << this->getDept();
  std::cout << " Semester: " << this->getSem();
  std::cout << " Grade Received: " << this->getGrade() << std::endl;
  std::cout << "===================================" << std::endl;

  //std::cout << this->getName() << " " << this->getDept() << " " << this->getSem() << " " << this->getGrade() << std::endl;
}
