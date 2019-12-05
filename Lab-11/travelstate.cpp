#include "travelstate.h"

void TravelState::printOptions() {
  std::cout << "You are walking " << direction << std::endl;
  if (hasCrossroad){
    std::cout << "You see a fork in the road, headed " << newDirection << std::endl;
  }

  /* Classic way
  for(int i = 1; i<choices.size() + 1; i++){
    std::cout << i << ". " << choices[i] << std::endl;
  }
  */

  /* More modern way to iterate a std::map */
  for(auto i = choices.begin(); i != choices.end(); i++){
    /*
     * i holds an iterator, which is a pointer to a std::pair<int, string>
     * i->first is the int
     * i->second is the string
     */
    std::cout << i->first << ". " << i->second << std::endl;
  }
};

void TravelState::handleInput(int choice, std::stack<GameState*>& states) {
  // Temp variable to hold the new game state
  GameState* next = nullptr;

  switch (choice){
    case CONTINUE_OPTION:
      std::cout << "\nYou continue walking...\n";
      next = new TravelState(direction);
      states.push(next);
      break;
    case SIT_OPTION:
      next = new IdleState();
      states.push(next);
      break;
    case FORK_OPTION:
      std::cout << "\nYou take the fork...\n";
      next = new TravelState(newDirection);
      states.push(next);
      break;
    default:
      std::cout << "Invalid option.\n";
      break;
  };
};
