#include "HanoiStack.h"
HanoiStack::HanoiStack(){
  top = nullptr;
}
HanoiStack::HanoiStack(int s){
  top = nullptr;
  for(int i = 0; i < s; i++){
    Disk* temp = new Disk;
    Disk* crsr;
    temp->size = i + 1;
    temp->next = nullptr;
    if(top == nullptr){
      top = temp;
      crsr = top;
    }else{
      crsr->next = temp;
      crsr = crsr->next;
    }
  }
}
HanoiStack& HanoiStack::operator+=(HanoiStack rhs){
  Disk* left = new Disk;
  Disk* right = new Disk;
  this->pop(*left);
  rhs.pop(*right);
  if(left->size  > right->size){
    rhs.push(right);
    this->push(left);
  }else{
    rhs.push(right);
    rhs.push(left);
  }
}
HanoiStack::~HanoiStack(){
  if(top == nullptr){
    delete top;
  }else{
    Disk* crsr = top;
    while(crsr){
      crsr = crsr->next;
      delete top;
      top = crsr;
    }
  }
}

void HanoiStack::push(Disk* d){
  if(top == nullptr){
    top = d;
    top->next = nullptr;
  }else if(d->size > top->size){
    std::cout << "A disk cannot be placed on top of a smaller one" << std::endl;
    return;
  }else{
    Disk* temp = new Disk;
    temp->size = d->size;
    temp->next = top;
    top = temp;
  }
}
void HanoiStack::pop(Disk& d){
  if(top == nullptr){
    std::cout << "Stack is Empty" << std::endl;
  }else{
    d.size = top->size;
    d.next = top->next;
    top = top->next;
  }
}
void HanoiStack::displayStack(){
  if(top == nullptr){
    for(int i = 0; i < 10; i++){
      std::cout << "           |          " << std::endl;
    }
      std::cout << "======================" << std::endl << std::endl;
  }else{
    Disk* crsr = top;
    while(crsr->next){
      crsr = crsr->next;
    }
    int size = crsr->size;
    crsr = top;
    for(int i = 0; i <= 10 - size; i++){
      std::cout << "           |          " << std::endl;
    }
    while(crsr){
      std::cout << "           " << crsr->size << "          " << std::endl;
      crsr = crsr->next;
    }
      std::cout << "======================" << std::endl << std::endl;

  }
}
