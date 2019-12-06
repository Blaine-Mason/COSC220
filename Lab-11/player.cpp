#include "player.h"

Player::Player() : LivingEntity(100, 100, 10){}
Player::~Player(){}
void Player::printStats(){
	std::cout << "=================" << std::endl;
	std::cout << "Player: John" << std::endl;
	std::cout << "Health: " << hp_curr << " out of " << hp_max << std::endl;
	std::cout << "Dmg: " << dmg << std::endl;
	std::cout << "=================" << std::endl;
}