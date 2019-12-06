#include "livingentity.h"

LivingEntity::LivingEntity(){
    hp_max = 100;
    hp_curr = 100;
    dmg = 5;
}
LivingEntity::LivingEntity(int hm, int h, int d){
    hp_max = hm;
    hp_curr = h;
    dmg = d;
}
bool LivingEntity::isDead(){
	return hp_curr <= 0;
}