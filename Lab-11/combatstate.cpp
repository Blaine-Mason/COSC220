#include "combatstate.h"

CombatState::CombatState(){
      combatProbability = 0;
      choices[ATTACK_OPTION] = "Attack the enemy.";
      choices[FLEE_OPTION]   = "Try to run away.";
      //choices[POWER_ATTACK_OPTION] = "Swing wildly.";
 }

void CombatState::printOptions(){
	std::cout << "The enemy prepares to attack!" << std::endl;
	std::cout << "1.) Attack the enemy." << std::endl;
	std::cout << "2.) Try to run away." << std::endl;
}
void CombatState::handleInput(int choice, std::stack<GameState*>& states, Player& p){
	GameState* tmpState = nullptr;

	switch(choice){
		case 1:
			std::cout << "You attack the enemy..." << std::endl;
			if(rand()%100 + 1 > 50){
				std::cout << "Oh No the monster attacks you!" << std::endl;
				p.hp_curr -= mon.dmg;
				p.printStats();
				mon.printStats();
			}else{
				mon.hp_curr -= p.dmg;
				p.printStats();
				mon.printStats();
			}
			if(mon.hp_curr <= 0){
				std::cout << "The enemy is dead!" << std::endl;
				tmpState = states.top();
				states.pop();
				delete tmpState;
				return;
			}
			break;
		case 2:
			std::cout << "You attempt to flee from the fight..." << std::endl;
			if(rand()%100 + 1 > 50){
				std::cout << "You successfully retreat from battle." << std::endl;
				p.printStats();	
				tmpState = states.top();
				states.pop();
				delete tmpState;
			}else{
				p.hp_curr -= mon.dmg;
				p.printStats();
				mon.printStats();
				std::cout << "You could not escape and the enemy attacks you!" << std::endl;
				p.hp_curr -= mon.dmg;
			}
			break;
		default:
			break;

	};
}