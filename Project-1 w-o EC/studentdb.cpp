#include "studentdb.h"
/*
* Constructor
*/
StudentDB::StudentDB(){
  head = nullptr;
}
/*
* Copy Constructor
*/
StudentDB::StudentDB(const StudentDB& rhs){
  StudentNode* crsr = rhs.head;
  head = nullptr;
  while(crsr){
    //Traverse the list and add Students
    createStudent(crsr->s);
    crsr = crsr->next;
  }
}
/*
* Assignment operator= overload
*/
StudentDB& StudentDB::operator=(const StudentDB& rhs){
  //If it is a self assignment
  if(this == &rhs){
    std::cout << "They are the same." << std::endl;
  }else{
    StudentNode* crsr = this->head;
    //Get rid of any old students
    while(crsr){
      crsr = crsr->next;
      delete this->head;
      this->head = crsr;
    }
    head = nullptr;
    crsr = rhs.head;
    while(crsr){
      //Traverse the list and add the Students
      this->createStudent(crsr->s);
      crsr = crsr->next;
    }
  }
  return *this;
}
/*
* Destructor
*/
StudentDB::~StudentDB(){
  //if the list is empty
  if(head == nullptr){
    delete head;
    return;
  }else{
    //traverse the list and delete the students
    StudentNode* crsr = head;
    while(crsr){
      crsr = crsr->next;
      delete head;
      head = crsr;
    }
  }
}
/*
* Adds(creates) a Student to the list
*/
void StudentDB::createStudent(Student st){
  //Creates a cursor and a new node
  StudentNode* nNode = new StudentNode;
  StudentNode* crsr = head;
  nNode->s = st;
  nNode->next = nullptr;
  //If the list is empty assign new node to head
  if(crsr == nullptr){
    head = nNode;
    return;
  }else{
    //t=Traverse to the end
    while(crsr->next){
      crsr = crsr->next;
    }
    //Add the student
    crsr->next = nNode;
  }
}
/*
* Deletes(removes) a Student from the list
*/
void StudentDB::deleteStudent(Student st){
  //Establishes a crsr and gets the students name to search
  std::string name = st.getName();
  StudentNode* crsr = head;
  //If the list is empty
  if(crsr == nullptr){
    std::cout << "The List is Empty" << std::endl;
  }
  //If the student is in the beginning of the list
  if(crsr->s.getName() == name){
    //Delete the head and assign head to the next element
    crsr = head->next;
    delete head;
    head = crsr;
  }else{
    //Traverse the list until the name is found or you reach the end
    StudentNode* prev = head;
    while(crsr->s.getName() != name && crsr != nullptr){
      prev = crsr;
      crsr = crsr->next;
    }
    //If you reach the end
    if(crsr == nullptr){
      std::cout << "Student not Found in the List" << std::endl;
    }else{
      //Delete the student
      prev->next = crsr->next;
    }
  }
}
/*
* Updates a student by assigning the student in list to the student object
* passed in
*/
void StudentDB::updateStudent(Student st){
  //Establish a cursor
  StudentNode* crsr = head;
  std::string stName = st.getName();
  //If the student is at the beginning
  if(crsr->s.getName() == stName){
    crsr->s = st;
  }else{
    //Traverse the list until the name is found or you reach the end
    while(crsr->s.getName() != stName && crsr != nullptr){
      crsr = crsr->next;
    }
    //Perform assignment
    crsr->s = st;
  }
}
/*
* Returns a Student when given the name
*/
Student StudentDB::getStudent(std::string nm){
  //Establish a crsr
  StudentNode* crsr = head;
  //If the list is empty
  if(crsr == nullptr){
    Student s;
    std::cout << "The list is empty." << std::endl;
    s.setName("Not Found");
    return s;
  }
  //If the student is at the head
  if(crsr->s.getName() == nm)
  {
    return crsr->s;
  }else{
    //Traverses the list
    while(crsr != nullptr){
      //If the student is found return it
      if(crsr->s.getName() == nm){
        return crsr->s;
      }else{
        //Move forward
        crsr = crsr->next;
      }
    }
    //If the end was reached
    if(crsr == nullptr){
        //Return an empty student
        Student s;
        std::cout << "Student Not Found" << std::endl;
        s.setName("Not Found");
        return s;
    }
  }
}
/*
* Displays the database
*/
void StudentDB::displayDB() const{
  for(StudentNode* crsr = head; crsr; crsr = crsr->next){
    crsr->s.displayStudent();
  }
}
