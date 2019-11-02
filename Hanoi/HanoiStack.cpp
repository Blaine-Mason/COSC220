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
std::ostream& operator<<(std::ostream &out, const HanoiStack& stack){
  int spacing = stack.initsize;
  if(stack.top == nullptr){
    for(int k = 0; k <= stack.initsize - 1; k++){
      for(int i = spacing; i >= 0; i--){
        out << " ";
      }
      out << "|";
      for(int i = spacing; i >= 0; i--){
        out << " ";
      }
      out << std::endl;
    }
    for(int j = 0; j <= (stack.initsize*2) + 2; j++){
      out << "=";
    }
    out << std::endl;
  }else{
    HanoiStack::DiskNode* crsr = stack.top;
    int count = 0;
    while(crsr->next){
      crsr = crsr->next;
      count++;
    }
    int size = crsr->d.size;
    count += 1;
    crsr = stack.top;
    for(int k = 0; k < stack.initsize - count; k++){
      for(int i = spacing; i >= 0; i--){
        out << " ";
      }
      out << "|" << std::endl;
    }
    count = 0;
    while(crsr){
      if(crsr->d.size != 0){
        for(int i = spacing; i >= 0; i--){
          out << " ";
        }
        out << crsr->d.size << std::endl;
      }
        crsr = crsr->next;

    }
    for(int j = 0; j <= (stack.initsize*2) + 2; j++){
      out << "=";
    }
    out << std::endl;
  }
  return out;
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
void HanoiStack::winCondition(bool& win){
  if(this->top == nullptr){
    return;
  }
  DiskNode* crsr = this->top;
  int winner = 0;
  while(crsr){
    winner++;
    crsr = crsr->next;
  }
  std::cout << winner << std::endl;
  if(winner == initsize){
    win = true;
  }else{
    win = false;
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
  int spacing = initsize;
  if(top == nullptr){
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
  }else{
    DiskNode* crsr = top;
    int count = 0;
    while(crsr->next){
      crsr = crsr->next;
      count++;
    }
    int size = crsr->d.size;
    count += 1;
    crsr = top;
    for(int k = 0; k < initsize - count; k++){
      for(int i = spacing; i >= 0; i--){
        std::cout << " ";
      }
      std::cout << "|" << std::endl;
    }
    count = 0;
    while(crsr){
      if(crsr->d.size != 0){
        for(int i = spacing; i >= 0; i--){
          std::cout << " ";
        }
        std::cout << crsr->d.size << std::endl;
      }
        crsr = crsr->next;

    }
    for(int j = 0; j <= (initsize*2) + 2; j++){
      std::cout << "=";
    }
    std::cout << std::endl;
  }
}
