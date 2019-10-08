#ifndef STUDENTDB_H
#define STUDENTDB_H

#include "course.h"
#include "student.h"
#include <iostream>

class StudentDB{
  private:
    struct StudentNode{
      Student s;
      StudentNode* next;
    };
    StudentNode* head;
  public:
    StudentDB();
    ~StudentDB();
    void createStudent(Student);
    void deleteStudent(Student);
    void updateStudent(Student);
    void displayDB() const;
};
#endif
