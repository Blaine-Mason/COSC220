#include "HanoiStack.h"
/*
* Constructor
*/
HanoiStack::HanoiStack(int s, bool first){
  top = nullptr;
  //If the first tower is being created
  if(first){
    //set the initsize
    initsize = s;
    //for the number of disks, create a disk and put it on the stack.
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
/*
* += Overload
* Functionality:
*     Pops the left and right hand side, compares the disks. If it is a valid move
*     then push th disks in place.  If not, push back on to original stacks.
*/
HanoiStack& HanoiStack::operator+=(HanoiStack& rhs){
  Disk left;
  Disk right;
  //pop both diskd
  this->pop(left);
  rhs.pop(right);
  //if the left stack is empty
  if(left.size == 0){
    //push the right disk on to it
    this->push(right);
    return *this;
  //if the right stack is empty
  }else if(right.size == 0){
    //push the left disk on to it
    rhs.push(left);
    return *this;
  }else{
    //if the disk is too big, place into original spots
    if(left.size  > right.size){
      rhs.push(right);
      this->push(left);
      return *this;
    }else{
      //perform the move
      rhs.push(right);
      rhs.push(left);
      return *this;
    }
  }
}
/*
* << Operator
*   Honestly just a copy of displayStack.
*/
std::ostream& operator<<(std::ostream &out, const HanoiStack& stack){
  int spacing = stack.initsize;
  //if it is an empty stack
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
    //Do some counting
    HanoiStack::DiskNode* crsr = stack.top;
    int count = 0;
    while(crsr->next){
      crsr = crsr->next;
      count++;
    }
    int size = crsr->d.size;
    //count holds the number of disks in the list
    count += 1;
    crsr = stack.top;
    //print the top of the stack if it isnt full
    for(int k = 0; k < stack.initsize - count; k++){
      for(int i = spacing; i >= 0; i--){
        out << " ";
      }
      out << "|" << std::endl;
    }
    //count is reset for the next iteration
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
/*
* Win Condition Checker
*/
void HanoiStack::winCondition(bool& win){
  if(this->top == nullptr){
    return;
  }
  DiskNode* crsr = this->top;
  //you win if one stack has all the disks on it, since its impossible to have all the disks
  //on one stack unless you have won.
  int winner = 0;
  while(crsr){
    winner++;
    crsr = crsr->next;
  }
  std::cout << winner << std::endl;
  if(winner == initsize){
    crsr = this->top;
    while(crsr){
      crsr = crsr->next;
      this->pop(top->d);
      top = crsr;
    }
    win = true;
  }else{
    win = false;
  }
}
/*
* Push
*/
void HanoiStack::push(Disk d){
  //Creates a disk and puts it on the top of the stack
  DiskNode* temp = new DiskNode;
  temp->d.size = d.size;
  temp->next = top;
  top = temp;
}
void HanoiStack::pop(Disk& d){
  //if the disk exists, then remove it from the "head" of the list
  if(top == nullptr){
    d.size = 0;
  }else{
    DiskNode* temp = top;
    d.size = top->d.size;
    top = top->next;
    delete temp;
  }
}
/*
* DisplayStack
*/
void HanoiStack::displayStack(){
  int spacing = initsize;
  //if it is an empty stack
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
    //Do some counting
    while(crsr->next){
      crsr = crsr->next;
      count++;
    }
    int size = crsr->d.size;
    //count holds the number of disks in the list
    count += 1;
    crsr = top;
    //print the top of the stack if it isnt full
    for(int k = 0; k < initsize - count; k++){
      for(int i = spacing; i >= 0; i--){
        std::cout << " ";
      }
      std::cout << "|" << std::endl;
    }
    //count is reset for the next iteration
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
