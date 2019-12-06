#ifndef LIVINGENTITY_H
#define LIVINGENTITY_H

#include <iostream>

class LivingEntity {
  protected:
  public:
    int hp_max;
    int hp_curr;
    int dmg;

    LivingEntity(){
        hp_max = 100;
        hp_curr = 100;
        dmg = 5;
    }
    LivingEntity(int hm, int h, int d){
        hp_max = hm;
        hp_curr = h;
        dmg = d;
    }
    virtual ~LivingEntity(){};
    virtual void printStats() = 0;
    bool isDead();
    
};

#endif
