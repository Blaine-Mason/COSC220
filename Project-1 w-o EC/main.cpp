#include <iostream>
#include <string>
#include <stdio.h> //system("clear")
#include <unistd.h> //usleep
#include "course.h"
#include "student.h"
#include "studentdb.h"

int main(){
  std::cout << "Welcome to Student Database" << std::endl;
  char choice;
  StudentDB students;
  Student s;
  do{
    //Display Menu
    std::cout << "--------------------" << std::endl << "|C.) Create Student|" << std::endl <<  "--------------------" << std::endl;
    std::cout << "--------------------" << std::endl << "|U.) Update Student|" << std::endl <<  "--------------------" << std::endl;
    std::cout << "--------------------" << std::endl << "|D.) Delete Student|" << std::endl <<  "--------------------" << std::endl;
    std::cout << "--------------------" << std::endl << "|P.) Print Database|" << std::endl <<  "--------------------" << std::endl;
    std::cout << "--------------------" << std::endl << "|E.) Exit          |" << std::endl <<  "--------------------" << std::endl;
    std::cin >> choice;
    std::cin.ignore();
    system("clear");
    //Variable to hold temp information with Students and Course
    std::string temp;
    int iTemp, selection, courseIndex;
    std::string name, dept, sem, grade;
    char cTemp;
    Course c;
    Student updatedSt;

    switch(choice){
      //Create Student
      case 'C':
      //Get the information from the user about the student
        std::cout << "~CREATE STUDENT~" << std::endl;
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
        system("clear");
        do{
          //Add Courses until input is n
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
            system("clear");
          }
        }while(cTemp != 'n');
        //Add the student to the database
        students.createStudent(s);
        system("clear");
        break;
      case 'U':
      //Get the student to edit
        std::cout << "~UPDATE STUDENT~" << std::endl;
        std::cout << "Enter the name for the Student you would like to edit: " << std::endl;
        std::getline(std::cin, name);
        //Assign updated st to the Student gotten from the list
        updatedSt = students.getStudent(name);
        //If the student doesnt exist
        if(updatedSt.getName() == "Not Found"){
          break;
        }
        //Update info of the student
        do{
          std::cout << "Select what you would like to edit(-1 to finish): " << std::endl;
          std::cout << "1.)Date of Birth: " << updatedSt.getDoB() << std::endl;
          std::cout << "2.)Major: " << updatedSt.getMajor() << std::endl;
          std::cout << "3.)Courses: " << std::endl;
          updatedSt.printCourses();
          std::cin >> selection;
          std::cin.ignore();
          system("clear");
          /*
          *For each selection, updatedSt is changed accordingly
          */
          switch(selection){
            case 1:
              std::cout << "Enter the updated Date of Birth: ";
              std::getline(std::cin, temp);
              updatedSt.setDob(temp);
              std::cout << "DoB Updated!" << std::endl;
              usleep(1000000);
              system("clear");
              break;
            case 2:
              std::cout << "Enter the updated Major: ";
              std::getline(std::cin, temp);
              updatedSt.setMajor(temp);
              std::cout << "Major Updated!" << std::endl;
              usleep(1000000);
              system("clear");
              break;
            case 3:
              std::cout << "Would you like to (1)add or (2)remove a course: " << std::endl;
              std::cin >> iTemp;
              std::cin.ignore();
              switch(iTemp){
                //Adds a course
                case 1:
                  std::cout << "Name: ";
                  std::getline(std::cin, name);

                  std::cout << "Department: ";
                  std::getline(std::cin, dept);

                  std::cout << "Semester: ";
                  std::getline(std::cin, sem);

                  std::cout << "Grade: ";
                  std::cin >> grade;
                  c = Course(name, dept, sem, grade);
                  updatedSt.addCourse(c);
                  usleep(1000000);
                  system("clear");
                  break;
                //Removes a course index wise
                case 2:
                  updatedSt.printCourses();
                  std::cout << "Enter the index of the course you would like to remove(Counting from 0): ";
                  std::cin >> courseIndex;
                  c = updatedSt.getCourse(courseIndex);
                  if(c.getName() == "NoName"){
                    break;
                  }else{
                    updatedSt.removeCourse(c);
                    std::cout << "Course Removed!" << std::endl;
                    usleep(1000000);
                    system("clear");
                    break;
                  }
                default:
                  break;
            }
            //Pass updatedSt to updateStudent
            students.updateStudent(updatedSt);
            break;
          default:
            break;
          }
        }while(selection != -1);
        usleep(1000000);
        system("clear");
        break;
        //Delete student given the name
      case 'D':
        std::cout << "~DELETE STUDENT~" << std::endl;
        students.displayDB();
        std::cout << "Enter the name of the Student you wish to remove: ";
        std::getline(std::cin, temp);
        s = students.getStudent(temp);
        //Uses a default student to tell if the name exists
        if(s.getName() == "Not Found"){
          break;
        }
        students.deleteStudent(s);
        std::cout << s.getName() << " Removed!" << std::endl;
        usleep(1000000);
        system("clear");
        break;
      case 'P':
      //Test function, this ones on me
        char c;
        std::cout << "~STUDENT DATABASE~" << std::endl;
        students.displayDB();
        std::cout << "Enter C to continue: ";
        std::cin >> c;
        usleep(1000000);
        system("clear");
        break;
      default:
        break;
    }
  }while(choice != 'E');

  return 0;
}
