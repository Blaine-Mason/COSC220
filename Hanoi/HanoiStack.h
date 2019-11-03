
#ifndef HANOISTACK_H
#define HANOISTACK_H

#include <iostream>
#include <string>

//Disk to be held by a DiskNode
struct Disk{
  int size;
};

class HanoiStack{
  private:
    //DiskNodes to construct the list.
    struct DiskNode{
      Disk d;
      DiskNode* next;
    };
    DiskNode* top;
    //Holds the initial values of the list
    int initsize;
  public:
    //Constructor
    HanoiStack(int, bool);
    //Destructor
    ~HanoiStack();
    //EC
    void winCondition(bool& win);
    //Operator += overload
    HanoiStack& operator+=(HanoiStack& rhs);
    //Operator << overload
    friend std::ostream& operator<<(std::ostream &out, const HanoiStack&);
    //Push
    void push(Disk);
    //Pop
    void pop(Disk&);
    //Display
    void displayStack();

};
#endif
