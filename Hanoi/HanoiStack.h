
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
    //EC
    void winCondition(bool& win);
    HanoiStack& operator+=(HanoiStack& rhs);
    friend std::ostream& operator<<(std::ostream &out, const HanoiStack&);
    void push(Disk);
    void pop(Disk&);
    void displayStack();

};
#endif
