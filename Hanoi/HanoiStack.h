#ifndef HANOISTACK_H
#define HANOISTACK_H

#include <iostream>
#include <string>

class HanoiStack{
  private:
    struct Disk{
      int size;
      Disk* next;
    };
    Disk* head;
  public:
    HanoiStack(int);
    void push(Disk*);
    void pop(Disk&);
    void displayStack();

};
#endif
