#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "livingentity.h"

class Player : public LivingEntity {
  public:
  	Player();
  	virtual ~Player();
  	virtual void printStats();
};

#endif
