#include <iostream>
#include "mystack.h"
#include "payroll.h"

int main(){
   MyStack<int> s;
   MyStack<std::string> s2;
   MyStack<int> s7;
   int temp = 0;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.pop(temp);
   s.push(50);
   int p = s.peek();
   std::cout << "Peek: " << p << std::endl;
   MyStack<int> s3(s);
   s7 = s;
   s.displayStack();
   s3.displayStack();
   s7.displayStack();


   s2.push("Egggs");
   s2.push("Bacon");
   s2.push("Cheese");
   s2.displayStack();




   MyStack<PayRoll> pStack;
   PayRoll p1("Blaine", 8.00, 40);
   PayRoll p2("Not Blaine", 10.30, 23);
   PayRoll p3("Luke", 7.50, 20);
   PayRoll p4;
   pStack.push(p1);
   pStack.push(p2);
   pStack.push(p3);
   pStack.displayStack();
   pStack.pop(p4);
   pStack.displayStack();
  return  0;
}
