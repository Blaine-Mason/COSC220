#ifndef IDLESTATE_H
#define IDLESTATE_H

/*
 * TODO: For lab:
 * - implement the two override functions of GameState, printOptions and handleInput
 * - implement constructor to remember the status of the previous travel state
 */
#include <iostream>
#include <stdlib.h>
#include "gamestate.h"
#include "travelstate.h"

class IdleState : public GameState{
  private:
    enum Choices {
      CONTINUE_OPTION = 1,
      LEAVE_OPTION    = 2
    };
  public:
  	IdleState();


    void printOptions() override;

    void handleInput(int, std::stack<GameState*>&) override;
};

#endif
