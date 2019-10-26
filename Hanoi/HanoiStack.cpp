#include "HanoiStack.h"
HanoiStack::HanoiStack(){
  top = nullptr;
}
HanoiStack::HanoiStack(int s){
  top = nullptr;
  for(int i = 0; i < s; i++){
    Disk temp;
    temp.size = i + 1;
    DiskNode* nNode = new DiskNode; 
    nNode->d = temp;
    nNode->next = nullptr;
    DiskNode* crsr;
    if(top == nullptr){
      top = nNode;
      crsr = top;
    }else{
      crsr->next = nNode;
      crsr = crsr->next;
    }
  }
}
HanoiStack& HanoiStack::operator+=(HanoiStack rhs){
  Disk* left = new Disk;
  Disk* right = new Disk;
  left->size = 0;
  right->size = 0;
  this->pop(*left);
  rhs.pop(*right);
  if(left->size == 0){
    this->push(right);
    delete left;
  }else if(right->size == 0){
    rhs.push(left);
    delete right;
  }else{
    std::cout << "Popped" << std::endl;
    if(left->size  > right->size){
      rhs.push(right);
      this->push(left);
    }else{
      std::cout << "Yes Yes" << std::endl;
      rhs.push(right);
      rhs.push(left);
      std::cout << "Pushed Pushed" << std::endl;
    }
  }
}
HanoiStack::~HanoiStack(){
  if(top != nullptr){
    DiskNode* crsr = top;
    while(crsr){
      crsr = crsr->next;
      delete top;
      top = crsr;
    }
  }
}

void HanoiStack::push(Disk* d){
  if(top == nullptr){
    top->d = *d;
    top->next = nullptr;
  }else if(d->size > top->d.size){
    std::cout << "A disk cannot be placed on top of a smaller one" << std::endl;
    return;
  }else{
    DiskNode* temp = new DiskNode;
    temp->d.size = d->size;
    temp->next = top;
    top = temp;
  }
}
void HanoiStack::pop(Disk& d){
  if(top == nullptr){
    d.size = 0;
    std::cout << "Stack is Empty" << std::endl;
  }else{
    DiskNode* temp = top;
    d.size = top->d.size;
    top = top->next;
    delete temp;
  }
}
void HanoiStack::displayStack(){
  if(top == nullptr){
    for(int i = 0; i < 10; i++){
      std::cout << "           |          " << std::endl;
    }
      std::cout << "======================" << std::endl << std::endl;
  }else{
    DiskNode* crsr = top;
    while(crsr->next){
      crsr = crsr->next;
    }
    int size = crsr->d.size;
    crsr = top;
    for(int i = 0; i <= 10 - size; i++){
      std::cout << "           |          " << std::endl;
    }
    while(crsr){
      std::cout << "           " << crsr->d.size << "          " << std::endl;
      crsr = crsr->next;
    }
      std::cout << "======================" << std::endl << std::endl;

  }
}
