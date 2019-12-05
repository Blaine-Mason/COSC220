#include "idlestate.h"

IdleState::IdleState(){
	choices[CONTINUE_OPTION] = "Keep sitting.";
	choices[LEAVE_OPTION] = "Get up and keep walking.";
}

void IdleState::printOptions(){
	std::cout << "You are sitting at the side of the road\n" << std::endl;
	std::cout << "1.) " << choices[CONTINUE_OPTION] << std::endl;
	std::cout << "2.) " << choices[LEAVE_OPTION] << std::endl;
}
void IdleState::handleInput(int choice, std::stack<GameState*>& states){
	GameState* next = nullptr;
	GameState* old = nullptr;

	switch(choice){
		case CONTINUE_OPTION:
			old = states.top();
			states.pop();
			delete old;
			next = new IdleState();
			states.push(next);
			break;
		case LEAVE_OPTION:
			old = states.top();
			states.pop();
			delete old;
			break;
		default:
			break;

	}
}