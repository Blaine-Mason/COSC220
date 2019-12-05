#ifndef TRAVELSTATE_H
#define TRAVELSTATE_H

#include "gamestate.h"
#include "idlestate.h"
#include <stdlib.h>
#include <time.h>
#include <list>

class TravelState : public GameState {
  private:
    // Current direction of travel
    std::string direction;

    // Denotes if there is a fork
    bool hasCrossroad;

    // The direction of the crossroad
    std::string newDirection;

    // Choice constants
    enum Choices{
      CONTINUE_OPTION = 1,
      SIT_OPTION      = 2,
      FORK_OPTION     = 3
    };

  public:
    TravelState(std::string dir){
      direction = dir;

      // Randomly add a fork in the road
      srand(time(0));
      if ( rand()%10 + 1 > 7 ){ // 30% chance of a turn
        hasCrossroad = true;
        std::list<std::string> dirs;
        dirs.push_front("North");
        dirs.push_front("South");
        dirs.push_front("East");
        dirs.push_front("West");

        // Remove the direction we're going
        dirs.remove(direction);

        // Selects a random direction that we're not already traveling
        newDirection = *std::next(dirs.begin(), rand()%dirs.size());
      } else {
        hasCrossroad = false;
      }
      
      // Set up the choice text for the user
      choices[CONTINUE_OPTION] = "Keep walking.";
      choices[SIT_OPTION] = "Sit and rest.";
      if (hasCrossroad){
        choices[FORK_OPTION] = "Take the " + newDirection + " fork.";
      }
    }

    void printOptions() override;

    void handleInput(int, std::stack<GameState*>&) override;

};

#endif
