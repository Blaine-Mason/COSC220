#include "studentdb.h"

StudentDB::StudentDB(){
  head = nullptr;
}
StudentDB::~StudentDB(){
  if(head == nullptr){
    return;
  }else{
    StudentNode* crsr = head;
    while(crsr){
      crsr = crsr->next;
      delete head;
      head = crsr;
    }
  }
}
void StudentDB::createStudent(Student st){

  StudentNode* nNode = new StudentNode;
  StudentNode* crsr = head;
  nNode->s = st;
  nNode->next = nullptr;
  if(crsr == nullptr){
    head = nNode;
    return;
  }else{
    while(crsr->next){
      crsr = crsr->next;
    }
    crsr->next = nNode;
  }
}
void StudentDB::deleteStudent(Student st){
  std::string name = st.getName();
  StudentNode* crsr = head;


  if(crsr == nullptr){
    std::cout << "The List is Empty" << std::endl;
  }
  if(crsr->s.getName() == name){
    crsr = head->next;
    delete head;
    head = crsr;
  }else{
    StudentNode* prev = head;
    while(crsr->s.getName() != name && crsr != nullptr){
      prev = crsr;
      crsr = crsr->next;
    }
    if(crsr == nullptr){
      std::cout << "Student not Found in the List" << std::endl;
    }else{
      prev->next = crsr->next;
    }
  }
}
void StudentDB::updateStudent(Student st){
  StudentNode* crsr = head;

  std::string stName = st.getName();

  if(crsr->s.getName() == stName){
    crsr->s = st;
  }else{
    while(crsr->s.getName() != stName && crsr != nullptr){
      crsr = crsr->next;
    }
    crsr->s = st;
  }
}
Student StudentDB::getStudent(std::string nm){
  StudentNode* crsr = head;
  if(crsr == nullptr){
    Student s;
    std::cout << "The list is empty." << std::endl;
    return s;
  }
  if(crsr->s.getName() == nm)
  {
    return crsr->s;
  }else{
    while( crsr->s.getName() != nm  && crsr != nullptr){
      crsr = crsr->next;
    }
    return crsr->s;
  }
}
void StudentDB::displayDB() const{
  int i = 1;
  for(StudentNode* crsr = head; crsr; crsr = crsr->next){
    std::cout << i << ".) ";
    crsr->s.displayStudent();
    i++;
  }
}
