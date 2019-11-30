#include "combatstate.h"
combatstate::combatstate(){
  combatProbability = 0;
  choices[ATTACK_OPTION] = "Attack the enemy.";
  choices[FLEE_OPTION]   = "Try to run away.";
  choices[POWER_ATTACK_OPTION] = "Swing wildly.";
}