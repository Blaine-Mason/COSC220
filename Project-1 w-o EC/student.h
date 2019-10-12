#ifndef STUDENT_H
#define STUDENT_H
#include "course.h"

#include <string>
#include <iostream>


class Student{
  private:
    struct CourseNode{
      Course c;
      CourseNode* next;
    };
    CourseNode* courseHead;


  public:
    Student();
    Student(std::string, std::string, std::string);
    Student(const Student& rhs);
    Student& operator=(const Student& rhs);
    ~Student();
    std::string name, dob, major;
    std::string getName() const;
    std::string getDoB() const;
    std::string getMajor() const;
    void setName(std::string);
    void setMajor(std::string);
    void setDob(std::string);
    void addCourse(Course c);
    int totalCourses() const;
    void removeCourse(Course);
    Course getCourse(int);
    void printCourses() const;
    void displayStudent() const;
};
#endif
