
#include "Character.h"
#include "Prey.h"

int main() {
	Character character (0,0);

	character.Move("Up");
	character.Move("Right");
	Prey Prey(0, 0);
	Prey.Move("Up");
	Prey.Move("Up");




	return 0;
}