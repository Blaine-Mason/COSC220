#include "course.h"

Course::Course(){
  name = "NoName";
  dept = "NoDept";
  sem = "NoSemester";
  grade = 'F';
}
Course::Course(std::string n, std::string d, std::string s, char g){
  name = n;
  dept = d;
  sem = s;
  grade = g;
}
Course::Course(const Course& rhs){
  name = rhs.name;
  dept = rhs.dept;
  sem = rhs.sem;
  grade = rhs.grade;
}
std::string Course::getName() const {
  return name;
}
std::string Course::getDept() const {
  return dept;
}
std::string Course::getSem() const {
  return sem;
}
char Course::getGrade() const {
  return grade;
}
void Course::DisplayCourseInfo(){
  /*
  std::cout << "===================================" << std::endl;
  std::cout << "Course Name: " << this->getName() << std::endl;
  std::cout << "Department: " << this->getDept() << std::endl;
  std::cout << "Semester: " << this->getSem() << std::endl;
  std::cout << "Grade Received: " << this->getGrade() << std::endl;
  std::cout << "===================================" << std::endl;
  */
  std::cout << this->getName() << " " << this->getDept() << " " << this->getSem() << " " << this->getGrade() << std::endl;
}
