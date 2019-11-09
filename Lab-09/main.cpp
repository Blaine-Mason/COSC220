#include <iostream>
#include "mystack.h"

int main(){
   MyStack<int> s;
   MyStack<std::string> s2;
   MyStack<int> s3(s);
   MyStack<int> s7;
   s7 = s;
   int temp = 0;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.pop(temp);
   s.push(50);
   int p = s.peek();
   std::cout << "Peek: " << p << std::endl;
   s.displayStack();
   s3.displayStack();
   s7.displayStack();


   s2.push("Egggs");
   s2.push("Bacon");
   s2.push("Cheese");
   s2.displayStack();
  return  0;
}
