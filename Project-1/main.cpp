#include <iostream>
#include <string>
#include "course.h"
#include "student.h"
#include "studentdb.h"

int main(){
  std::cout << "Welcome to Student Database" << std::endl;
  char choice;
  StudentDB students;
  Student s;
  do{
    std::cout << "--------------------" << std::endl << "|C.) Create Student|" << std::endl <<  "--------------------" << std::endl;
    std::cout << "--------------------" << std::endl << "|U.) Update Student|" << std::endl <<  "--------------------" << std::endl;
    std::cout << "--------------------" << std::endl << "|D.) Delete Student|" << std::endl <<  "--------------------" << std::endl;
    std::cout << "--------------------" << std::endl << "|E.) Exit          |" << std::endl <<  "--------------------" << std::endl;
    std::cin >> choice;
    std::cin.ignore();
    std::string temp;
    char cTemp;
    int iTemp, selection, courseIndex;
    std::string name, dept, sem;
    char grade;
    Course c;
    Student updatedSt;
    switch(choice){
      case 'C':
        s = Student();
        std::cout << "Name: ";
        std::getline(std::cin, temp);
        s.setName(temp);
        std::cout << "Date of Birth: ";
        std::getline(std::cin, temp);
        s.setDob(temp);
        std::cout << "Major: ";
        std::getline(std::cin, temp);
        s.setMajor(temp);
        do{
          std::cout << "Add a course?(y/n): ";
          std::cin >> cTemp;
          std::cin.ignore();

          if(cTemp == 'y'){
            std::cout << "Name: ";
            std::getline(std::cin, name);
            //std::cin >> name;
            std::cout << "Department: ";
            std::getline(std::cin, dept);
            //std::cin >> dept;
            std::cout << "Semester: ";
            std::getline(std::cin, sem);
            //std::cin >> sem;
            std::cout << "Grade: ";
            std::cin >> grade;
            c = Course(name, dept, sem, grade);
            s.addCourse(c);
          }
        }while(cTemp != 'n');
        students.createStudent(s);
        students.displayDB();
        break;
      case 'U':
        std::cout << "Enter the name for the Student you would like to edit: " << std::endl;
        std::getline(std::cin, name);
        updatedSt = students.getStudent(name);
        do{
          std::cout << "Select what you would like to edit(-1 to finish): " << std::endl;
          std::cout << "1.)Date of Birth: " << updatedSt.getDoB() << std::endl;
          std::cout << "2.)Major: " << updatedSt.getMajor() << std::endl;
          std::cout << "3.)Courses: " << std::endl;
          updatedSt.printCourses();
          std::cin >> selection;
          std::cin.ignore();
          switch(selection){
            case 1:
              std::cout << "Enter the updated Date of Birth: ";
              std::getline(std::cin, temp);
              updatedSt.setDob(temp);
              std::cout << "DoB Updated!" << std::endl;
              break;
            case 2:
              std::cout << "Enter the updated Major: ";
              std::getline(std::cin, temp);
              updatedSt.setMajor(temp);
              std::cout << "Major Updated!" << std::endl;
              break;
            case 3:
              std::cout << "Would you like to (1)add or (2)remove a course: " << std::endl;
              std::cin >> iTemp;
              std::cin.ignore();
              switch(iTemp){
                case 1:
                  std::cout << "Name: ";
                  std::getline(std::cin, name);
                  //std::cin >> name;
                  std::cout << "Department: ";
                  std::getline(std::cin, dept);
                  //std::cin >> dept;
                  std::cout << "Semester: ";
                  std::getline(std::cin, sem);
                  //std::cin >> sem;
                  std::cout << "Grade: ";
                  std::cin >> grade;
                  c = Course(name, dept, sem, grade);
                  updatedSt.addCourse(c);
                  break;
                case 2:
                  updatedSt.printCourses();
                  std::cout << "Enter the index of the course you would like to remove: ";
                  std::cin >> courseIndex;
                  c = updatedSt.getCourse(courseIndex);
                  updatedSt.removeCourse(c);
                  std::cout << "Course Removed!" << std::endl;
                  break;
                default:
                  break;
            }
            students.updateStudent(updatedSt);
            break;
          default:
            break;
          }
        }while(selection != -1);
        break;
      case 'D':
        students.displayDB();
        std::cout << "Enter the name of the Student you wish to remove: ";
        std::getline(std::cin, temp);
        s = students.getStudent(temp);
        students.deleteStudent(s);
        std::cout << s.getName() << " Removed!" << std::endl;
        break;
      case 'P':
        students.displayDB();
        break;
      default:
        break;
    }
  }while(choice != 'E');

  return 0;
}
