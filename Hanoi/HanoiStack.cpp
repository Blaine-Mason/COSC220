#include "HanoiStack.h"
HanoiStack::HanoiStack(){
  head = nullptr;
}
HanoiStack::HanoiStack(int s){
  Disk* d = new Disk;
  d->size = s;
  s--;
  head = d;
  Disk* crsr = head;
  while(s > 0){
    Disk* tmp = new Disk;
    tmp->size = s;
    tmp->next = nullptr;
    crsr->next = tmp;
    crsr = crsr->next;
    s--;
  }
}

void HanoiStack::push(Disk* d){
  Disk* crsr = head;
  d->next = nullptr;
  if(crsr == nullptr){
    head = d;
  }else{
    while(crsr->next){
      crsr = crsr->next;
    }
    crsr->next = d;
  }
}
void HanoiStack::pop(Disk& d){
  Disk* crsr = head;
  Disk* prev = head;
  if(head == nullptr){
    std::cout << "Stack is Empty" << std::endl;
  }else{
    while(crsr->next){
      prev = crsr;
      crsr = crsr->next;
    }
    d.size = crsr->size;
    d.next = crsr->next;
    prev->next = crsr->next;
  }
}
void HanoiStack::displayStack(){
  Disk* crsr = head;
  while(crsr){
    std::cout << crsr->size << std::endl;
    crsr = crsr->next;
  }

}
