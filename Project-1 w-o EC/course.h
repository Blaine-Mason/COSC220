#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course{
  private:
    std::string name, dept, sem, grade;
  public:
    Course();
    Course(std::string, std::string, std::string, std::string);
    Course(const Course& rhs);
    std::string getName() const;
    std::string getDept() const;
    std::string getSem() const;
    std::string getGrade() const;
    void DisplayCourseInfo();
};
#endif
