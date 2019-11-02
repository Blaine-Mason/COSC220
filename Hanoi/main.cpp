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
    std::cout << s1;
    std::cout << s2;
    std::cout << s3;
    //s1.displayStack();
    //s2.displayStack();
    //s3.displayStack();
    s2.winCondition(win);
    s3.winCondition(win);
  }while(!win);


  return 0;
}
