#include "monster.h"

Monster::Monster() : LivingEntity(150, 150, 5) {}
void Monster::printStats(){
	std::cout << "=================" << std::endl;
	std::cout << "Monster: Dragon" << std::endl;
	std::cout << "Health: " << hp_curr << " out of " << hp_max << std::endl;
	std::cout << "Dmg: " << dmg << std::endl;
	std::cout << "=================" << std::endl;
}