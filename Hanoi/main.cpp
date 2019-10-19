#include <iostream>
#include <string>
#include <stdio.h>
#include "HanoiStack.h"

int main(int argc, char** argv){

  HanoiStack s1(atoi(argv[1]));
  HanoiStack s2;
  HanoiStack s3;

  Disk d;
  s1.pop(d);
  Disk* dPtr = &d;
  s2.push(dPtr);



  s1.displayStack();
  std::cout << std::endl;
  s2.displayStack();
  std::cout << std::endl;
  s3.displayStack();


  return 0;
}
