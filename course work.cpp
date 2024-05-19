#include "Character.h"
#include "Prey.h"
#include "Predator.h"
#include "Arena.h"

int main() {
    // Create instances of characters
    Prey prey(0, 0);
    Predator predator(3, 3);

    // Move characters
    prey.Move("Up");
    prey.Move("Up");
    predator.Move("Left");
    predator.Move("Left");

    // Create an instance of Arena
    Arena arena;

    // Start the game
    arena.startGame();

    // Check if the game is over
    if (arena.isGameOver()) {
        std::cout << "Game Over!" << std::endl;
    }

    return 0;
}