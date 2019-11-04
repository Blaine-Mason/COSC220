#include <iostream>
#include <string>
#include <stdio.h>
#include "HanoiStack.h"
/*
* SolveHanoi
* -Dr. Anderson
*/
void SolveHanoi(int n, int start, int end, int tmp){
 if( n >= 1 ){
   SolveHanoi(n-1, start, tmp, end);
   printf("Move disc %d from %d to %d.\n",
       n, start, end);
   SolveHanoi(n-1, tmp, end, start);
 }
}
int main(int argc, char** argv){
  //Create the Stacks
  HanoiStack s1(atoi(argv[1]), true);
  HanoiStack s2(atoi(argv[1]), false);
  HanoiStack s3(atoi(argv[1]), false);
  //Bools to hold the win condition and solution variables
  bool win = false, solution1 = false, solution2 = false;
  //users name
  std::string name;
  //moves made
  int moves = 0;


  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "                    Towers of Hanoi              " << std::endl;
  std::cout << std::endl;
  std::cout << "Objective: Move an entire stack of disks from one\npeg to a different peg. " << std::endl << std::endl;
  std::cout << "Rules of the Game:" << std::endl;
  std::cout << "1.) You can only move one disk at a time." << std::endl;
  std::cout << "2.) No disk can be placed on top of the other." << std::endl << std::endl;
  std::cout << "If you get stuck, enter in '30' for the stack to\nbe moved from and '30' for the stack to be moved to." << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Eneter your first name to begin:";
  std::cin >> name;
  //system("clear");

  //display stacks
  std::cout << s1;
  std::cout << s2;
  std::cout << s3;
  do{
    //Hold the to and fro values
    int from, to;
    std::cout << "Enter the Stack to remove from(1-2-3): " <<std::endl;
    std::cin >> from;
    std::cout << "Enter the Stack to move to(1-2-3): " <<std::endl;
    std::cin >> to;
    switch(from){
      //if moving from 1 to 2 or 3
      case 1:
        switch(to){
          case 1:
            std::cout << "Can't move to the stack its being taken from" << std::endl;
            break;
          case 2:
            s1 += s2;
            break;
          case 3:
            s1 += s3;
            break;
          default:
            std::cout << "There are only 3 stacks!(Hint 30-30)" << std::endl;
            break;
        }
        break;
      //if moving from 2 to 1 or 3
      case 2:
        switch(to){
          case 1:
            s2 += s1;
            break;
          case 2:
            std::cout << "Can't move to the stack its being taken from" << std::endl;
            break;
          case 3:
            s2 += s3;
            break;
          default:
            std::cout << "There are only 3 stacks!(Hint 30-30)" << std::endl;
            break;
        }
        break;
      //if moving from 3 to 1 or 2
      case 3:
        switch(to){
          case 1:
            s3 += s1;
            break;
          case 2:
            s3 += s2;
            break;
          case 3:
            std::cout << "Can't move to the stack its being taken from" << std::endl;
            break;
          default:
            std::cout << "There are only 3 stacks!(Hint 30-30)" << std::endl;
            break;
        }
        break;
      //If they don't know the solution
      case 30:
        solution1 = true;
        switch(to){
          case 30:
            solution2 = true;
            break;
          default:
            std::cout << "There are only 3 stacks!(Hint 30-30)" << std::endl;
            break;
        }
        break;
      default:
        std::cout << "There are only 3 stacks!(Hint 30-30)" << std::endl;
        break;
    }

    //system("clear");

    if(solution1 && solution2){
      std::cout << "Solution Starting at 1, ending at 2, using 3: " << std::endl;
      SolveHanoi(atoi(argv[1]), 1, 2, 3);
      std::cout << "Solution Starting at 1, ending at 3, using 2: " << std::endl;
      SolveHanoi(atoi(argv[1]), 1, 3, 2);
      std::cout << s1;
      std::cout << s2;
      std::cout << s3;
    }else{
      std::cout << s1;
      std::cout << s2;
      std::cout << s3;
    }
    //increment moves
    moves++;
    s2.winCondition(win);
    s3.winCondition(win);
    if(win){
      std::cout << "Congrats " << name << " you solved Hanoi in " << moves - 1 << " moves!" << std::endl;
    }
  }while(!win);


  return 0;
}
