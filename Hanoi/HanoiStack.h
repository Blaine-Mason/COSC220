
#ifndef HANOISTACK_H
#define HANOISTACK_H

#include <iostream>
#include <string>

struct Disk{
  int size;
};

class HanoiStack{
  private:
    struct DiskNode{
      Disk d;
      DiskNode* next;
    };
    DiskNode* top;
    int initsize;
  public:
    HanoiStack();
    HanoiStack(int, bool);
    ~HanoiStack();
    HanoiStack& operator+=(HanoiStack& rhs);
    void push(Disk);
    void pop(Disk&);
    void displayStack();

};
#endif
