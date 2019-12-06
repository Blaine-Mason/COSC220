#ifndef COMBATSTATE_H
#define COMBATSTATE_H

#include <iostream>
#include <stdlib.h>
#include "gamestate.h" // GameState
#include "livingentity.h"
#include "monster.h"

class CombatState : public GameState {
  private:
    Monster mon;
    enum Choices {
      ATTACK_OPTION = '1',
      FLEE_OPTION   = '2'
    };
  public:
    CombatState();
    void printOptions() override;
    void handleInput(int, std::stack<GameState*>&, Player&) override;
};

#endif