#ifndef COMBATSTATE_H
#define COMBATSTATE_H

#include <iostream>
#include <stdlib.h>
#include "gamestate.h" // GameState

class CombatState : public GameState {
  private:
    int enemyHealth = 100;

    enum Choices {
      ATTACK_OPTION = '1',
      FLEE_OPTION   = '2'
    };
  public:
    CombatState();
    void printOptions() override;
    void handleInput(int, std::stack<GameState*>&) override;
};

#endif