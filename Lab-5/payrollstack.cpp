    #include "payrollstack.h"

PayRollStack::PayRollStack(){
  head = nullptr;
}

PayRollStack::~PayRollStack(){
  if(head == nullptr){
    return;
  }else{
    StackNode* crsr = head;
    while(crsr){
      crsr = crsr->next;
      delete head;
      head = crsr;
    }
  }
}
PayRollStack::PayRollStack(const PayRollStack& rhs){
  StackNode* crsr = rhs.head;
  head = nullptr;
  while(crsr->next  ){
    push(crsr->p);
    crsr = crsr->next;
  }
}
PayRollStack PayRollStack::operator=(const PayRollStack& rhs){
  StackNode* crsr = rhs.head;
  if(this == &rhs){
    cout << "They are Same" << endl;
  }else{
    while(crsr->next){
      push(crsr->p);
      crsr = crsr->next;
    }
    return *this;
  }
}

// Adds a PayRoll object into the stack
// -Dr.Anderson
void PayRollStack::push(PayRoll c){
  StackNode* nNode = new StackNode;
  StackNode* crsr = head;
  nNode->p = c;
  nNode->next = nullptr;
  if(crsr == nullptr){
    head = nNode;
    return;
  }else{
    while(crsr->next){
      crsr = crsr->next;
    }
    crsr->next = nNode;
    delete nNode;
  }
}

// Returns the payroll object that was most recently pushed
// -Dr.Anderson
PayRoll PayRollStack::pop(){
  StackNode* crsr = head;
  StackNode* prev = head;
  if(head == nullptr){
    PayRoll p;
    cout << "Stack is Empty" << endl;
    return p;
  }else{

    while(crsr->next){
      prev = crsr;
      crsr = crsr->next;
    }
    PayRoll temp = crsr->p;
    prev->next = nullptr;
    crsr = nullptr;
    return temp;
  }
}
// Alternative, but common, method:
// instead of using a return, take the destination container
// as a parameter to the pop function
// -Dr.Anderson
void PayRollStack::pop(PayRoll& rp){
  rp = pop();
}

// Returns the number of elements on the stack
// -Dr.Anderson
int PayRollStack::size(){
  int count = 0;
  if(head){
    return 1 + (-1);
  }else{
    StackNode* crsr = head;
    while(crsr){
      count++;
      crsr = crsr->next;
    }
    return count;
  }
}
