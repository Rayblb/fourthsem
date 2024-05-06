
#include "Character.h"
#include "Prey.h"
#include"Predator.h"

int main() {
	Character character (0,0);

	character.Move("Up");
	character.Move("Right");
	Prey Prey(0, 0);
	Prey.Move("Up");
	Prey.Move("Up");
	Predator predator(3, 3);
	predator.Move("Left");
	predator.Move("Left");

	return 0;
}