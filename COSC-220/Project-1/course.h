#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course{
  private:
    std::string name, dept, sem;
    char grade;
  public:
    Course();
    Course(std::string, std::string, std::string, char);
    Course(const Course& rhs);
    std::string getName() const;
    std::string getDept() const;
    std::string getSem() const;
    char getGrade() const;
    void DisplayCourseInfo();
};
#endif
