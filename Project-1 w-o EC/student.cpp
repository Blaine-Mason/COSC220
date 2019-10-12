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
  name = rhs.name;
  dob = rhs.dob;
  major = rhs.major;
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
    //rhs.displayStudent();
    name = rhs.name;
    major = rhs.major;
    dob = rhs.dob;
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
  }
  return *this;
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
void Student::setName(std::string s){
  name = s;
}
void Student::setMajor(std::string s){
  major = s;
}
void Student::setDob(std::string s){
  dob = s;
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
  int i = 0;
  for(CourseNode* crsr = courseHead; crsr; crsr = crsr->next){
    std::cout << i << ": ";
    crsr->c.DisplayCourseInfo();
    i++;
  }
}
int Student::totalCourses() const{
  int total = 0;
  for(CourseNode* crsr = courseHead; crsr; crsr = crsr->next){
    total++;
  }
  return total;
}
void Student::removeCourse(Course c){
  CourseNode* crsr = courseHead;
  std::string name = c.getName();
  if(crsr == nullptr){
    std::cout << "No Courses Exist" << std::endl;
  }
  if(crsr->c.getName() == name){
    crsr = courseHead->next;
    delete courseHead;
    courseHead = crsr;
  }else{
    CourseNode* prev = courseHead;
    while(crsr->c.getName() != name && crsr != nullptr){
      prev = crsr;
      crsr = crsr->next;
    }
    if(crsr == nullptr){
      std::cout << "Course not Found in the List" << std::endl;
    }else{
      prev->next = crsr->next;
    }
  }
}
Course Student::getCourse(int n){
  CourseNode* crsr = courseHead;
  int len = this->totalCourses();
  if(len < n){
    Course c;
    std::cout << "Index out of Bounds!" << std::endl;
    return c;
  }else{
    for(int i = 0; i < n; i++){
      crsr = crsr->next;
    }
    return crsr->c;
  }
}
void Student::displayStudent() const{
  /*
  std::cout << "*******************************" << std::endl;
  std::cout << "Name: " << this->getName() << std::endl;
  std::cout << "Date of Birth: " << this->getDoB() << std::endl;
  std::cout << "Major: " << this->getMajor() <<  std::endl;
  std::cout << "Courses Taken:" << std::endl;
  this->printCourses();
  std::cout << "*******************************" << std::endl;
  */
  std::cout << this->getName() << " " << this->getDoB() << " " << this->getMajor() << " " << std::endl;
  this->printCourses();

}
