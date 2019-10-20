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
    ~HanoiStack();
    void push(Disk*);
    void pop(Disk&);
    void displayStack();

};
#endif
