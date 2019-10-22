#ifndef HANOISTACK_H
#define HANOISTACK_H

#include <iostream>
#include <string>

struct Disk{
  int size;
  Disk* next;
};

class HanoiStack{
  private:
    struct DiskNode{
      Disk d;
      int size;
    }
    Disk* top;
  public:
    HanoiStack();
    HanoiStack(int);
    ~HanoiStack();
    HanoiStack& operator+=(const HanoiStack rhs);
    void push(Disk*);
    void pop(Disk&);
    void displayStack();

};
#endif
