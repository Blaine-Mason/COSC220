#include<iostream>
#include "gamestate.h"
#include "travelstate.h"
#include "combatstate.h"
#include "livingentity.h"
#include "player.h"

/*
 * Main function contains the main game loop.
 * Until the user exits or the program forces an
 * exit, we:
 *
 * 1. Get the list of current options from the 
 *    current GameState object
 * 2. Get the user input
 * 3. Pass that input to the current state to be
 *    handled. A GameState pointer (possibly of
 *    an entirely new object) is returned.
 *
 * Current bug: due to the reassignment of the
 * currentState variable, the old currentState
 * will be leaked! Need to fix this so after
 * playing for a long time, the program doesn't
 * run out of memory!
 */

int main(){
  int input, combatRoll;
  std::stack<GameState*> stateStack;


  // GameState is an abstract base class,
  // so currentState will have to actually
  // point to one of its subclasses
  Player pc;
  GameState* currentState = nullptr;
  CombatState* cs = nullptr;;

  // Start the user off in a travel state, headed north
  TravelState* t = new TravelState("North");
  stateStack.push(t);

  while(true){
    currentState = stateStack.top();

    if (currentState->combatProbability > 0){
      combatRoll = rand() % 100 + 1;
      if (combatRoll < currentState->combatProbability){
        std::cout << "You get attacked" << std::endl;
        cs = new CombatState();
        stateStack.push(cs);
        currentState = cs;
      }
    }
    // 1. Get options from the state
    currentState->printOptions();

    // 2. Get user input
    std::cin >> input;

    // 3. Pass input to the state, and get the new state
    currentState->handleInput(input, stateStack, pc);
  }
}
