#include <iostream>
#include <string>
#include <stdio.h>
#include "HanoiStack.h"

int main(int argc, char** argv){

  HanoiStack s1(atoi(argv[1]));
  HanoiStack s2;
  HanoiStack s3;
  bool win = false;
  s1.displayStack();
  s2.displayStack();
  s3.displayStack();
  do{
    int from, to;
    std::cout << "Enter the Stack to remove from(1-2-3): " <<std::endl;
    std::cin >> from;
    Disk* d = new Disk;
    switch(from){
      case 1:
        s1.pop(*d);
        break;
      case 2:
        s2.pop(*d);
        break;
      case 3:
        s3.pop(*d);
        break;
      default:
        break;
    }
    std::cout << "Enter the Stack to move to(1-2-3): " <<std::endl;
    std::cin >> to;
    switch(to){
      case 1:
        s1.push(d);
        break;
      case 2:
        s2.push(d);
        break;
      case 3:
        s3.push(d);
        break;
      default:
        break;
    }
    system("clear");
    s1.displayStack();
    s2.displayStack();
    s3.displayStack();


  }while(!win);


  return 0;
}
