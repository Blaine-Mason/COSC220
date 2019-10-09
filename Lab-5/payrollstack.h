#ifndef PAYROLLSTACK_H
#define PAYROLLSTACK_H
#include <iostream>
#include "payroll.h"

using namespace std;

class PayRollStack{
  private:
    struct StackNode {
      PayRoll p;
      StackNode* next;
    };
    StackNode* head;
  public:
    PayRollStack();

    ~PayRollStack();
    PayRollStack (const PayRollStack&);
    PayRollStack operator=(const PayRollStack&);

    // Adds a PayRoll object into the stack
    // -Dr.Anderson
    void push(PayRoll p);

    // Returns the payroll object that was most recently pushed
    // -Dr.Anderson
    PayRoll pop();

    // Alternative, but common, method:
    // instead of using a return, take the destination container
    // as a parameter to the pop function
    // -Dr.Anderson
    void pop(PayRoll&);

    // Returns the number of elements on the stack
    // -Dr.Anderson
    int size();
};
#endif
