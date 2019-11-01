#include "HanoiStack.h"
HanoiStack::HanoiStack(){
  top = nullptr;
}
HanoiStack::HanoiStack(int s, bool first){
  top = nullptr;
  if(first){
    initsize = s;
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
  }else{
    initsize = s;
  }
}
HanoiStack& HanoiStack::operator+=(HanoiStack& rhs){
  Disk left;
  Disk right;
  this->pop(left);
  rhs.pop(right);
  if(left.size == 0){
    this->push(right);
    return *this;
  }else if(right.size == 0){
    rhs.push(left);
    return *this;
  }else{
    if(left.size  > right.size){
      rhs.push(right);
      this->push(left);
      return *this;
    }else{
      rhs.push(right);
      rhs.push(left);
      return *this;
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

void HanoiStack::push(Disk d){
  DiskNode* temp = new DiskNode;
  temp->d.size = d.size;
  temp->next = top;
  top = temp;
}
void HanoiStack::pop(Disk& d){
  if(top == nullptr){
    std::cout << "Stack is Empty" << std::endl;
  }else{
    DiskNode* temp = top;
    d.size = top->d.size;
    top = top->next;
    delete temp;
  }
}
void HanoiStack::displayStack(){
  int spacing;
  std::cout << std::endl;
  if(top != nullptr){
    DiskNode* crsr = top;
    while(crsr->next){
      crsr = crsr->next;
    }
    crsr = top;
    spacing = initsize;
    while(crsr){
      for(int i = spacing; i > 0; i--){
        std::cout << " ";
      }
      for(int i = 0; i < (crsr->d.size); i++){
        std::cout << "#";
      }
      std::cout << "|";
      for(int i = 0; i < (crsr->d.size); i++){
        std::cout << "#";
      }
      std::cout << std::endl;
      crsr = crsr->next;
      spacing--;
    }
    for(int j = 0; j <= (initsize*2) + 2; j++){
      std::cout << "=";
    }
    std::cout << std::endl;
  }else{
    spacing = initsize;
    for(int k = 0; k <= initsize - 1; k++){
      for(int i = spacing; i >= 0; i--){
        std::cout << " ";
      }
      std::cout << "|";
      for(int i = spacing; i >= 0; i--){
        std::cout << " ";
      }
      std::cout << std::endl;
    }
    for(int j = 0; j <= (initsize*2) + 2; j++){
      std::cout << "=";
    }
    std::cout << std::endl;
  }
}
