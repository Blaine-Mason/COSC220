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
    Disk* top;
  public:
    HanoiStack();
    HanoiStack(int);
    void push(Disk*);
    void pop(Disk&);
    void displayStack();

};
#endif
