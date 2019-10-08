#include "student.h"
#include "course.h"

Student::Student(){
  courseHead = nullptr;
  name = "NoName";
  dob = "NoDoB";
  major = "NoMajor";
}
Student::Student(std::string n, std::string db, std::string m){
  name = n;
  dob = db;
  major = m;
  courseHead = nullptr;
}///*
Student::Student(const Student& rhs){
  /*
  name = rhs.name;
  dob = rhs.dob;
  major = rhs.major;
  */
  CourseNode* crsr = rhs.courseHead;
  courseHead = nullptr;
  while(crsr){
    addCourse(crsr->c);
    crsr = crsr->next;
  }
}///*
Student& Student::operator=(const Student& rhs){
  if(this == &rhs){
    std::cout << "They are the same." << std::endl;
  }else{
    name = rhs.name;
    dob = rhs.dob;
    major = rhs.major;
    CourseNode* crsr = this->courseHead;
    while(crsr){
      crsr = crsr->next;
      delete this->courseHead;
      this->courseHead = crsr;
    }
    courseHead = nullptr;
    crsr = rhs.courseHead;
    while(crsr){
      this->addCourse(crsr->c);
      crsr = crsr->next;
    }
    return *this;
  }
}//*/
Student::~Student(){
  if(courseHead == nullptr){
    return;
  }else{
    CourseNode* crsr = courseHead;
    while(crsr){
      crsr = crsr->next;
      delete courseHead;
      courseHead = crsr;
    }
  }
}
std::string Student::getName() const{
  return name;
}
std::string Student::getDoB() const{
  return dob;
}
std::string Student::getMajor() const{
  return major;
}
void Student::addCourse(Course newCourse){
  CourseNode* nNode = new CourseNode;
  CourseNode* crsr = courseHead;
  //this causes problems
  nNode->c = newCourse;
  nNode->next = nullptr;

  if(crsr == nullptr){
    courseHead = nNode;
    return;
  }else{
    while(crsr->next){
      crsr = crsr->next;
    }
    crsr->next = nNode;
  }
}
void Student::printCourses() const{
  for(CourseNode* crsr = courseHead; crsr; crsr = crsr->next){
    crsr->c.DisplayCourseInfo();
  }
}
void Student::removeCourse(Course c){

}
void Student::displayStudent() const{
  std::cout << "*******************************" << std::endl;
  std::cout << "Name: " << this->getName() << std::endl;
  std::cout << "Date of Birth: " << this->getDoB() << std::endl;
  std::cout << "Major: " << this->getMajor() <<  std::endl;
  std::cout << "Courses Taken:" << std::endl;
  this->printCourses();
  std::cout << "*******************************" << std::endl;

}
