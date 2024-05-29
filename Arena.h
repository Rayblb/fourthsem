#ifndef ARENA_H
#define ARENA_H

#include "Prey.h"
#include "Predator.h"
#include <string>

class Arena {
public:
    Arena(int size, Prey prey, Predator predator, int maxSteps, int difficulty, std::string playerSide);

    void printArena();
    void playGame();
    void movePrey(int direction);
    void movePredator(int direction);
    void movePrey();
    void movePredator();
    bool isGameOver();

private:
    int size;
    Prey prey;
    Predator predator;
    int steps;
    int maxSteps;
    int predatorMoveDistance;
    std::string playerSide;
};

#endif // ARENA_H
