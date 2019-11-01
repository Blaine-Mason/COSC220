#include <iostream>
#include <string>
#include <stdio.h>
#include "HanoiStack.h"

int main(int argc, char** argv){

  HanoiStack s1(atoi(argv[1]), true);
  HanoiStack s2(atoi(argv[1]), false);
  HanoiStack s3(atoi(argv[1]), false);
  bool win = false;
  s1.displayStack();
  s2.displayStack();
  s3.displayStack();
  do{
    Disk* d = new Disk;
    int from, to;
    std::cout << "Enter the Stack to remove from(1-2-3): " <<std::endl;
    std::cin >> from;
    std::cout << "Enter the Stack to move to(1-2-3): " <<std::endl;
    std::cin >> to;
    switch(from){
      case 1:
        switch(to){
          case 1:
            s1 += s1;
            break;
          case 2:
            s1 += s2;
            break;
          case 3:
            s1 += s3;
            break;
          default:
            win = true;
            break;
        }
        break;
      case 2:
        switch(to){
          case 1:
            s2 += s1;
            break;
          case 2:
            s2 += s2;
            break;
          case 3:
            s2 += s3;
            break;
          default:
            win = true;
            break;
        }
        break;
      case 3:
        switch(to){
          case 1:
            s3 += s1;
            break;
          case 2:
            s3 += s2;
            break;
          case 3:
            s3 += s3;
            break;
          default:
            win = true;
            break;
        }
        break;
      default:
        win = true;
        break;
    }
    system("clear");
    s1.displayStack();
    s2.displayStack();
    s3.displayStack();
  }while(!win);


  return 0;
}
