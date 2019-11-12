#include <iostream>
#include "mystack.h"
#include "payroll.h"

int main(){
   MyStack<int> intStack;
   MyStack<std::string> stringStack;
   MyStack<PayRoll> pStack;

   //Int Test
   int temp = 0;
   std::cout << "Pushing: 10, 20, 30" << std::endl << std::endl;
   intStack.push(10);
   intStack.push(20);
   intStack.push(30);
   intStack.displayStack();
   std::cout << "Popping: 30" << std::endl << std::endl;
   intStack.pop(temp);
   intStack.displayStack();
   std::cout << "Copying and Assigning..." << std::endl;
   MyStack<int> intCopy(intStack);
   MyStack<int> intAss;
   intAss = intStack;
   std::cout << "Copy Constructor and Assignment Operator Output:" << std::endl << std::endl;
   std::cout << "Copy Constructor" << std::endl;
   intCopy.displayStack();
   std::cout << "Assignment Operator" << std::endl;
   intAss.displayStack();
   std::cout << "Popping: 20" << std::endl << std::endl;
   intStack.pop(temp);
   intStack.displayStack();
   int p = intStack.peek();
   std::cout << "Peek: " << p << std::endl << std::endl;
   std::cout << "Final Stack" << std::endl;
   intStack.displayStack();
   std::cout << std::endl;

   //String Test
   std::string str = "";
   std::cout << "Pushing: 'Eggs', 'Bacon', 'Cheese' " << std::endl << std::endl;
   stringStack.push("Eggs");
   stringStack.push("Bacon");
   stringStack.push("Cheese");
   stringStack.displayStack();
   std::cout << "Popping: 'Cheese'" << std::endl;
   stringStack.pop(str);
   stringStack.displayStack();
   std::cout << "Copying and Assigning..." << std::endl;
   MyStack<std::string> strCopy(stringStack);
   MyStack<std::string> strAss;
   strAss = stringStack;
   std::cout << "Copy Constructor and Assignment Operator Output:" << std::endl << std::endl;
   std::cout << "Copy Constructor" << std::endl;
   strCopy.displayStack();
   std::cout << "Assignment Operator" << std::endl;
   strAss.displayStack();
   std::cout << "Popping: 'Bacon'" << std::endl << std::endl;
   stringStack.pop(str);
   stringStack.displayStack();
   str = stringStack.peek();
   std::cout << "Peek: " << str << std::endl << std::endl;
   std::cout << "Final Stack" << std::endl;
   stringStack.displayStack();
   std::cout << std::endl;

   //PayRoll Test
   PayRoll p1("Blaine", 8.00, 40);
   PayRoll p2("Not Blaine", 10.30, 23);
   PayRoll p3("Luke", 7.50, 20);
   PayRoll tempP;
   std::cout << "Pushing: 'Blaine', 'Not Blaine', 'Luke' " << std::endl << std::endl;
   pStack.push(p1);
   pStack.push(p2);
   pStack.push(p3);
   pStack.displayStack();
   std::cout << "Popping: Luke" << std::endl;
   pStack.pop(tempP);
   std::cout << "Copying and Assigning..." << std::endl;
   MyStack<PayRoll> strPayRoll(pStack);
   MyStack<PayRoll> pAss;
   pAss = pStack;
   std::cout << "Copy Constructor and Assignment Operator Output:" << std::endl << std::endl;
   std::cout << "Copy Constructor" << std::endl;
   strPayRoll.displayStack();
   std::cout << "Assignment Operator" << std::endl;
   pAss.displayStack();
   std::cout << "Popping: Not Blaine" << std::endl;
   pStack.pop(tempP);
   pStack.displayStack();
   PayRoll peek;
   peek = pStack.peek();
   std::cout << "Peek: " << std::endl << peek << std::endl;
   std::cout << "Final Stack" << std::endl;
   pStack.displayStack();


  return  0;
}
