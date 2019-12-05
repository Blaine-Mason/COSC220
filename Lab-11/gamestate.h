#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<map>
#include <iostream>
#include <stack>

class GameState {
  protected:
    // Each subclass will be responsible for setting up a list
    // of things the user can do, along with the text prompt
    std::map<int, std::string> choices;

  public:
    virtual ~GameState(){};
    // TODO: each state should have a chance of
    // the user getting attacked
    double combatProbability;

    // prints all options available to the user in this state
    virtual void printOptions() = 0;

    // will take the input and handle it appropriately
    virtual void handleInput(int, std::stack<GameState*>&) = 0;
};

#endif
