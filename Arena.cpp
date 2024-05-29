#include "Arena.h"
#include <iostream>
#include <vector>

Arena::Arena(int size, Prey prey, Predator predator, int maxSteps, int difficulty, std::string playerSide)
    : size(size), prey(prey), predator(predator), steps(0), maxSteps(maxSteps), playerSide(playerSide) {

    if (playerSide == "1") { // Player controls prey
        switch (difficulty) {
        case 1: this->predatorMoveDistance = 1; break;
        case 2: this->predatorMoveDistance = 2; break;
        case 3: this->predatorMoveDistance = 3; break;
        default: this->predatorMoveDistance = 1; break;
        }
    }
    else if (playerSide == "2") { // Player controls predator
        switch (difficulty) {
        case 1: this->predatorMoveDistance = 3; break;
        case 2: this->predatorMoveDistance = 2; break;
        case 3: this->predatorMoveDistance = 1; break;
        default: this->predatorMoveDistance = 1; break;
        }
    }
}

void Arena::printArena() {
    std::vector<std::vector<char>> grid(size, std::vector<char>(size, '.'));
    Point2D preyPos = prey.getPosition();
    Point2D predatorPos = predator.getPosition();

    grid[preyPos.y][preyPos.x] = 'P';
    grid[predatorPos.y][predatorPos.x] = 'X';

    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

void Arena::playGame() {
    if (prey.getPosition().equals(predator.getPosition())) {
        std::cout << "Predator wins!" << std::endl;
    }
    else if (steps >= maxSteps) {
        std::cout << "Prey wins!" << std::endl;
    }
}

void Arena::movePrey(int direction) {
    prey.move(direction, size);
    steps++;
}

void Arena::movePredator(int direction) {
    predator.move(direction, predatorMoveDistance, size);
    steps++;
}

void Arena::movePrey() {
    prey.moveRandomly(size);
    steps++;
}

void Arena::movePredator() {
    predator.moveToPrey(prey, predatorMoveDistance, size);
    steps++;
}

bool Arena::isGameOver() {
    return prey.getPosition().equals(predator.getPosition()) || steps >= maxSteps;
}
