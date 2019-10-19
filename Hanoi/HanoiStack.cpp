#include "HanoiStack.h"
HanoiStack::HanoiStack(){
  head = nullptr;
}
HanoiStack::HanoiStack(int s){
  
}

void HanoiStack::push(Disk* d){
  Disk* crsr = head;
  d->next = nullptr;
  if(crsr == nullptr){
    head->prev = nullptr;
    head = d;
  }else{
    while(crsr->next != nullptr){
      crsr = crsr->next;
    }
    crsr->next = d;
    d->prev = crsr;
  }
  last = crsr;
}
void HanoiStack::pop(Disk& d){
  Disk* crsr = head;
  if(head == nullptr){
    std::cout << "Stack is Empty" << std::endl;
  }else{
    while(crsr->next){
      crsr = crsr->next;
    }
    d.size = crsr->size;
    d.next = crsr->next;
    crsr->prev = crsr->next;
  }
}
void HanoiStack::displayStack(){
  Disk* crsr = head;
  while(crsr->next){
    crsr = crsr->next;
  }
  while(crsr){
    std::cout << 5 << std::endl;
    crsr = crsr->prev;
  }

}
