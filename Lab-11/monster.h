#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include "livingentity.h"

class Monster : public LivingEntity {
  public:
  	Monster();
  	virtual ~Monster(){};
  	void printStats();
    
};

#endif