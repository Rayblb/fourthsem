#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Arena.h"

int main() {
    srand(static_cast<unsigned>(time(0)));

    int size = 10;
    Prey prey(0, 0);
    Predator predator(9, 9);

    int difficulty;
    std::cout << "Choose the game difficulty (1 = easy, 2 = medium, 3 = hard): ";
    std::cin >> difficulty;

    if (difficulty < 1 || difficulty > 3) {
        std::cout << "Invalid difficulty. Exiting game." << std::endl;
        return 1;
    }

    Arena arena(size, prey, predator, 7, difficulty);

    std::string choice;
    std::cout << "Choose your side (1 = prey, 2 = predator): ";
    std::cin >> choice;

    if (choice == "1") {
        // Player controls prey, predator moves towards prey
        while (!arena.isGameOver()) {
            arena.printArena();
            int direction;
            std::cout << "Enter direction for prey (1: up, 2: upright, 3: upleft, 4: down, 5: downright, 6: downleft, 7: left, 8: right): ";
            std::cin >> direction;
            arena.movePrey(direction);
            arena.movePredator();
        }
    }
    else if (choice == "2") {
        // Player controls predator, prey moves randomly
        while (!arena.isGameOver()) {
            arena.printArena();
            int direction;
            std::cout << "Enter direction for predator (1: up, 2: down, 3: left, 4: right): ";
            std::cin >> direction;
            arena.movePredator(direction);
            arena.movePrey();
        }
    }
    else {
        std::cout << "Invalid choice. Exiting game." << std::endl;
        return 1;
    }

    arena.playGame();
    std::cout << "Game Over!" << std::endl;

    return 0;
}
