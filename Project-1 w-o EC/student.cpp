#include "student.h"
#include "course.h"

/*
* Default Constructor
*/
Student::Student(){
  courseHead = nullptr;
  name = "NoName";
  dob = "NoDoB";
  major = "NoMajor";
}
/*
* Student Constructor that takes parameters of the name, dob, and major
*/
Student::Student(std::string n, std::string db, std::string m){
  name = n;
  dob = db;
  major = m;
  courseHead = nullptr;
}
/*
* Copy Constructor
*/
Student::Student(const Student& rhs){
  //asign the new student the rhs info
  name = rhs.name;
  dob = rhs.dob;
  major = rhs.major;
  CourseNode* crsr = rhs.courseHead;
  courseHead = nullptr;
  //Give the new Student all the rhs courses
  while(crsr){
    addCourse(crsr->c);
    crsr = crsr->next;
  }
}
/*
* Assignment operator= overload
*/
Student& Student::operator=(const Student& rhs){
  //If it is a self assignment
  if(this == &rhs){
    std::cout << "They are the same." << std::endl;
  }else{
    //Assign the left side the right sides information
    name = rhs.name;
    major = rhs.major;
    dob = rhs.dob;
    CourseNode* crsr = this->courseHead;
    while(crsr){
      //Get rid of any old courses in the left hand side
      crsr = crsr->next;
      delete this->courseHead;
      this->courseHead = crsr;
    }
    courseHead = nullptr;
    crsr = rhs.courseHead;
    while(crsr){
      //Add the rhs courses to the left hand side.
      this->addCourse(crsr->c);
      crsr = crsr->next;
    }
  }
  return *this;
}
/*
* Destructor
*/
Student::~Student(){
  //if the list is empty
  if(courseHead == nullptr){
    delete courseHead;
  }else{
    //travese the list and delete the courses
    CourseNode* crsr = courseHead;
    while(crsr){
      crsr = crsr->next;
      delete courseHead;
      courseHead = crsr;
    }
  }
}
/*
* Returns the name of the Student
*/
std::string Student::getName() const{
  return name;
}
/*
* Returns the DoB of the Student
*/
std::string Student::getDoB() const{
  return dob;
}
/*
* Returns the Major of the Student
*/
std::string Student::getMajor() const{
  return major;
}
/*
* Sets the Name of the Student
*/
void Student::setName(std::string s){
  name = s;
}
/*
* Sets the Major of the Student
*/
void Student::setMajor(std::string s){
  major = s;
}
/*
* Sets the DoB of the Student
*/
void Student::setDob(std::string s){
  dob = s;
}
/*
* Adds a course to the student
*/
void Student::addCourse(Course newCourse){
  //Creates and new node for Course and assigns a cursor
  CourseNode* nNode = new CourseNode;
  CourseNode* crsr = courseHead;
  nNode->c = newCourse;
  nNode->next = nullptr;

  //if the list is empty
  if(crsr == nullptr){
    //The nNode is set to the head
    courseHead = nNode;
    return;
  }else{
    //traverse to the end of the list
    while(crsr->next){
      crsr = crsr->next;
    }
    //place new node at the end
    crsr->next = nNode;
  }
}
/*
* Displays the Courses of the student
*/
void Student::printCourses() const{
  int i = 0;
  for(CourseNode* crsr = courseHead; crsr; crsr = crsr->next){
    std::cout << i << ": " << std::endl;
    crsr->c.DisplayCourseInfo();
    i++;
  }
}
/*
* Returns the amount of Courses the student has
*/
int Student::totalCourses() const{
  int total = 0;
  for(CourseNode* crsr = courseHead; crsr; crsr = crsr->next){
    total++;
  }
  return total;
}
/*
* Removes a course by passing in a course object
*/
void Student::removeCourse(Course c){
  //Establishes a crsr and sets the name to the course name
  CourseNode* crsr = courseHead;
  std::string name = c.getName();
  //if the list is empty
  if(crsr == nullptr){
    std::cout << "No Courses Exist" << std::endl;
  }
  //If the course is at the head of the list
  if(crsr->c.getName() == name){
    //The course to be removed is located at the head
    crsr = courseHead->next;
    delete courseHead;
    courseHead = crsr;
  }else{
    //A prev is established and traverses the list for the course
    CourseNode* prev = courseHead;
    while(crsr->c.getName() != name && crsr != nullptr){
      prev = crsr;
      crsr = crsr->next;
    }
    //If the course is found remove it
    if(crsr){
            prev->next = crsr->next;
    }else{
      std::cout << "Course not Found in the List" << std::endl;
    }
  }
}
/*
* Returns a Course for an index given
*/
Course Student::getCourse(int n){
  //A crsr is established
  CourseNode* crsr = courseHead;
  int len = this->totalCourses();
  //If the index is larger than the length of the list
  if(len <= n || n < 0){
    Course c;
    std::cout << "Index out of Bounds!" << std::endl;
    return c;
  }else{
    //traverse the list
    for(int i = 0; i < n; i++){
      crsr = crsr->next;
    }
    //Return the Course
    return crsr->c;
  }
}
/*
* Displays the student
*/
void Student::displayStudent() const{
  std::cout << "*******************************" << std::endl;
  std::cout << "Name: " << this->getName() << std::endl;
  std::cout << "Date of Birth: " << this->getDoB() << std::endl;
  std::cout << "Major: " << this->getMajor() <<  std::endl;
  std::cout << "Courses Taken:" << std::endl;
  this->printCourses();
  std::cout << "*******************************" << std::endl;
}
